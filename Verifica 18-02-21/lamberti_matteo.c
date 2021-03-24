#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Carte{
    int valore;
    char seme;
    struct Carte* next;
};

int is_empty(struct Carte* head){ //controlla se la pila è vuota
    if (head == NULL) return 1;
    else return 0;
}

void push(struct Carte** pila, struct Carte* element){ //aggiunge un elemento alla cima della pila
	if (&pila==NULL){
		*pila = element;
		element->next = NULL;
	}else{
		element->next = *pila;
		*pila = element;
	}
}

struct Carte* pop(struct Carte** pila){ //toglie un elemento dalla cima della pila
	struct Carte *ret = *pila;
	if(&pila==NULL){
		return NULL;
	}else{
		*pila = ret->next;
	}
	return ret;
}

void stampaPila(struct Carte* l){ //stampa tutta la pila "poppando" i valori
    while(!is_empty(l)){
        struct Carte* carta=pop(&l);
        printf("%d - %c\n",carta->valore,carta->seme);
    }
}

/*

bool ctrl(struct Carte* head,struct Carte* carta){
    struct Carte* temp = head;
    bool giaPresente=false;
    while(temp!=NULL){
        if(temp->valore==carta->valore && temp->seme==carta->seme){
            giaPresente=true;
        }
        temp=temp->next;
    }
    return giaPresente;
}

parte di main per il random che però non funziona
        do{    
            srand(time(0));
            cartaSingola->valore=+rand()%13;
            int seed=1+rand()%4;
            if(seed==1){
                cartaSingola->seme='C';
            }else if(seed==2){
                cartaSingola->seme='P';
            }else if(seed==3){
                cartaSingola->seme='D';
            }else if(seed==4){
                cartaSingola->seme='F';
            }
        }while(ctrl(mazzo,cartaSingola)==false);
*/

int main(){
    struct Carte* mazzo=NULL; //head della pila - mazzo completo
    struct Carte* cartaSingola=NULL;
    struct Carte* alice=NULL; //head della pila - mazzo di alice
    struct Carte* bob=NULL; //head della pila - mazzo di bob

    for(int seed=0;seed<4;seed++){ //cicla per i semi (quindi 4)
        for(int num=1;num<=13;num++){ //cicla per i valori delle carte (quindi 13)
            cartaSingola=(struct Carte*)malloc(sizeof(struct Carte));
            if(seed==0){
                cartaSingola->seme='C';
            }else if(seed==1){
                cartaSingola->seme='P';
            }else if(seed==2){
                cartaSingola->seme='D';
            }else if(seed==3){
                cartaSingola->seme='F';
            }
            cartaSingola->valore=num;
            push(&mazzo,cartaSingola); //dopo aver aggiunto seme e valore "mette la carta nel mazzo"
        }
    }

    while(!is_empty(mazzo)){ //cicla finchè non finisce la pila e distribuisce le carte ad uno ad uno
        srand(time(0));
        int scelta=rand()%2; //randomizza se fare prima bob o prima alice
        //printf("%d",scelta); - serviva per vedere se randomizzava giusto 0 e 1
        if(scelta==0){ //prima alice
            push(&alice,pop(&mazzo));
            push(&bob,pop(&mazzo));
        }else if(scelta==1){ //prima bob
            push(&bob,pop(&mazzo));
            push(&alice,pop(&mazzo));
        }
    }
    stampaPila(alice); //stampa mazzo di alice
    return 0;
}