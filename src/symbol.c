#include "includes.h"

#define HASHTABLE_INIT_SIZE 1117
#define GROWTH_FACTOR 1.5
#define ODDIFY(A) ((A)|1)

int table_size;
int table_capacity;
TableEntry **table;
TableEntry *entry_list_head;

void free_structure(Structure *structure);

Type *malloc_type(){
  vprintf(NONE,"allocating type...\n");
  return malloc(sizeof(Type));
}

void free_type(Type *type){
  vprintf(NONE,"freeing type...\n");
  if(type == NULL) return;
  if(type->next == NULL){
    free_structure(type->structure);
    type->structure = NULL;
    free(type);
    type = NULL;
    return;
  }
  free_type(type->next);
  free(type);
  type = NULL;
}

Structure *malloc_structure(){
  vprintf(NONE,"allocating structure...\n");
  return malloc(sizeof(Structure));
}

void free_structure(Structure *structure){
  vprintf(NONE,"freeing structure...\n");
  if(structure == NULL) return;
  if(structure->type != NULL){
    free_type(structure->type);
    structure->type = NULL;
  }
  if(structure->next != NULL){
    free_structure(structure->next);
    Structure->next = NULL;
  }
  free(structure);
  return;
}

Value *malloc_value(){
  vprintf(NONE,"allocating value...\n");
  return malloc(sizeof(Value));
}

void free_value(Value *value){
  vprintf(NONE,"freeing value...\n");
  if(value == NULL) return;
  free_type(value->type);
  free(value->val);
  free(value);
}

Symbol *malloc_symbol(){
  vprintf(LOW,"allocating symbol...\n");
  return malloc(sizeof(Symbol));
}

void free_symbol(Symbol *sym){
  vprintf(LOW,"freeing symbol %s...\n",sym->name);
  if(sym == NULL) return;
  if(sym->value != NULL){
    free_value(sym->val);
  }
  free(sym);
}

TableEntry *malloc_table_entry(){
  vprintf(NONE,"allocating table entry...\n");
  return malloc(sizeof(TableEntry));
}

void free_table_entry(TableEntry *table_entry){
  vprintf(NONE,"freeing table entry...\n");
  if(table_entry == NULL) return;
  if(table_entry->symbol != NULL){
    free_symbol(table_entry->symbol);
  }
  free(table_entry);
}

TableEntry **malloc_hashtable(){
  vprintf(LOW,"initializing symbol table...\n");
  return malloc(HASHTABLE_INIT_SIZE * sizeof(TableEntry*));
}

int grow_hashtable(TableEntry ***tbl, int size){
  size = ODDIFY((int)(GROWTH_FACTOR * size));
  vprintf(LOW,"growing hashtable to size: %d...\n",size);
  free(*tbl);
  *tbl = malloc(size * sizeof(TableEntry));
  return size;
}

void free_entry_list(TableEntry *tbl){
  TableEntry *next;
  for(tbl;tbl != NULL; tbl = next){
    next = tbl->next;
    free(tbl);
  }
}

void free_hashtable(TableEntry **tbl){
  vprintf(LOW,"freeing symbol table...\n");
  free(tbl);
  free_entry_list(entry_list);
}

unsigned long hash_symbol(Symbol symbol){
  vprintf(LOW,"hashing symbol %s...\n",symbol->name);
  unsigned long index = 0;
  unsigned long offset = 37;
  int length = strlen(symbol->name);
  int i = 0;
  for(i=0;i<length;i++){
    index += symbol->name[i] * offset;
    offset *= 37;
  }
  return index;
}

void init_symbol_table(){
  table_capacity = HASHTABLE_INIT_SIZE;
  table_size = 0;
  table = malloc_hashtable();
}

int same_type(Type *typea, Type *typeb){
  if(typea->modifier == typeb->modifier){
    if(typea->modifies != NULL && typeb->modifies != NULL){
      if(!same_type(typea->modifies,typeb->modifies)){
        return 0;
      }
    }
    Structure *currenta = typea->structure;
    Structure *currentb = typeb->structure;
    for(currenta,currentb;currenta!=NULL && currentb!=NULL;currenta=currenta->next,currentb=currentb->next){
      if(!same_type(currenta->type,currentb->type)){
        return 0;
      }
    }
    if(currenta==currentb){
      return 1;
    }else{
      return 0;
    }
  }else{
    return 0;
  }
}

int add_table_entry(TableEntry *entry){
  int index;
  if(entry->index == ~0){
    entry->index = hash_symbol(entry->symbol);
  }
  index = entry->index % table_capacity;

  TableEntry *current, **previous = &table[index];
  if(table[index] == NULL){
    table[index] = entry;
    table[index]->next = NULL;
  }else{
    for(current = table[index];current->next != NULL;current = current->next){
      if(!strncompare(current->symbol->name,entry->symbol->name)){
        if(same_type(current->symbol->type,entry->symbol->type)){
          entry->next = current->next;
          free_table_entry(current);
          *previous = entry;
        }else{
          return 0;
        }
      }
      previous = &current;
    }
    current->next = entry;
    entry->next = NULL;
    table_size++;
  }
  return 1;
}

void rehash_symbol_table(){
  table_capacity = grow_hashtable(&table,table_capacity);
  TableEntry current;
  for(current = entry_list_head; current != NULL; current = current->next){
    add_entry(current);
  }
}

int add_symbol(Symbol *symbol){
  TableEntry *entry = malloc_table_entry();
  entry->symbol = symbol;
  entry->index = ~0;
  if(symbol->val == NULL){
    entry->symbol_type = RESERVED_WORD;
  }else{
    entry->symbol_type = VARIABLE;
  }
  return add_table_entry(entry);
}

Symbol* make_symbol(char *name, Value *value){
  Symbol *symbol = malloc_symbol();
  strncpy(symbol->name,name,SYMBOL_NAME_LENGTH);
  symbol->val = value;
  return symbol;
}

Value* make_value(Type *type, char *val){
  Value *value = malloc_value();
  value->type = type;
  value->val = malloc(strlen(val));
  strcpy(value->val,val);
  return value;
}



int exists_symbol(char *name);

Type *get_variable_type(char *name);

Symbol *get_symbol(char *name);

int set_symbol(char *name, Value *value);

int unset_symbol(char *name);
