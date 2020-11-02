//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 23

void encoding(){ //trasforma una stringa lunga a corta
    char let;
    int nl=1,i=0,k;
    char string[LUNG];
    fflush(stdin);
    printf("Enter the string to be compressed: ");
    scanf("%s",string);
    let=string[0];
    for(k=1;k<=strlen(string);k++){
        if(let==string[k]){ //ogni volta che incontra quella lettera aumento un contatore
            nl++;
        }else{
            let=string[k]; //quando la lettera cambia la mette nella variabile da controllare
            k--; //evita che non venga saltato una lettera nel conto
            printf("%d",nl);
            printf("%c",string[k]);
            nl=0; //riassegna il conto a 0
        }
    }
}

void decoding(){ //trasforma una stringa corta a lunga
    char string[LUNG];
    int n;
    printf("Enter the string to be decompressed: ");
    fflush(stdin);
    scanf("%s",string);
    for(int k=0;k<strlen(string);k=k+2){
        n=string[k]-48;
        for(int i=0;i<n;i++){ //printa n volte il carattere
            printf("%c",string[k+1]);
        }
    }
}

int main(){
    char string[LUNG],risp[LUNG];
    printf("Encoding or Decoding (LOWERCASE PLEASE): ");
    fflush(stdin);
    scanf("%s",risp);
    if(strcmp(risp,"encoding")==0){
        encoding();
    }else if(strcmp(risp,"decoding")==0){
        decoding();
    }
}
