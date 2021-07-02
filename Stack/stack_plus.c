# include <stdio.h>
# include <stdlib.h>
# include "base_stack.h"

void empilhar_pilhas(Pilha *p1, Pilha *p2) {
    Pilha *aux = pilha_cria();
    float v;

    while (!pilha_vazia(p2)) {
        v = pilha_pop(p2);
        pilha_push(aux, v);
    }

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p2, v);
        pilha_push(p1, v);
    }

    pilha_libera(aux);
}

Pilha* somar_pilhas(Pilha *p1, Pilha *p2) {
    Pilha *auxp1 = pilha_cria();
    Pilha *auxp2 = pilha_cria();
    Pilha *soma = pilha_cria();
    float v1, v2;

    // esvaziar pilha1 em auxiliar1
    while (!pilha_vazia(p1)) {
        v1 = pilha_pop(p1);
        pilha_push(auxp1, v1);
    }

    // esvaziar pilha2 em auxiliar2
    while (!pilha_vazia(p2)) {
        v2 = pilha_pop(p2);
        pilha_push(auxp2, v2);
    }

    // somar as pilhas
    while (!pilha_vazia(auxp1) || !pilha_vazia(auxp2)) {
        v1 = 0.0f;
        if (!pilha_vazia(auxp1)) {
            v1 = pilha_pop(auxp1);
            pilha_push(p1, v1); // retornar o elemento para pilha1 original
        }

        v2 = 0.0f;
        if (!pilha_vazia(auxp2)) {
            v2 = pilha_pop(auxp2);
            pilha_push(p2, v2); // retornar o elemento para pilha2 original
        }

        pilha_push(soma, v1 + v2);
    }

    pilha_libera(auxp1);
    pilha_libera(auxp2);
    return soma;
}

int main() {
    Pilha *p1 = pilha_cria();
    Pilha *p2 = pilha_cria();
    Pilha *p3;
    int opmenu;

    // popular p1
    pilha_push(p1, 10);
    pilha_push(p1, 20);
    pilha_push(p1, 30);

    // popular p2
    pilha_push(p2, 40);
    pilha_push(p2, 50);

    do {
        system("cls");
        printf("1. empilhar p2 sobre p1\n");
        printf("2. somar as pilhas (p1 + p2) e armazenar na pilha p3\n");
        printf("3. fim\n");
        printf("=> ");
        scanf("%d", &opmenu);

        switch (opmenu) {
            case 1:
                empilhar_pilhas(p1, p2);
                printf("***** pilha 1 *****\n");
                mostra_pilha(p1);
                printf("***** pilha 2 *****\n");
                mostra_pilha(p2);
                break;
            case 2:
                p3 = somar_pilhas(p1, p2);
                printf("***** pilha 1 *****\n");
                mostra_pilha(p1);
                printf("***** pilha 2 *****\n");
                mostra_pilha(p2);
                printf("***** pilha 3 *****\n");
                mostra_pilha(p3);
                break;
        }

        system("pause");
    } while (opmenu != 3);
    
    return 0;
}
