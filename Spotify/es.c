#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
//#define N_CANZONI 10
#define SIZE 100 //grandezza massima di una riga del file

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
}Canzone;

bool check(int* vet,int cerc,int dim){ //funzione che controlla se il numero randomico inserito è già presente all'interno del vettore
    bool ok=false;
    for(int k=0;k<dim;k++){
        if(cerc==*(vet+k)){ //se è uguale return true ed esce dal ciclo
            ok=true;
            k=dim;
        }
    }
    return ok;
}

void printRand(Canzone* playlist,int dim){
    int* vet;
    vet = malloc(dim  * sizeof(int));
    srand(time(NULL));
    for(int i=0;i<dim;i++){
        do{
            *(vet+i)=rand()%(dim-1+1);//carica il vettore con un valore randomico da 0 a 9
        }while(check(vet,*(vet+i),i));//funzione che controlla se il numero randomico inserito è già presente all'interno del vettore
    }
    for(int j=0;j<dim;j++){
        //printf("%d\n",*(vet+j));
        printf("%d - %s - %s\n",(playlist+(*(vet+j)))->num,(playlist+(*(vet+j)))->nome_canzone,(playlist+(*(vet+j)))->artista);
        //scrive a schermo in modo randomico le canzoni utilizzando il vettore randomico da 0 a 9.
    }
}

int main(){
    FILE* fp;
    Canzone* playlist;
    char* buffer;
    buffer = malloc(SIZE * sizeof(char));
    int k=0;
    if((fp=fopen("canzoni.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer,SIZE,fp)){
            k++;
        }
        fclose(fp);
        fp=fopen("canzoni.csv","r");
        playlist = malloc(k * sizeof(Canzone));
        k=0;
        while(fgets(buffer,SIZE,fp)){
            (playlist+k)->num = atoi(strtok(buffer,",")); //prende tutto prima della virgola e lo trasforma in intero
            //printf("%d",playlist[k].num);
            strcpy((playlist+k)->nome_canzone,strtok(NULL,",")); //prende tutto da dopo la virgola alla virgola successiva
            //printf("%s",playlist[k].nome_canzone);
            strcpy((playlist+k)->artista,strtok(NULL,"\n")); //prende tutto fino all'a capo
            //printf("%s\n",playlist[k].artista);
            k++;
        }
        printRand(playlist,k);
    }
}
