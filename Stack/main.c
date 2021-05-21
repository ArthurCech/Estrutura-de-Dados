#include <stdio.h>
#include <stdlib.h>
#include "basic_stack.h"

void mostrar_topo(Pilha *p)
{
    float v;
    v = pilha_pop(p);
    printf("Topo = %.0f\n", v);
    pilha_push(p, v);
}

void mostrar_base(Pilha *p)
{
    Pilha *aux = pilha_cria();
    float v;

    while (!pilha_vazia(p)) {
        v = pilha_pop(p);
        pilha_push(aux, v);
    }

    printf("Base = %.0f\n", v);

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p, v);
    }

    pilha_libera(aux);
}

int contar_elementos(Pilha *p)
{
    Pilha *aux = pilha_cria();
    float v;
    int qtd = 0;

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

float somar_elementos(Pilha *p)
{
    Pilha *aux = pilha_cria();
    float v, soma = 0.0f;

    while (!pilha_vazia(p)) {
        v = pilha_pop(p);
        pilha_push(aux, v);
        soma += v;
    }

    while (!pilha_vazia(aux)) {
        v = pilha_pop(aux);
        pilha_push(p, v);
    }

    pilha_libera(aux);
    return soma;
}

void duplicar_elementos(Pilha *p)
{
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

void menu()
{
    system("cls");
    printf("Escolha uma das opcoes do menu:\n");
    printf("1. inserir (push)\n");
    printf("2. retirar (pop)\n");
    printf("3. mostrar\n");
    printf("4. mostrar o topo\n");
    printf("5. mostrar a base\n");
    printf("6. contar elementos\n");
    printf("7. somar elementos\n");
    printf("8. duplicar elementos\n");
    printf("9. fim\n");
    printf("==> ");
}

int main()
{
    Pilha *pi = pilha_cria();
    float item;
    int opmenu;

    do {
        menu();
        scanf("%d", &opmenu);
        
        switch (opmenu) {
            case 1: // inserir
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(pi, item);
                break;
            case 2: // retirar
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    printf("Elemento retirado = %.0f\n", pilha_pop(pi));
                break;
            case 3: // mostrar a pilha
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    mostra_pilha(pi);
                break;
            case 4: // mostrar o topo
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    mostrar_topo(pi);
                break;
            case 5: // mostrar a base
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    mostrar_base(pi);
                break;
            case 6: // mostrar a qtd. de elementos
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    printf("Quantidade de elementos = %d\n", contar_elementos(pi));
                break;
            case 7: // mostrar a soma de elementos
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    printf("Soma dos elementos = %.0f\n", somar_elementos(pi));
                break;
            case 8: // duplicar os valores da pilha
                if (pilha_vazia(pi))
                    printf("Pilha Vazia\n");
                else
                    duplicar_elementos(pi);
                break;
        }

        printf("\n");
        system("pause");

    } while (opmenu != 9);

    return 0;
}