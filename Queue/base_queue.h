# define N 5

typedef struct fila {
    int fin; // controla o final
    int ini; // controla o inicio
    float vet[N];
} Fila;

Fila* fila_cria() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->fin = 0;
    f->ini = 0;
    return f;
}

int fila_vazia(Fila *f) {
    if (f->fin == f->ini)
        return 1;
    else
        return 0;
}

void fila_insere(Fila *f, float v) {
    if (f->fin == N) {
        printf("capacidade da pilha esgotada\n");
        return;
    }

    f->vet[f->fin] = v; // inserir no final
    f->fin++;
}

float fila_retira(Fila *f) {
    float v;
    v = f->vet[f->ini]; // retirar do inicio
    f->ini++;
    return v;
}

void fila_libera(Fila *f) {
    free(f);
}

void mostra_fila(Fila *f) {
    printf("conteudo da fila\n");
    for (int i = f->ini; i < f->fin; i++) {
        printf("%.0f\n", f->vet[i]);
    }
    printf("\n");
}
