#ifndef READ_H
#define READ_H

#define  LINE_SEGMENT_LENGTH 256

typedef struct InputLine {
  int length;
  int ateof;
  char value[LINE_SEGMENT_LENGTH];
  struct InputLine *next;
} InputLine;

InputLine * get_input_line(FILE *fp);




#endif
