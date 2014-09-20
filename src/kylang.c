#include "includes.h"
#include "repl.h"
#include <stdlib.h>
#include <unistd.h>

#define OPTION_STRING "v:qf:e:"

int verbosity;
int quiet;

int main(int argc, char **argv){
  char c;
  FILE *fp = stdin;
  
  char *prompt = NULL;
  char *eval_arg = NULL;
  char *filename = NULL;
  int file_mode;
  int eval_arg_mode;
  int interactive;

  verbosity = 1;
  quiet = 0;
  interactive = 1;
  file_mode = 0;
  eval_arg_mode = 0;
  
  while((c = getopt(argc,argv,OPTION_STRING)) != -1){
    switch(c){
      case 'v':
        //verbose mode
        verbosity = atoi(optarg);
        break;
      case 'q':
        //quiet mode
        quiet = 1;
        break;
      case 'f':
        //take input from file
        interactive = 0;
        file_mode = 1;
        filename = optarg;
        fp = fopen(filename, "r");
        break;
      case 'e':
        //take argument as input
        eval_arg = optarg;
        eval_arg_mode = 1;
        interactive = 0;
        break;
      case 'p':
        //set prompt string
        prompt = optarg;
        break;
      default:
        fprintf(stderr,"Usage: %s [-q | -v] [-f <file name>] [-e <eval string>]\n",argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  
  if(interactive){
    vprintf(NONE,"entering interactive mode...\n");
    int err = repl(prompt);
    if(err){
      exit(EXIT_FAILURE);
    }else{
      exit(EXIT_SUCCESS);
    }
  }else if(file_mode){
    vprintf(NONE,"running file: %s...\n", filename);
    run(fp);
    exit(EXIT_SUCCESS);
  }else if(eval_arg_mode){
    vprintf(NONE,"evaluating: %s...\n", eval_arg);
    eval_string(eval_arg);
    exit(EXIT_SUCCESS);
  }

  eprintf("something went wrong...\n");
  exit(EXIT_FAILURE);

  return 1;
}


int quit(){
  vprintf(LOW,"Goodbye!\n");
  exit(EXIT_SUCCESS);
  return(0);
}

