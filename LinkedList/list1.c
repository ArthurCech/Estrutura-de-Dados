# include <stdio.h>
# include <stdlib.h>

void menu() {
    system("cls");
    printf("1. inserir\n");
    printf("2. inserir de forma ordenada\n");
    printf("3. retirar\n");
    printf("4. mostrar\n");
    printf("5. contar elementos\n");
    printf("6. inserir sem repetir\n");
    printf("7. dobrar os valores da lista\n");
    printf("8. fim\n");
    printf("=> ");
}

typedef struct lista {
    int valor;
    struct lista *prox;
} Lista;

Lista* cria_lista() {
    return NULL;
}

int lista_vazia(Lista *li) {
    return (li == NULL); 
}

Lista* lista_busca(Lista *li, int dado) {
    Lista *aux;

    for (aux = li; aux != NULL; aux = aux->prox) {
        if (aux->valor == dado) {
            return aux;
        }
    }

    return NULL;
}

Lista* insere(Lista *li, int dado) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));

    novo->valor = dado;
    novo->prox = li;

    return novo;
}

Lista* insere_ordenada(Lista *li, int v) {
    Lista *ant = NULL;
    Lista *aux = li;

    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = v;

    // buscar a posicao de insercao
    while (aux != NULL && aux->valor < v) {
        ant = aux;
        aux = aux->prox;
    }

    if (ant == NULL) { // vai ser o primeiro da lista
        novo->prox = li;
        li = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
        
    return li;
}

Lista* insere_sem_repetir(Lista *li, int dado) {
    Lista *aux = lista_busca(li, dado);

    if (aux == NULL) { // nao possui elementos repetidos
        Lista *novo = insere(li, dado);
        return novo;
    } else {
        printf("nao foi possivel inserir o valor, pois ja se encontra na lista");
        return li;
    }
}

Lista* retira(Lista *li, int dado) {
    Lista *ant = NULL; // armazenar o anterior
    Lista *aux = li; // auxiliar para percorrer a lista

    // procurar o elemento
    while (aux != NULL && aux->valor != dado) {
        ant = aux; // armazena ponteiro do elemento anterior
        aux = aux->prox;
    }

    // verifica se achou o elemento
    if (aux == NULL) {
        printf("valor nao localizado\n");
        return li; // retorna a lista
    }

    // achou, retirar o elemento
    if (ant == NULL) // primeiro da lista
        li = aux->prox;
    else
        ant->prox = aux->prox; // religar a lista

    free(aux);

    return li;
}

void mostrar(Lista *li) {
    printf("conteudo da lista\n");
    Lista *aux;

    for (aux = li; aux != NULL; aux = aux->prox) {
        printf("%d\t", aux->valor);
    }

    printf("\n");
}

void lista_libera(Lista *li) {
    Lista *aux, *next;
    aux = li;

    while (aux != NULL) {
        next = aux->prox;
        free(aux);
        aux = next;
    }
}

int contar_elementos(Lista *li) {
    Lista *aux = li;
    int qtd = 0;

    while (aux != NULL) {
        qtd++;
        aux = aux->prox;
    }

    return qtd;
}

void duplicar_valores(Lista *li) {
    Lista *aux;

    for (aux = li; aux != NULL; aux = aux->prox) {
        aux->valor *= 2;
    }
}

int main() {
    Lista *lst;
    lst = cria_lista();
    int valor, opmenu;

    do {
        menu();
        scanf("%d", &opmenu);

        switch (opmenu) {
            case 1:
                printf("digite o valor a ser inserido: ");
                scanf("%d", &valor);
                lst = insere(lst, valor);
                break;
            case 2:
                printf("digite o valor a ser inserido (forma ordenada): ");
                scanf("%d", &valor);
                lst = insere_ordenada(lst, valor);
                break;
            case 3:
                if (lista_vazia(lst)) {
                    printf("lista vazia\n");
                } else {
                    printf("digite o valor a ser retirado: ");
                    scanf("%d", &valor);
                    lst = retira(lst, valor);
                }
                break;
            case 4:
                if (lista_vazia(lst))
                    printf("lista vazia\n");
                else
                    mostrar(lst);
                break;
            case 5:
                printf("qtd. de elementos = %d", contar_elementos(lst));
                break;
            case 6:
                printf("digite o valor a ser inserido (sem repetir): ");
                scanf("%d", &valor);
                lst = insere_sem_repetir(lst, valor);
                break;
            case 7:
                if (lista_vazia(lst))
                    printf("lista vazia\n");
                else
                    duplicar_valores(lst);
                break;
        }

        printf("\n");
        system("pause");

    } while (opmenu != 8);

    return 0;
}
