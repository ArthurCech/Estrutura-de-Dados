#define N 5

typedef struct fila {
    int inicio;
    int final;
    float vet[N];
} Fila;

Fila* fila_cria() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->final = 0;
    return f;
}

int fila_vazia(Fila *f) {
    if (f->final == f->inicio)
        return 1;
    else
        return 0;
}

void fila_insere(Fila *f, float v) {
    if (f->final == N) {
        printf("Capacidade da fila esgotada.\n");
        return;
    }

    f->vet[f->final] = v;
    f->final++;
}

float fila_retira(Fila *f) {
    float v;
    v = f->vet[f->inicio];
    f->inicio++;
    return v;
}

void fila_libera(Fila *f) {
    free(f);
}

void mostra_fila(Fila *f) {
    printf("Conteudo da fila\n");
    for (int i = f->inicio; i < f->final; i++) {
        printf("%.0f\n", f->vet[i]);
    }
    printf("\n");
}