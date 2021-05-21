#define N 5

typedef struct fila {
    int inicio;
    int final;
    int tamFila;
    int tamVetor;
    float *vet;
} Fila;

Fila* fila_cria() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->final = 0;
    f->tamVetor = N;
    f->tamFila = 0;
    f->vet = (float*)malloc(sizeof(Fila) * f->tamVetor);
    return f;
}

int fila_vazia(Fila *f) {
    if (f->tamFila == 0)
        return 1;
    else
        return 0;
}

void fila_insere(Fila *f, float v) {
    // capacidade esgotada
    if (f->tamFila == f->tamVetor) {
        printf("Capacidade da fila esgotada.\n");
        return;
    }

    // final chegou no limite, deve voltar para o início
    if (f->final == f->tamVetor) {
        f->final = 0;
    }

    f->vet[f->final] = v;
    f->final++;
    f->tamFila++;
}

float fila_retira(Fila *f) {
    float v;

    v = f->vet[f->inicio];
    f->tamFila--;

    // se o inicio estiver no índice 4 (removeu o último elemento da fila)
    if (f->inicio == f->tamVetor - 1) {
        f->inicio = 0; // voltar para a posição inicial
    } else {
        f->inicio++;
    }

    return v;
}

void fila_libera(Fila *f) {
    free(f->vet);
    free(f);
}

void mostra_fila(Fila *f) {
    printf("Conteudo da fila\n");
    
    if (f->inicio < f->final) { // se o inicio for menor que final (iteração normal)
        for (int i = f->inicio; i < f->final; i++) 
            printf("%.0f\n", f->vet[i]);

    } else { // inicio maior ou igual a final
        for (int i = f->inicio; i < f->tamVetor; i++) // percorrer de f->inicio até o índice 4
            printf("%.0f\n", f->vet[i]);
        
        for (int i = 0; i < f->final; i++) // printar do 0 até o f->final
            printf("%.0f\n", f->vet[i]);
    }

  printf("\n");
}