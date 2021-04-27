#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define EOS '\0' // End of string

int getLine(char line[]);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  
  max = 0;
  
  while ((len = getLine(line)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  
  
  if (max > 0) {
    printf("Longest line:\n  %s\n", longest);
  }
  
  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char *line)
{
  int c, i;
  
  for (i=0; i < (MAXLINE - 1) && (c=getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  
  line[i] = EOS;
  
  return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char *to, char *from)
{
  int i = 0;
  
  while ((to[i] = from[i]) != EOS) {
    ++i;
  }
}

