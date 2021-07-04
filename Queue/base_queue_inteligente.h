# define N 5

typedef struct fila {
    int fin; // controla o final
    int ini; // controla o inicio
    int tamVetor;
    int tamFila;
    float *vet;
} Fila;

Fila* fila_cria() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->fin = 0;
    f->ini = 0;
    f->tamFila = 0;
    f->tamVetor = N;
    f->vet = (float*)malloc(sizeof(Fila) * f->tamVetor);
    return f;
}

int fila_vazia(Fila *f) {
    if (f->fin == f->ini)
        return 1;
    else
        return 0;
}

void compactar(Fila *f) {
    for (int i = 0; i < f->fin; i++) {
        f->vet[i] = f->vet[f->ini + i];
    }

    f->fin = f->fin - f->ini;
    f->ini = 0;
}

void fila_insere(Fila *f, float v) {
    // int tamanFila = f->fin - f->ini;

    if (f->fin == N) {
        if (f->tamFila < N) {
            compactar(f);
        } else {
            printf("capacidade da pilha esgotada\n");
            return;
        }
    }

    f->vet[f->fin] = v; // inserir no final
    f->fin++;
    f->tamFila++;
}

float fila_retira(Fila *f) {
    float v;
    v = f->vet[f->ini]; // retirar do inicio
    f->ini++;
    f->tamFila--;
    return v;
}

void fila_libera(Fila *f) {
    free(f->vet);
    free(f);
}

void mostra_fila(Fila *f) {
    printf("conteudo da fila\n");
    for (int i = f->ini; i < f->fin; i++) {
        printf("%.0f\n", f->vet[i]);
    }
    printf("\n");
}
