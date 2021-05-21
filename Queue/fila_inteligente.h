#define N 5

typedef struct fila {
    int inicio;
    int final;
    int tamVetor;
    float *vet;
} Fila;

Fila* fila_cria() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->final = 0;
    f->tamVetor = N;
    f->vet = (float*)malloc(sizeof(Fila) * f->tamVetor);
    return f;
}

int fila_vazia(Fila *f) {
    if (f->final == f->inicio)
        return 1;
    else
        return 0;
}

void fila_insere(Fila *f, float v) {
    int tamFila = f->final - f->inicio;

    // verificar o falso sinal de fila cheia
    if (f->final == N) {
        if (tamFila < N) {
            fila_compactar(f);
        } else {
            printf("Capacidade da fila esgotada.\n");
            return;
        }
    }

    f->vet[f->final] = v;
    f->final++;
}

// compacta quando tiver falso sinal de fila cheia
void fila_compactar(Fila *f) {
    for (int i = 0; i < f->final; i++) {
        f->vet[i] = f->vet[f->inicio + i];
    }

    f->final = f->final - f->inicio;
    f->inicio = 0;
}

float fila_retira(Fila *f) {
    float v;
    v = f->vet[f->inicio];
    f->inicio++;
    return v;
}

void fila_libera(Fila *f) {
    free(f->vet);
    free(f);
}

void mostra_fila(Fila *f) {
    printf("Conteudo da fila\n");
    for (int i = f->inicio; i < f->final; i++) {
        printf("%.0f\n", f->vet[i]);
    }
    printf("\n");
}