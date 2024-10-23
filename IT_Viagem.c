#include <stdio.h>
#include <stdlib.h>

void PTCDD (int X, int *Y){ //Imprime a distancia entre as Cidades

    int i,j; // Variaveis de auxilio
    printf("\nMatriz com as distancias entre as cidades:\n\n");
    for(i=0; i<X; i++) {
        for(j=0; j<X; j++){
                printf("%d ", *(Y+i*X+j));
        }
        printf("\n");
    }

}

void PTITI (int X, int Y, int *A, int *B, int *C){ //Imprime os itinerarios e a distancia Total

    int  i, j, soma=0; // Variaveis de auxilio

    for(i=0; i<X; i++){// imprime o Itinerario
            printf("\nItinerario %d:  ", i+1);
            soma=Y*i;
            for(j=0; j<=*(C+i); j++){
                printf("%d ",*(A+soma+j));
            }
            printf("\n\n");
            printf("A distancia total do Itinerario %d e de:  %d", i+1, *(B+i)); //imprime a distancia total
            printf("\n");
        }
        printf("\n");
}

int main() {

    #define ITIMAX 300 // define quantas ciadades ele pode ir no mesmo ITINERARIO

    int i, j; // Variaveis de auxilio
    int CDD; // Representa o numero de Cidades
    int ITI; // Representa o numero de Itinerarios

    printf("Qual o numero de cidades?  "); //Coleta a quantidade de Cidades
    scanf("%d", &CDD);
    printf("\n");

    int MZCDD[CDD][CDD], *MZC; //Matriz e ponteiro com a distancia entre as Cidades
    MZC = &MZCDD[0][0];

    for(i=0; i<CDD; i++) { // Cria a Matriz com o valor das distancias entre as cidades
        for(j=0; j<CDD; j++){
            printf("Distancia da cidade %d para a cidade %d:  ", i, j);
            scanf("%d", &MZCDD[i][j]);
        }
    }

    printf("\nNumero de itinerarios?  "); //Coleta a quantidade de Itinerarios
    scanf("%d", &ITI);

    int MZITI[ITI][ITIMAX], *MZI; // Matriz e ponteiro com  os Itinerarios
    int DTITI[ITI],*DT; // Vetor e ponteiro com as distancias dos Itinerarios
    int TMITI[ITI],*TM; //Vetor e ponteiro com a quantidade de cidades vizitadas no itinerario
    MZI = &MZITI[0][0];
    DT = DTITI;
    TM = TMITI;

    for(i=0; i<ITI; i++){ // Cria a matriz com os Itinerarios e faz o calculo da Distancia
        DTITI[i]=0;
        *(TM+i)=0;
        printf("\nItinerario %d:\n", i+1);

        while(1){ // Cria a Matriz Itinerario
            printf("Cidade %d:  ", *(TM+i)+1);
            scanf("%d", &MZITI[i][*(TM+i)]);
            if (MZITI[i][*(TM+i)] < CDD){ // Verifica se a cidade informada existe
                if (MZITI[i][*(TM+i)] == MZITI[i][0] && *(TM+i) != 0){ // Verifica se a cidade informada e igual a primeira
                    break;
                }
                 (*(TM+i))++;
            }
            else{
                printf("\nEssa cidade NAO existe. As Cidades Existentes sao: \n"); // Caso a cidade nao exista, informa as cidades existentes
                for (j=0; j<CDD; j++) {
                    printf("Cidade %d;  ", j);
                }
                printf("\n\n");
            }
        }
        for (j=0; j<TMITI[i]; j++){ // Faz o calculo da distancia
            DTITI[i]=DTITI[i] + MZCDD[MZITI[i][j]][MZITI[i][j+1]];
        }
    }

    PTCDD(CDD, MZC); //Imprime a Matriz de distancia da Cidade
    PTITI(ITI,ITIMAX, MZI, DT, TM);
    
return(0);
}
