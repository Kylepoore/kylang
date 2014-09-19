#ifndef PRINT_H
#define PRINT_H

#include "symbol.h"

int type_to_string(Type *type, char *str);

void print_type(Type *type);

int value_to_string(Value *value, char *str);

void print_value(Value *value);

int symbol_to_string(Symbol *var, char *str);

void print_symbol(Symbol *var);


#endif
