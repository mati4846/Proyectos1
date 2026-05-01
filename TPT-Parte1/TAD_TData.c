
#include "TAD_TData.h"
#include "String.h"
#include <stdio.h>
#include <stdlib.h>

Tdata clone(Tdata n){
	if(n == NULL) return NULL;
	
	Tdata nuevo = NULL;
	
	if(n->nodeType == STR){
		nuevo = create_str_ast();
		nuevo->string = load2(n->string);
	}
	
	else if(n->nodeType == SET || n->nodeType == LIST){
		nuevo = (n->nodeType == SET) ? create_set() : create_list();
		
		Tdata aux = n;
		Tdata head = NULL;
		Tdata tail = NULL;
		
		while(aux != NULL){
			Tdata nodo_lista = create_set();  // nodo contenedor
			
			nodo_lista->data = clone(aux->data);
			nodo_lista->next = NULL;
			
			if(head == NULL){
				head = nodo_lista;
				tail = nodo_lista;
			} else {
				tail->next = nodo_lista;
				tail = nodo_lista;
			}
			
			aux = aux->next;
		}
		
		return head;
	}
	
	return nuevo;
}

//Creacion de Str, List y Set
Tdata create_str_ast(){
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = STR;
	n->string = NULL;
	return n;
}

Tdata create_set(){
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = SET;
	n->data = NULL;
	n->next = NULL;
	return n;
}
	
Tdata create_list(){
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = LIST;
	n->data = NULL;
	n->next = NULL;
	return n;
}

//Operaciones sobre List (listas)
void append_list(Tdata* list, Tdata datos){
	Tdata nuevo = create_list();
	
	nuevo->data = clone(datos);
	nuevo->next = NULL;
	
	if( (*list)==NULL ){
		(*list) = nuevo;
	} else {
		Tdata aux = *list;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = nuevo;
	}
}
int length(Tdata list){ //solo para lista
	if(list==NULL || list->nodeType!=LIST){
		printf("\nError. LIST invalido...\n");
		return -1;
	} else {
		int cont=0;
		while(list!=NULL){
			if(list->data!=NULL) cont++;
			list = list->next;
		}
		return cont;
	}
}
Tdata copy_list(Tdata list){
	if(list!=NULL && list->nodeType==LIST) return clone(list);
	else return NULL;
}
void concat(Tdata* l1, Tdata l2){
	if( l2!=NULL && l2->nodeType==LIST && l2->data!=NULL){
		if( (*l1)!=NULL && (*l1)->nodeType==LIST ){
			Tdata aux = (*l1);
			if( (*l1)->data==NULL){
				(*l1) = l2;
				free(aux);
			} else {
				while(aux->next!=NULL){
					aux=aux->next;
				}
				aux->next = l2; //llamar a la funcion clone(l2);??
			}
		} else {
			(*l1) = l2;
		}
	}
}
int search(Tdata list, Tdata elem){
	if(list==NULL || list->nodeType!=LIST){
		printf("\nError. LIST invalido...\n");
		return -1;
	}
	int bus=0;
	while(bus==0 && list!=NULL){
		if( elem->nodeType==STR && list->data->nodeType==STR && equals_string(list->data->string, elem->string)==0 ){
			bus=1;
		}
		if( elem->nodeType==SET && list->data->nodeType==SET && equals_set(list->data, elem) ){
			bus=1;
		}
		if( elem->nodeType==LIST && list->data->nodeType==LIST ){
			bus=1;
		}
		list = list->next;
	}
	return bus; // 1 si lo encuentra
}

//Operaciones sobre Set (conjuntos)
void insert_set(Tdata* set, Tdata datos){
	Tdata nuevo = create_set();
	
	nuevo->data = clone(datos);
	nuevo->next = NULL;
	
	if( (*set)==NULL ){
		(*set) = nuevo;
	} else {
		Tdata aux = *set;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = nuevo;
	}
}
int belongs(Tdata set, Tdata elem){
	if( set==NULL || elem==NULL || set->nodeType!=SET ){
		printf("\nError. SET invalido...\n");
		return -1;
	}
	int bus=0;
	while(bus==0 && set!=NULL){
		if( elem->nodeType==STR && set->data->nodeType==STR && equals_string(set->data->string, elem->string)==0 ){
			bus=1;
		}
		if( elem->nodeType==SET && set->data->nodeType==SET && equals_set(set->data, elem) ){
			bus=1;
		}
		if( elem->nodeType==LIST && set->data->nodeType==LIST ){
			bus=1;
		}
		set = set->next;
	}
	return bus; // 1 si lo encuentra
}
void remove_set(Tdata* set, Tdata elem){
	if( (*set)==NULL || (*set)->nodeType!=SET ){
		printf("\nError. SET invalido...\n");
	} else {
		Tdata* act = set;
		while( *act!=NULL && equals_string((*act)->data->string, elem)!=0 ){
			act = &((*act)->next);
		}
		if( act!=NULL ){
			//si lo encuentra ...
			
		}
	}
}

//Operaciones algebraicas (SET)
Tdata union_set(Tdata A, Tdata B){
	return NULL;
}
Tdata intersection_set(Tdata A, Tdata B){
	return NULL;
}
Tdata difference_set(Tdata A, Tdata B){
	return NULL;
}
int subset(Tdata A, Tdata B){
	return 0;
}
int equals_set(Tdata A, Tdata B){
	if( (A==NULL || B==NULL) || (A->nodeType!=SET || B->nodeType!=SET) ){
		printf("\nError. SET invalido...\n");
		return -1;
	}
	int equal=0;
	while(equal==0 && A!=NULL && B!=NULL){
		if( A->data->nodeType==B->data->nodeType ){
			switch(A->data->nodeType){
			case LIST:
				equal = 1;
				break;
			case SET:
				equal = equals_set(A->data, B->data);
				break;
			case STR:
				equal = equals_string(A->data->string, B->data->string);
			}
			A = A->next; B = B->next;
		} else {
			equal=1;
		}
	}
	return equal;  // 0 si son iguales
}

//prints
void printTdata(Tdata A){
	switch(A->nodeType){
	case LIST:
		printList(A);
		break;
	case SET:
		printSet(A);
		break;
	case STR:
		print_string(A->string);
	}
}

void printSet(Tdata A){
	if(A==NULL || A->nodeType!=SET){
		printf("\nError. SET invalido...\n");
	} else {
		Tdata aux = A;
		printf("{ ");
		while(aux!=NULL){
			switch(aux->data->nodeType){
			case LIST:
				printList(aux->data);
				break;
			case SET:
				printSet(aux->data);
				break;
			case STR:
				print_string(aux->data->string);
			}
			aux = aux->next;
			if(aux!=NULL) printf(", ");
		}
		printf(" }");
	}
}
void printList(Tdata A){
	if(A==NULL || A->nodeType!=LIST){
		printf("\nError. LIST invalido...\n");
	} else {
		Tdata aux = A;
		printf("[ ");
		while(aux!=NULL){
			switch(aux->data->nodeType){
			case LIST:
				printList(aux->data);
				break;
			case SET:
				printSet(aux->data);
				break;
			case STR:
				print_string(aux->data->string);
			}
			aux = aux->next;
			if(aux!=NULL) printf(", ");
		}
		printf(" ]");
	}
}

