#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printArray(long int n, int* ptr) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void bubbleSort(long int n, int* ptr, long long int* comparisons) {
    *comparisons = 0;
    int temp;
    for (long int i = 0; i < n - 1; i++) {
        for (long int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (ptr[j] > ptr[j + 1]) {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(long int n, int* ptr, long long int* comparisons) {
    *comparisons = 0;
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = ptr[i];
        j = i - 1;

        while (j >= 0 && ptr[j] > key) {
            (*comparisons)++;
            ptr[j + 1] = ptr[j];
            j = j - 1;
        }
        if (j >= 0) {
           (*comparisons)++;
        }
        ptr[j + 1] = key;
    }
}

int main() {
    long int n = 100000;
    int *vet1_bubble = (int*)malloc(n * sizeof(int));
    int *vet2_insertion = (int*)malloc(n * sizeof(int));

    if (vet1_bubble == NULL || vet2_insertion == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    srand(time(NULL));

    printf("Gerando %ld numeros aleatorios...\n\n", n);
    for (long int i = 0; i < n; i++) {
        vet1_bubble[i] = rand();
    }
    memcpy(vet2_insertion, vet1_bubble, n * sizeof(int));

    long long int bubble_comparisons = 0;
    long long int insertion_comparisons = 0;
    clock_t begin, end;
    double time_spent;

    printf("--- Testando Bubble Sort com n = %ld ---\n", n);
    begin = clock();
    bubbleSort(n, vet1_bubble, &bubble_comparisons);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Numero de comparacoes: %lld\n", bubble_comparisons);
    printf("Tempo de execucao: %.4f segundos\n\n", time_spent);

    printf("--- Testando Insertion Sort com n = %ld ---\n", n);
    begin = clock();
    insertionSort(n, vet2_insertion, &insertion_comparisons);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Numero de comparacoes: %lld\n", insertion_comparisons);
    printf("Tempo de execucao: %.4f segundos\n", time_spent);

    free(vet1_bubble);
    free(vet2_insertion);

    return 0;
}