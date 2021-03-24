#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
-Author: Matteo Lamberti
-Target: 
    implements enqueue() and dequeue() method and develop a script that allow
    user to fill a queue of integers (arbitrary lenght). Than
    use dequeue method to empty the queue.
*/

struct El{
    int val;
    struct El* next;
};

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

void main(){
    struct El* tail = (struct El*) malloc(sizeof(struct El));    
    struct El* head = (struct El*) malloc(sizeof(struct El));
    head = NULL;
    tail = NULL;
    struct El* element;
    char risposta;
    do{
        element = (struct El*) malloc(sizeof(struct El));
        printf("inserisci un numero: ");
        fflush(stdin);
        scanf("%d",&element->val); //insert a number
        enqueue(&head,&tail,element);
        printf("vuoi ancora inserire y/n:"); //ask if you want to add another number
        fflush(stdin);
        scanf("%c",&risposta);
    }while(risposta == 'y' || risposta=='Y');

    while (element!=NULL){ //iteration that print the numbers returned from the dequeue
        element = dequeue(&head,&tail);
        printf("%d",element->val);
        free(element); //deallocation of memory
    }
}