#include "eval.h"
#include "symbol.h"
#include "includes.h"

Value * eval(InputLine *input){
  if(input->ateof){
    quit();
  }
  Value *val = malloc(sizeof(Value));
  return val;

}

void eval_string(char *str){
  
}

void run(FILE *fp){

}
