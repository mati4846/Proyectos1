
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

str load2(const char* s){
	str r = (str)malloc(strlen(s)+1);
	strcpy(r, s);
	return r;
}
	
void print_string(str s){
	printf("%s", s);
}
	
int equals_string(str a, str b){
	return strcmp(a, b);  // 0 si son iguales
}
	
void concat_string(str a, str b){
	strcat(a, b);
}
