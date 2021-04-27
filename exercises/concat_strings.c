#include <stdio.h>
#include <string.h>

void jStrcat(char *destination, const char *base, const char *suffix);

void jStrcat(char *destination, const char *base, const char *suffix) {
  while((*destination++ = *base++))
    ;

  --destination;  // Move back to remove the copy '\0' from the end of base

  while((*destination++ = *suffix++))
    ;
}

int main(int argc, char *argv[]) {
  size_t length_base = strlen(argv[1]);
  size_t length_suffix = strlen(argv[2]);
  size_t length_result = length_base + length_suffix + 1;

  char result[length_result];

  jStrcat(result, argv[1], argv[2]);

  printf("Result:\n\t%s\n", result);
  
  return 0;
}

