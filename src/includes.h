#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "eval.h"
#include "print.h"
#include "symbol.h"

typedef enum {
  HIGH,
  MED,
  LOW,
  NONE
} Priority;

#define vprintf(priority, format, ...) do {        \
  if (verbosity > priority)                          \
    fprintf(stderr, format, ##__VA_ARGS__);        \
} while(0)

#define eprintf(format, ...) do {                  \
  if (!quiet)                                      \
    fprintf(stderr, format, ##__VA_ARGS__);        \
} while(0)

int quit();

extern int verbosity;
extern int quiet;
#endif
