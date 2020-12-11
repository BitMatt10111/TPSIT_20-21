#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; //assegna a lista NULL cosi potrà entrare nell'if e usare lista anche la prima volta

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) //se la lista punta a NULL (quindi nel primo caso)
            {
                //Assegna a lista la dimension in byte di un tipo struttura: "El" e salva in l lista

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;

            }else{  //se la lista non punta a NULL quindi punta a dei dati (dal secondo ciclo in avanti)
                
                //viene allocata memoria in byte alla lista successiva e l diviene puntatore alla sua stessa next

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
                push(lista,n);
            }
            l->valore = n;  //assegna al campo "valore" della lista l "n"
            l->next = NULL; //assegno al successivo NULL per poter riciclare
        }
    } while (n >= 0);

    l = lista; //riporta "l" all' inizio della lista
    printf("numeri inseriti: ");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; //l diventa il suo successivo puntatndo alla sua next, questo per ciclare tutti i valori
    }
    printf("\n");
    return 0;
}