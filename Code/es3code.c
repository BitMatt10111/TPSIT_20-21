#include <stdio.h>
#include <stdlib.h>

/*
-Author: Matteo Lamberti
-Target: 
    Implements stacks and methods pop e push using a queue with its methods
    enqueue() and dequeue().
*/

typedef struct nodo{
    int n;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){ //function that check if the queue is empty
    if (head == NULL)
    {
        return 1;
    }else
    {
        return 0;
    } 
}

void enqueue(Nodo** head, Nodo** tail, Nodo* element){ //function that add data to a queue
    
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;

    return;
}

Nodo* dequeue(Nodo** head, Nodo** tail){ //function that remove and return data from a queue
    
    Nodo* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;

    return ret;
}

void push (Nodo **head, Nodo** tail, Nodo *element){ //function that add data to a stack
    Nodo* supportHead = NULL;
    Nodo* supportTail = NULL;
    Nodo* element2;

    while (!is_empty(*head)){
        element2 = dequeue(head,tail);
        enqueue(&supportHead, &supportTail, element2); //made using enqueue
    }

    enqueue(head, tail, element);

    while (!is_empty(supportHead)){
        enqueue(head, tail, dequeue(&supportHead, &supportTail)); //and dequeue
    }
}

Nodo* pop(Nodo **head){ //function that remove and return data from a stack
    Nodo* ret = *head;

    if (is_empty(*head))
    {
        return NULL;
    }else
    {
        *head = ret->next;
    }

    return ret;
}

void stampaCoda(Nodo **head, Nodo **tail){ //function that print a queue

    Nodo* valore = (Nodo*) malloc(sizeof(Nodo));
    valore = dequeue(head, tail);

    while (valore != NULL) { //iteration that print the numbers returned from the dequeue
        printf("%d\n",valore->n);
        valore = dequeue(head, tail);
    }
    free(valore);
}

void main(){
    Nodo *head = NULL;
    Nodo *tail = NULL;
    Nodo* element = NULL;

    for (int i = 0; i < 10; i++) //iteration that insert in the queue numbers from 1 to 10
    {
        element = (Nodo*) malloc(sizeof(Nodo));

        element->n = i;
        push(&head, &tail, element);
    }
    
    stampaCoda(&head, &tail); //function that print a queue

}