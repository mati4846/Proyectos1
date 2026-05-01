#ifndef STRING_H
#define STRING_H

typedef char* str;

str load2(const char*);
void print_string(str);
int equals_string(str, str);
void concat_string(str, str);

#endif
