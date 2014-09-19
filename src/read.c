#include "includes.h"


InputLine * get_input_line(FILE *fp){
  InputLine *input, *current;
  input = malloc(sizeof(InputLine));
  int done = 0;
  char *ret = 0;
  current = input;
  int char_count = 0;
  
  while(!done){
    current->next = NULL;
    ret = fgets(current->value, LINE_SEGMENT_LENGTH - 1, fp);
    if(ret == NULL){
      eprintf("eof or error\n");
      current->length = strlen(current->value);
      done = 1;
    }else{
      current->length = strlen(current->value);
      if(current->value[current->length - 1] == '\n'){
        current->value[current->length - 1] = 0;
        done = 1;
      }else{
        current->next = malloc(sizeof(InputLine));
        current = current->next;
      }
    }
  }
  
  return input;
}





