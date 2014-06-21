#ifndef PRINT_H
#define PRINT_H

int type_to_string(Type type, char *str);

void print_type(Type type);

int value_to_string(Value value, char *str);

void print_value(Value value);

int variable_to_string(Variable var, char *str);

void print_variable(Variable var);


#endif
