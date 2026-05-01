#ifndef TAD_AST_H
#define TAD_AST_H

#include "String.h"
#define STR 1
#define SET 2
#define LIST 3

struct dataType{
	int nodeType;   /* STR, SET, LIST */
	union{
		str string;
		struct{
			struct dataType* data;
			struct dataType* next;
		};
	};
};
typedef struct dataType* Tdata;

//Creacion de Str, List y Set
Tdata create_str_ast();
Tdata create_list();
Tdata create_set();

//Operaciones sobre List (listas)
void append_list(Tdata*, Tdata);				//Añadir elemento
int length(Tdata);						//Tamaño de lista
Tdata copy_list(Tdata);					//Copiar lista
void concat(Tdata*, Tdata);				//concatenar listas
int search(Tdata, Tdata);				//Buscar elemento en lista
int equals_list(Tdata A, Tdata B);

//Operaciones sobre Set (conjuntos)
void insert_set(Tdata*, Tdata);			//Agrega elemento al conjunto
int belongs(Tdata, Tdata);				//Pertenece al conjunto
void remove_set(Tdata*, Tdata);			//Remueve elemento del conjunto
//Operaciones algebraicas
Tdata union_set(Tdata, Tdata);
Tdata intersection_set(Tdata, Tdata);
Tdata difference_set(Tdata, Tdata);
int subset(Tdata, Tdata);
int equals_set(Tdata, Tdata);

//print
void printTdata(Tdata);				//Agregado
void printSet(Tdata);
void printList(Tdata);

#endif
