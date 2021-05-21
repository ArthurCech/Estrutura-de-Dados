#include <stdio.h>
#include <stdlib.h>
#include "base_queue.h"

void menu() {
    system("cls");
    printf("Escolha uma das opcoes do menu:\n");
    printf("1. inserir no final\n");
    printf("2. retirar do inicio\n");
    printf("3. mostrar a fila\n");
    printf("4. fim\n");
    printf("==> \n");
}

int main() {
    Fila *fi = fila_cria();
    int opmenu;
    float item;

    do {
        menu(); 
        scanf("%d", &opmenu);

        switch (opmenu) {
            case 1 : 
                printf("Digite o valor a ser enfileirado: ");
                scanf("%f", &item);
                fila_insere(fi,item);
                break;
            case 2 : 
                if(fila_vazia(fi)) 
                    printf("fila vazia.\n");
                else
                    printf("Elemento retirado = %.0f\n",fila_retira(fi));
                break;    
            case 3 :
                mostra_fila(fi);
                break;                   
        }

        printf("\n");
        system("pause"); 
    } while(opmenu!=4);

    return 0;
}