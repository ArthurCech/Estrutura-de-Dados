#include <stdio.h>
#include <stdlib.h>
//#include "fila_burra.h" // compactar após cada remoção
//#include "fila_inteligente.h" // compactar quando tiver falso sinal de fila cheia
#include "fila_circular.h"

void mostra_inicio(Fila *f) {
    float primeiro;
    primeiro = f->vet[f->inicio];
    printf("inicio da fila = %.0f\n", primeiro);
}

void mostra_fim(Fila *f) {
    float ultimo;
    ultimo = f->vet[f->final - 1];
    printf("final da fila = %.0f\n", ultimo);
}
 
int contar_elementos(Fila *f) {
    Fila *aux = fila_cria();
    int total = 0;
    float valor;

    while (!fila_vazia(f)) {
        valor = fila_retira(f);
        fila_insere(aux, valor);
        total++;
    }

    while (!fila_vazia(aux)) {
        valor = fila_retira(aux);
        fila_insere(f, valor);
    }

    fila_libera(aux);

    return total;
}

float somar_elementos(Fila *f) {
    Fila *aux = fila_cria();
    float valor, soma = 0.0f;

    while (!fila_vazia(f)) {
        valor = fila_retira(f);
        fila_insere(aux, valor);
        soma += valor;
    }

    while (!fila_vazia(aux)) {
        valor = fila_retira(aux);
        fila_insere(f, valor);
    }

    fila_libera(aux);

    return soma;
}

void duplicar_elementos(Fila *f) {
    Fila *aux = fila_cria();
    float valor;

    while (!fila_vazia(f)) {
        valor = fila_retira(f);
        fila_insere(aux, valor);
    }

    while (!fila_vazia(aux)) {
        valor = fila_retira(aux);
        fila_insere(f, valor * 2.0);
    }

    fila_libera(aux);
}

//repete os elementos de f em f
void replica(Fila *f) {
	Fila *a1 = fila_cria();
	Fila *a2 = fila_cria();
	float x;

	while (!fila_vazia(f)) {
		x = fila_retira(f);
		fila_insere(a1, x);
		fila_insere(a2, x);
	}

	while (!fila_vazia(a1))
	    fila_insere(f, fila_retira(a1));
	fila_libera(a1);

	while (!fila_vazia(a2))
	    fila_insere(f, fila_retira(a2));
	fila_libera(a2);
}

void menu() {
    system("cls");
    printf("Escolha uma das opcoes do menu:\n");
    printf("1. inserir no final\n");
    printf("2. retirar do inicio\n");
    printf("3. mostrar a fila\n");
    printf("4. mostrar o inicio\n");
    printf("5. mostrar o final\n");
    printf("6. contar elementos\n");
    printf("7. somar elementos\n");
    printf("8. duplicar os elementos\n");
    printf("9. replicar a fila\n");
    printf("10. fim\n");
    printf("==> ");
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
            case 4: // mostrar inicio
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    mostra_inicio(fi);
                break;
            case 5: // mostrar final
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    mostra_fim(fi);
                break;
            case 6: // contar elementos
                printf("quantidade de elementos = %d\n", contar_elementos(fi));
                break;
            case 7: // somar elementos
                if (fila_vazia(fi)) 
                    printf("fila vazia\n");
                else
                    printf("soma dos elementos = %.0f\n", somar_elementos(fi));
                break;
            case 8: // duplicar elementos
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    duplicar_elementos(fi);
                break;  
            case 9: // replicar a fila
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    replica(fi);
	                mostra_fila(fi);
                break;  
        }

        printf("\n");
        system("pause"); 

    } while (opmenu!=10);

    return 0;
}