#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

#include "../include/app.h"
#include "../include/common.h"

int execute(struct args_t *args) {
  printf("Args Help: %d", args->help);

  return STATUS_SUCCESS;
}