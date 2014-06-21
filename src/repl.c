#include "includes.h"

int repl(char *prompt){
  if(prompt == NULL){
    prompt = DEFAULT_PRIMARY_PROMPT;
  }
  //load stuff
  vprintf("loading stuff...\n");


  //start REPLing
  InputLine *input;
  Value *result;
  while(1){
    input = get_input_line(stdin);
    result = eval(input);
    print(result);
  }
}
