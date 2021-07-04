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
    if (f->tamFila == 0)
        return 1;
    else
        return 0;
}

void fila_insere(Fila *f, float v) {
    if (f->tamFila == f->tamVetor) {
        printf("capacidade da pilha esgotada\n");
        return;
    }

    if (f->fin == f->tamVetor) { // final chegou no limite, deve voltar para o inicio
        f->fin = 0;
    }

    f->vet[f->fin] = v;
    f->fin++;
    f->tamFila++;
}

float fila_retira(Fila *f) {
    float v;

    v = f->vet[f->ini];
    f->tamFila--;

    if (f->ini == f->tamVetor - 1) { // se removeu o ultimo elemento
        f->ini = 0; // voltar para o inicio
    } else {
        f->ini++;
    }

    return v;
}

void fila_libera(Fila *f) {
    free(f->vet);
    free(f);
}

void mostra_fila(Fila *f) {
    printf("conteudo da fila\n");

    if (f->ini < f->fin) {
        for (int i = f->ini; i < f->fin; i++)
            printf("%.0f\n", f->vet[i]);
    } else { // inicio >= final
        for (int i = f->ini; i < f->tamVetor; i++)
            printf("%.0f\n", f->vet[i]);
        
        for (int i = 0; i < f->fin; i++)
            printf("%.0f\n", f->vet[i]);
    }   

    

    printf("\n");
}
