# define N 5

typedef struct fila {
    int fin; // controla o final
    int ini; // controla o inicio
    int tamVetor;
    float *vet;
} Fila;

Fila* fila_cria() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->fin = 0;
    f->ini = 0;
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

void fila_insere(Fila *f, float v) {
    if (f->fin == N) {
        printf("capacidade da pilha esgotada\n");
        return;
    }

    f->vet[f->fin] = v; // inserir no final
    f->fin++;
}

void compactar(Fila *f) {
    for (int i = 0; i < f->fin; i++) {
        f->vet[i] = f->vet[i + 1];
    }
    
    f->fin--;
}

float fila_retira(Fila *f) {
    float v;
    v = f->vet[f->ini]; // retirar do inicio
    compactar(f);
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
