/*
 * gcc -o example `xml2-config --cflags` example.c `xml2-config --libs`
 */

#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

static void print_element(xmlNode * node) {
  printf("Node name: %s\n", node->name);
  if (xmlChildElementCount(node) == 0) {
    printf("  value: %s\n", xmlNodeGetContent(node));
  }
}

static void print_node(xmlNode *node) {
  xmlNode *current_node = NULL;

  for (current_node = node; current_node; current_node = current_node->next) {
    if (current_node->type == XML_ELEMENT_NODE) {
      print_element(current_node);
      print_node(current_node->children);
    }
  }
}

void run_query(const char * query, xmlDocPtr document) {
  xmlXPathInit();
  xmlXPathContextPtr ctxt;
  xmlXPathObjectPtr xpathRes;
  xmlNodePtr node;

  if (NULL == (ctxt = xmlXPathNewContext(document))) {
    printf("Can't parse document\n");
    return;
  }

  if (NULL == (xpathRes = xmlXPathEvalExpression(BAD_CAST query, ctxt))) {
    printf("Invalid XPath expression\n");
    return;
  }

  if (XPATH_NODESET == xpathRes->type) {
    for (int i = 0; i < xpathRes->nodesetval->nodeNr; i++) {
      node = xpathRes->nodesetval->nodeTab[i];
      if (node->type == XML_ELEMENT_NODE) {
        print_node(node->children);
      }
    }
  }

  xmlXPathFreeObject(xpathRes);
  xmlXPathFreeContext(ctxt);
}

int main(int argc, char **argv) {

  LIBXML_TEST_VERSION;

  xmlXPathInit();

  xmlDocPtr document;

  document = xmlParseFile(argv[1]);

  run_query(argv[2], document);
  
  xmlFreeDoc(document);
  
  return EXIT_SUCCESS;
}

