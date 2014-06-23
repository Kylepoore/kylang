#ifndef SYMBOL_H
#define SYMBOL_H

#define SYMBOL_NAME_LENGTH 64
#define SYMBOL_TYPE_LENGTH 256

typedef enum {
  RESERVED_WORD,
  VARIABLE
} SymbolType;

typedef enum {
  INT,
  FLOAT,
  CHAR,
  ARRAY,
  TUPLE,
  FUNCTION,
  TYPE,
  PATTERN,
  CONSTANT,
  MODIFIER
} Modifier;

static const char **MODIFIER_NAMES = {
  "INT",
  "FLOAT",
  "CHAR",
  "ARRAY",
  "TUPLE",
  "FUNCTION",
  "TYPE",
  "PATTERN",
  "CONSTANT",
  "MODIFIER"
};

struct Structure;

typedef struct Type {
  Modifier modifier;
  struct Type *modifies;
  struct Structure *structure;
} Type;

typedef struct Structure {
  struct *Type
  struct Structure *next
} Structure;

typedef struct Value {
  Type *type;
  char *val;
}

typedef struct Symbol {
  char name[SYMBOL_NAME_LENGTH];
  Value *val;
} Symbol;

typedef struct TableEntry {
  SymbolType symbol_type;
  Symbol *symbol;
  unsigned long index;
  TableEntry *lprev;
  TableEntry *lnext;
  TableEntry *cprev;
  TableEntry *cnext;
} TableEntry;

int exists_symbol(char *name);

Type *get_symbol_type(char *name);

Symbol *get_symbol(char *name);

int set_symbol(char *name, Value *value);

int unset_symbol(char *name);





#endif
