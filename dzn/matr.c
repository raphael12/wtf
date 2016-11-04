#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 3000


struct snd {
    int **a;
    int **b;
};

void *mythread(void *A) {
    pthread_t mythid;
    mythid = pthread_self();
    struct snd *matrix;
    matrix = (struct snd *) A;
    int i, j, k;
    int **C = (int **) malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        C[i] = (int *) malloc(N * sizeof(int));
    }

    for (i = 1; i < N; i += 2) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += (*matrix).a[i][k] * (*matrix).b[k][j];
            }
        }
    }

    return C;
}


int main() {
    pthread_t thid, mythid;
    struct snd matrix;
    int i, j, k;
    int **A = (int **) malloc(N * sizeof(int *));
    int **B = (int **) malloc(N * sizeof(int *));
    int **C = (int **) malloc(N * sizeof(int *));
    int **result = (int **) malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        A[i] = (int *) malloc(N * sizeof(int));
        B[i] = (int *) malloc(N * sizeof(int));
        C[i] = (int *) malloc(N * sizeof(int));
        result[i] = (int *) malloc(N * sizeof(int));
    }
    srand(time(NULL));
    for (i = 0; i < N; i += 1) {
        for (j = 0; j < N; j += 2) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    matrix.a = A;
    matrix.b = B;

    result = pthread_create(&thid, (pthread_attr_t *) NULL, mythread, &matrix);
    mythid = pthread_self();

    for (i = 0; i < N; i += 2) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    for (i = 0; i < N; i++) {
        if(i % 2 == 0) {
            for (j = 0; j < N; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        } else {
            for (j = 0; j < N; j++)
                printf("%d ", result[i][j]);
            printf("\n");

        }
    }

}
