#include <stdio.h>
#include <stdlib.h>
struct El
{
    int valore;
    struct El *next;
};

void push(struct El* l,int n){
    struct El* t=l;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=(struct El*)malloc(sizeof(struct El*));
    t->next->valore=n;
    t->next->next=NULL;
}

void stampa(struct El* l){
    struct El* t=l;
    while(t!=NULL){
        printf("%d - %p \n", t->valore, t->next);
        t=t->next;
    }
}

int main()
{
    int n;
    struct El *lista;
    lista = NULL; /* mette lista che punta a NULL (niente) */
    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* controllo che lista non abbia nessun valore */
            {
                /* se lista non ha valori faccio la malloc e poi faaccio puntare "l" alla stessa cella di memoria che punta lista */
                lista = (struct El *)malloc(sizeof(struct El));
                lista->valore=n;
                lista->next=NULL;
            }
            else /* se lista ha valori, quindi punta a qualcosa */
            {
                push(lista,n);
            }
        }
    } while (n >= 0);
    printf("numeri inseriti: \n");
    stampa(lista);
    return 0;
}
