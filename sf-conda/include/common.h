#ifndef COMMON_H
#define COMMON_H
#include <ctype.h>
#include <string.h>

typedef enum {
  STATUS_ERROR = -1,
  STATUS_SUCCESS = 0,
} status_t;

char *ltrim(char *s);
char *rtrim(char *s);
char *trim(char *s);

#endif