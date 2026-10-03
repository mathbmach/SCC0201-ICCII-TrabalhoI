#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int v[], int n);

void merge_sort(int v[], int inicio, int fim);

void intercala(int *v, int inicio, int meio, int fim);

int main() {
    int algoritmo, n;

    scanf("%d", &algoritmo);        // 0: insertion sort - 1: merge sort
    scanf("%d", &n);                // tamanho do vetor

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    if (algoritmo == 0)
        insertion_sort(v, n);
    else
        merge_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");

        printf("%d", v[i]);
    }

    printf("\n");

    return 0;
}

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

void merge_sort(int v[], int inicio, int fim) {
    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;

    merge_sort(v, inicio, meio);
    merge_sort(v, meio + 1, fim);

    intercala(v, inicio, meio, fim);
}

void intercala(int *v, int inicio, int meio, int fim) {
    int tam = fim - inicio + 1;
    int *aux = malloc(tam * sizeof(int));

    if (aux == NULL)
        return;

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i <= meio)
        aux[k++] = v[i++];

    while (j <= fim)
        aux[k++] = v[j++];

    for (k = 0; k < tam; k++)
        v[inicio + k] = aux[k];

    free(aux);
}