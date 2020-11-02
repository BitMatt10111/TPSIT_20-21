#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define N_CANZONI 11
#define SIZE 100

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
}Canzone;

void visualizzaPlaylist(Canzone play[],int num){
    for(int k=0; k<num; k++){
        printf("%d - %s - %s\n",play[k].num,play[k].nome_canzone,play[k].artista);
    }
}

bool check(int vet[],int cerc,int dim){
    bool ok=false;
    for(int k=0;k<dim;k++){
        if(cerc==vet[k]){
            ok=true;
            k=dim;
        }
    }
    return ok;
}

void printRand(Canzone playlist[],int dim){
    int vet[dim];
    srand(time(NULL));
    for(int i=0;i<dim;i++){
        do{
            vet[i]=rand()%(dim-1+1);
        }while(check(vet,vet[i],i));
    }
    for(int j=0;j<dim;j++){
        printf("%d - %s - %s\n",playlist[vet[j]].num,playlist[vet[j]].nome_canzone,playlist[vet[j]].artista);
    }
}

int main(){
    FILE *fp;
    Canzone playlist[N_CANZONI];
    char buffer[SIZE];
    int k=0;

    if((fp=fopen("canzoni.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer,SIZE,fp)){
            playlist[k].num = atoi(strtok(buffer,","));
            //printf("%d",playlist[k].num);
            strcpy(playlist[k].nome_canzone,strtok(NULL,","));
            //printf("%s",playlist[k].nome_canzone);
            strcpy(playlist[k].artista,strtok(NULL,"\n"));
            //printf("%s\n",playlist[k].artista);
            k++;
        }
        printRand(playlist,k);
    }
}