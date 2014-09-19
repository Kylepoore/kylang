#include "print.h"
#include <stdio.h>
#include "symbol.h"
#include "includes.h"

int type_to_string(Type *type, char *str){
  vprintf(NONE,"type to string\n");

  return 0;
}

void print_type(Type *type){
  vprintf(NONE,"print type\n");
}

int value_to_string(Value *value, char *str){
  vprintf(NONE,"value to string\n");
  return 0;
}

void print_value(Value *value){
  vprintf(NONE,"print value\n");
}

int symbol_to_string(Symbol *var, char *str){
  vprintf(NONE,"symbol to string\n");
  return 0;
}

void print_symbol(Symbol *var){
  vprintf(NONE,"print symbol\n");
}
