#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

#include "../include/parse.h"
#include "../include/common.h"

status_t parse_args(int argc, char **argv, struct args_t *args) {
  int c;

  args->filepath = NULL;
  args->list = false;
  args->create = false;
  args->help = false;

  while ((c = getopt(argc, argv, "flch")) != -1) {
    switch (c) {
      case 'f':
        args->filepath = optarg;
        break;
      case 'l':
        args->list = true;
        break;
      case 'c':
        args->create = true;
        break;
      case 'h':
        args->help = true;
        break;
      case '?':
        printf("Unknown option -%c\n", c);
        break;
      default:
        return STATUS_ERROR;
        break;
    }
  }

  if (args->filepath == NULL && !args->help) {
    printf("File path is a required argument...\n");
    return STATUS_ERROR;
  }

  return STATUS_SUCCESS;
}