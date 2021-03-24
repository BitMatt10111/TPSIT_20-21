#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
-Author: Matteo Lamberti
-Target: 
    Write a function that reverse a queue. Use a stack to reverse
    the numbers taked from input.
*/

struct El{
    int val;
    struct El* next;
};

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

int is_empty(struct El* head){ //function that check if the queue is empty
    if (head == NULL) return 1;
    else return 0;
}

void enqueue(struct El **head, struct El **tail, struct El *element){ //function that add data to a queue

    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next=element;
    }
    *tail = element;
    element->next=NULL;    
}

struct El * dequeue(struct El **head, struct El **tail){ //function that remove and return data from a queue
    struct El *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    if (*head==NULL){
        *tail = NULL;
    }
    return ret;
}

void stampaCoda(struct El** head, struct El** tail){ //function that print a queue

    struct El* valore = (struct El*) malloc(sizeof(struct El));
    valore = dequeue(head, tail);

    while (valore != NULL) { //iteration that print the numbers returned from the dequeue
        printf("%d\n",valore->val);
        valore = dequeue(head, tail);
    }
    free(valore);
}

int main(){
    struct El* head=NULL;
    struct El* tail=NULL;
    struct El* element=NULL;
    struct El* stack=NULL;
    char risp;
    do{
        element=(struct El*)malloc(sizeof(struct El));
        printf("Inserisci un intero: ");
        fflush(stdin);
        scanf("%d",&element->val); //insert a number
        enqueue(&head,&tail,element);
        printf("Vuoi inserire ancora? Y=SI N=NO"); //ask if you want to add another number
        fflush(stdin);
        scanf("%c",&risp);
    }while(risp=='y' || risp=='Y');
    
    while(!is_empty(head)){ //add returned elements from dequeue in a stack using push
        element=dequeue(&head,&tail);
        push(&stack,element);
    }

    while(!is_empty(stack)){ //add returned elements from pop in a queue using enqueue
        element=pop(&stack);
        enqueue(&head,&tail,element);
    }

    stampaCoda(&head,&tail); //add returned elements from dequeue in a stack using push and print them
    return 0;
}