#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/common.h"
#include "../include/parse.h"
#include "../include/app.h"

void print_usage(char *argv[]) {
  printf("Usage: %s\n", argv[0]);
  printf("\t -h - print usage\n");
  // printf("\t -n - create new database file\n");
  // printf("\t -a - add employee to the database\n");
  // printf("\t -v - validate database file header\n");
  // printf("\t -D - delete database file\n");
  // printf("\t -l - list database files\n");
  // printf("\t -p - docs pending\n");
  // printf("\t -d - enable debug logging\n");
  // printf("\t -m - test minheap logic\n");

  return;
}

int main(int argc, char **argv) {
  int retVal = 0;
  struct args_t *args = malloc(sizeof(struct args_t));
  
  if (parse_args(argc, argv, args) == STATUS_ERROR) {
    print_usage(argv);
    retVal = 0;
    goto free_args;
  }

  if (args->help) {
    print_usage(argv);
    goto free_args;
  }

  if (execute(args) == STATUS_ERROR) {
    printf("ERROR...\n");
    print_usage(argv);
    goto free_args;
  }

free_args:
  free(args);
  args = NULL;

  return retVal;
}