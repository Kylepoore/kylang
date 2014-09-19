#include "includes.h"
#include "repl.h"

int repl(char *prompt){
  if(prompt == NULL){
    prompt = DEFAULT_PRIMARY_PROMPT;
  }
  //load stuff
  vprintf(LOW,"loading stuff...\n");


  //start REPLing
  InputLine *input;
  Value *result;
  while(1){
  //read
    vprintf(NONE,"get input line\n");
    input = get_input_line(stdin);
  //eval
    vprintf(NONE,"evaluate\n");
    result = eval(input);
  //print
    vprintf(NONE,"print\n");
    print_value(result);
  //loop
  }
}
