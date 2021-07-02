# include <stdio.h>
# include <stdlib.h>
# include "base_stack.h"

void menu() {
    system("cls");
    printf("1. empilhar (push)\n");
    printf("2. retirar (pop)\n");
    printf("3. mostrar\n");
    printf("4. mostrar topo\n");
    printf("5. mostrar base\n");
    printf("6. contar a qtd. de elementos\n");
    printf("7. somar os valores\n");
    printf("8. duplicar os valores\n");
    printf("9. fim\n");
    printf("=> ");
}

void mostra_topo(Pilha *p) {
    float v;
    v = pilha_pop(p);
    printf("topo da pilha = %.0f\n", v);
    pilha_push(p, v);
}

void mostra_base(Pilha *p) {
    Pilha *aux = pilha_cria();
    float v;

    while (!pilha_vazia(p)) {
        v = pilha_pop(p);
        pilha_push(aux, v);
    }

    printf("base da pilha = %.0f\n", v);

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p, v);
    }

    pilha_libera(aux);
}

int contar(Pilha *p) {
    Pilha *aux = pilha_cria();
    int qtd = 0;
    float v;

    while (!pilha_vazia(p)) {
        v = pilha_pop(p);
        pilha_push(aux, v);
        qtd++;
    }

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p, v);
    }

    pilha_libera(aux);
    return qtd;
}

float somar(Pilha *p) {
    Pilha *aux = pilha_cria();
    float v, sum = 0.0f;

    while (!pilha_vazia(p)) {
        v = pilha_pop(p);
        pilha_push(aux, v);
        sum += v;
    }

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p, v);
    }

    pilha_libera(aux);
    return sum;
}

void duplicar(Pilha *p) {
    Pilha *aux = pilha_cria();
    float v;

    while (!pilha_vazia(p)) {
        v = pilha_pop(p);
        pilha_push(aux, v);
    }

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p, v * 2.0);
    }

    pilha_libera(aux);
}

int main() {
    Pilha *pi = pilha_cria();
    int opmenu;
    float item;

    do {
        menu();
        scanf("%d", &opmenu);
        switch (opmenu) {
            case 1:
                printf("digite o valor: ");
                scanf("%f", &item);
                pilha_push(pi, item);
                break;
            case 2:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    printf("elemento retirado = %.0f\n", pilha_pop(pi));
                break;
            case 3:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    mostra_pilha(pi);
                break;
            case 4:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    mostra_topo(pi);
                break;
            case 5:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    mostra_base(pi);
                break;
            case 6:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    printf("qtd. de elementos = %d\n", contar(pi));
                break;
            case 7:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    printf("soma dos elementos = %.0f\n", somar(pi));
                break;
            case 8:
                if (pilha_vazia(pi))
                    printf("pilha vazia\n");
                else
                    duplicar(pi);
                break;
        }

        printf("\n");
        system("pause");

    } while (opmenu != 9);

    return 0;
}
