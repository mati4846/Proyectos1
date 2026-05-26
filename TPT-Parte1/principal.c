#include <stdio.h>

#include "String.h"
#include "TAD_TData.h"

int main() {
	/* //STRING pruebas
	str s, c;
	s = load2("hola mundo");
	print_string(s);
	c = load2("hola mundo 2");
	print_string(c);
	printf("\n");
	printf("%d", equals_string(s, c));
	printf("\n");
	concat_string(s, load2(" 2"));
	printf(" %d", equals_string(s, c));
	*/
	/*
	Tdata A=NULL;
	Tdata s1 = create_str_ast();
	s1->string = load2("hola");
	insert_set(&A, s1);
	
	Tdata s2 = create_str_ast();
	s2->string = load2("mundo");
	insert_set(&A, s2);
	
	Tdata s3 = create_str_ast();
	s3->string = load2("2026");
	insert_set(&A, s3);
	
	Tdata s4=NULL;
	Tdata s41 = create_str_ast();
	s41->string = load2("10110");
	insert_set(&s4, s41);
	insert_set(&A, s4);
	printSet(A);
	*/
	
	Tdata A = NULL;
	Tdata B = NULL;
	
	Tdata l = NULL;
	
	//A = {"hola", "mundo"}
	Tdata s1 = create_str_ast();
	s1->string = load2("hola");
	
	Tdata s2 = create_str_ast();
	s2->string = load2("mundo");
	
	insert_set(&A, s1);
	insert_set(&A, s2);
	
	append_list(&l, s1);    
	
	// B = {"palabra", {A}}
	Tdata s3 = create_str_ast();
	s3->string = load2("palabra");
	insert_set(&A, s3);
	insert_set(&B, s3);
	insert_set(&B, A);   // 
	
	printf(" A = ");
	printSet(A);
	
	printf("\n B = ");
	printSet(B);
	
	printf("\n");
	
	//añadido
	printf(" l = ");
	append_list(&l, A);	//agrega
	append_list(&l, B);
	printList(l);
	printf("\n ");
	printTdata(s1);
	printf("\n Cantidad en la lista: %d ", length(l));
	printf("\n");	//concatenacion
	Tdata lPrueba=NULL;
	append_list(&lPrueba, A);
	concat(&l, lPrueba);//concat(&l, lPrueba);//concat(&lPrueba, l);
	printf(" Concatenacion: ");
	printTdata(l); append_list(&l, s3);
	Tdata s4 = create_str_ast(); s4->string = load2("bdsmdfr");
	printf("\n Busqueda en la lista: %d", search(l, s3) );
	Tdata l2 = NULL; append_list(&l2, s3);
	printf("\n Iguales list: %d", equals_list(l, l2));
	printf("\n Iguales SET: %d", equals_set(A, B));
	printf("\n Pertenece al SET: %d", belongs(A, s1));
	//remove_set(&A, s3);  printf("\nRemueve del SET: ");  printTdata(A);
	Tdata s5 = create_set(); insert_set(&s5, A);
	printf("\n s5 : "); printTdata(s5);
	printf("\n Contiene a el SET ");  printTdata(B); printf(" - ");  printTdata(s5); 
	printf(" - %d", subset(B, s5));
	printf("\n Union : ");
	printTdata(union_set(A, B));
	printf("\n Interseccion : ");
	printTdata(intersection_set(A, B));
	printf("\n Diferencia : ");
	printTdata(difference_set(A, B));
	return 0;
}

