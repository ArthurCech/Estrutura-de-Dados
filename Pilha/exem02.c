#include <stdio.h>
#include <stdlib.h>
#include "exem.h"

void empilhar_pilhas(Pilha *p1, Pilha *p2)
{
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

Pilha* somar_pilhas(Pilha *p1, Pilha *p2)
{
    Pilha *auxP1 = pilha_cria();
    Pilha *auxP2 = pilha_cria();
    Pilha *soma = pilha_cria();
    float v1, v2;

    // popular auxiliares com elementos de pilha1 e pilha2
    while (!pilha_vazia(p1)) {
        v1 = pilha_pop(p1);
        pilha_push(auxP1, v1);
    }

    while (!pilha_vazia(p2)) {
        v1 = pilha_pop(p2);
        pilha_push(auxP2, v1);
    }

    // montar a pilha de soma
    while (!pilha_vazia(auxP1) || !pilha_vazia(auxP2)) {
        v1 = 0.0f;
        if (!pilha_vazia(auxP1)) {
            v1 = pilha_pop(auxP1);
            pilha_push(p1, v1);
        }

        v2 = 0.0f;
        if (!pilha_vazia(auxP2)) {
            v2 = pilha_pop(auxP2);
            pilha_push(p2, v2);
        }

        pilha_push(soma, v1 + v2);
    }

    pilha_libera(auxP1);
    pilha_libera(auxP2);
    return soma;
}



int main()
{
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

    printf("Escolha uma das opcoes do menu:\n");
    printf("1. empilhar p2 sobre p1\n");
    printf("2. somar as pilhas e armazenar em uma terceira pilha\n");
    printf("==> ");
    scanf("%d", &opmenu);

    switch (opmenu) {
        case 1:
            empilhar_pilhas(p1, p2);
            printf("***** Pilha 1 *****");
            mostra_pilha(p1);
            printf("***** Pilha 2 *****");
            mostra_pilha(p2);
            break;
        case 2:
            p3 = somar_pilhas(p1, p2);
            printf("***** Pilha 1 *****");
            mostra_pilha(p1);
            printf("***** Pilha 2 *****");
            mostra_pilha(p2);
            printf("***** Pilha 3 *****");
            mostra_pilha(p3);
            break;
    }

    return 0;
}