#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
-Author: Matteo Lamberti
-Target:
    Write a script that reverse an integer taken from input using stacks.
*/

struct El{
    int valore;
    struct El* next;
}El;

int is_empty(struct El* head){ //function that check if the queue is empty
    if (head == NULL) return 1;
    else return 0;
}

void push(struct El** pila, struct El* element){ //function that add data to a stack
	if (&pila==NULL){
		*pila = element;
		element->next = NULL;
	}else{
		element->next = *pila;
		*pila = element;
	}
}

struct El* pop(struct El** pila){ //function that remove and return data from a stack
	struct El *ret = *pila;
	if(&pila==NULL){
		return NULL;
	}else{
		*pila = ret->next;
	}
	return ret;
}

void stampaPila(struct El* l){ //print in screen numbers returned from pop
    while(!is_empty(l)){
        printf("%d",pop(&l)->valore);
    }
}

int main(){

    struct El* pila;
    struct El* elemento;
    struct El* ret;
    char numeri[1000];

    printf("Inserisci i numeri:\n");
    fflush(stdin);
    scanf("%s", numeri);

    for(int k = 0; numeri[k]!='\0'; k++){ //insert number in stack
        elemento = (struct El*) malloc(sizeof(struct El));
        elemento->valore = numeri[k] - 48;
        push(&pila,elemento);
    }

    stampaPila(pila); //print in screen numbers

    return 0;
 }