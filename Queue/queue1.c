# include <stdio.h>
# include <stdlib.h>

// # include "base_queue.h"
// # include "base_queue_simples.h"
// # include "base_queue_inteligente.h"
# include "base_queue_circular.h"

void menu() {
    system("cls");
    printf("1. inserir elemento\n");
    printf("2. retirar elemento\n");
    printf("3. mostrar\n");
    printf("4. mostrar inicio\n");
    printf("5. mostrar final\n");
    printf("6. contar a qtd. de elementos\n");
    printf("7. somar os valores\n");
    printf("8. duplicar os valores\n");
    printf("9. replicar\n");
    printf("10. fim\n");
    printf("=> ");
}

void mostrar_inicio(Fila *f) {
    printf("inicio da fila = %.0f\n", f->vet[f->ini]);
}

void mostrar_fim(Fila *f) {
    printf("final da fila = %.0f\n", f->vet[f->fin - 1]);
}

int contar(Fila *f) {
    Fila *aux = fila_cria();
    float v;
    int qtd = 0;

    while (!fila_vazia(f)) {
        v = fila_retira(f);
        fila_insere(aux, v);
        qtd++;
    }

    while (!fila_vazia(aux)) {
        v = fila_retira(aux);
        fila_insere(f, v);
    }

    fila_libera(aux);
    return qtd;
}

float somar(Fila *f) {
    Fila *aux = fila_cria();
    float v, soma = 0.0f;

    while (!fila_vazia(f)) {
        v = fila_retira(f);
        fila_insere(aux, v);
        soma += v;
    }

    while (!fila_vazia(aux)) {
        v = fila_retira(aux);
        fila_insere(f, v);
    }

    fila_libera(aux);
    return soma;
}

void duplicar(Fila *f) {
    Fila *aux = fila_cria();
    float v;

    while (!fila_vazia(f)) {
        v = fila_retira(f);
        fila_insere(aux, v);
    }

    while (!fila_vazia(aux)) {
        v = fila_retira(aux);
        fila_insere(f, v * 2.0);
    }

    fila_libera(aux);
}

void replicar(Fila *f) {
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

int main() {
    Fila *fi = fila_cria();
    int opmenu;
    float item;

    do {
        menu();
        scanf("%d", &opmenu);

        switch (opmenu) {
            case 1:
                printf("digite o valor: ");
                scanf("%f", &item);
                fila_insere(fi, item);
                break;
            case 2:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    printf("elemento retirado = %.0f\n", fila_retira(fi));
                break;
            case 3:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    mostra_fila(fi);
                break;
            case 4:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    mostrar_inicio(fi);
                break;
            case 5:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    mostrar_fim(fi);
                break;
            case 6:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    printf("qtd. de elementos = %d\n", contar(fi));
                break;
            case 7:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    printf("soma dos elementos = %.0f\n", somar(fi));
                break;
            case 8:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    duplicar(fi);
                break;
            case 9:
                if (fila_vazia(fi))
                    printf("fila vazia\n");
                else
                    replicar(fi);
                    mostra_fila(fi);
                break;
        }

        printf("\n");
        system("pause");

    } while (opmenu != 10);

    return 0;
}
