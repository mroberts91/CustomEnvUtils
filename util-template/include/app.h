#ifndef APP_H
#define APP_H

struct args_t {
  char *filepath;
  bool help;
  bool list;
  bool create;
};

int execute(struct args_t *args);

#endif