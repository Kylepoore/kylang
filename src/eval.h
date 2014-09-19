#ifndef EVAL_H
#define EVAL_H

#include "includes.h"
#include "symbol.h"

typedef enum{
  BRACES,
  PARENTHESES,
  SQ_BRACKETS,
  NG_BRACKETS
} EnclosureType;

typedef struct{
  int in_string;
  int depth[4];
  EnclosureType last_enc_type;
  int error;
} ParseState;



Value * eval(InputLine *input);

void eval_string(char *str);

void run(FILE *fp);


#endif
