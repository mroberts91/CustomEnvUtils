#include <ctype.h>
#include <string.h>

#include "../include/common.h"

char *ltrim(char *s) {
  if (s == NULL) {
    return NULL;
  }

  while (isspace(*s))
    s++;
  return s;
}

char *rtrim(char *s) {
  if (s == NULL) {
    return NULL;
  }

  char *back = s + strlen(s);
  while (isspace(*--back))
    ;
  *(back + 1) = '\0';
  return s;
}

char *trim(char *s) {
  if (s == NULL) {
    return NULL;
  }

  return rtrim(ltrim(s));
}