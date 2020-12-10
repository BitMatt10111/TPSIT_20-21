//Author: Lamberti

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define SIZE 100 //dimensione del nome dell'errore

typedef struct voloCoord{
    int tempC;
    float lat;
    float lon;
}VoloCoord;

typedef struct voloError{
    int tempE;
    char errorType[SIZE];
}VoloError;

/*funzione che trova a che coordinate
sono stati rilevati errori nel funzionamento
del drone*/
void findError(VoloCoord *coord,int contF1,VoloError *error,int contF2){
    for(int i=0;i<contF2;i++){
        for(int k=0;k<contF1;k++){
            if((coord+k)->tempC == (error+i)->tempE){ 
                //confronta i tempi per vedere se il quel secondo è successo qualcosa
                printf("L'errore %s E' avvenuto al secondo: %d e alle coordinate lat: %.3f e lon: %.3f\n",(error+i)->errorType,(error+i)->tempE,(coord+k)->lat,(coord+k)->lon);
            }
        }
    }
}

int main(){
    FILE* file1;
    FILE* file2;
    VoloCoord *coord;
    VoloError *error;
    /*alloco al puntatore di caratteri una dimensione massima
    per creare una stringa che conterrà una riga e poi la successiva*/
    char* buffer = malloc(SIZE * sizeof(char)); 
    int contF1=0,contF2=0;
    if((file1 = fopen("Volo_drone.csv","r"))==NULL || (file2 = fopen("Anomalie_drone.csv","r"))==NULL){
        printf("ERROR: files not avaiable...");
    }else{
        //leggo una volta il file1 per sapere quanto è lungo
        while(fgets(buffer,SIZE,file1)){ //leggo una volta tutto il file per sapere quante canzoni ci sono all'interno
            contF1++;
        }
        fclose(file1);
        file1=fopen("Volo_drone.csv","r");
        coord = malloc(contF1 * sizeof(VoloCoord)); //alloco al puntatore per la seconda struttura la suo dimensione
        contF1=0;
        fgets(buffer,SIZE,file1);
        while(fgets(buffer,SIZE,file1)){
            //separo la striga con strtok e carico a il vettore di strutture
            (coord+contF1)->tempC=atoi(strtok(buffer,","));
            (coord+contF1)->lat=atof(strtok(NULL,","));
            (coord+contF1)->lon=atof(strtok(NULL,","));
            contF1++;
        }

        //leggo una volta il file2 per sapere quanto è lungo
        while(fgets(buffer,SIZE,file2)){
            contF2++;
        }
        fclose(file2);
        file2=fopen("Anomalie_drone.csv","r");
        error=malloc(contF2*sizeof(VoloError)); //alloco al puntatore per la seconda struttura la suo dimensione
        contF2=0;
        fgets(buffer,SIZE,file2);
        while(fgets(buffer,SIZE,file2)){
            //separo la striga con strtok e carico a il vettore di strutture
            (error+contF2)->tempE=atoi(strtok(buffer,","));
            strcpy((error+contF2)->errorType,strtok(NULL,","));
            contF2++;
        }
        
        //Chiamata funz
        findError(coord,contF1,error,contF2);
    }

}