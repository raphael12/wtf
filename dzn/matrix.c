#include <pthread.h>
#include <stdio.h>
#include <time.h>	
#include <stdlib.h>
#define N 3000

//pthread_mutex_t lock;

//int pthread_mutex_lock(p_m_t* lock);
//int pthread_mutex_init(pthread_mutex_t* lock, NULL);
//int pthread_mutex_unlock(p_m_t* lock);
//int pthread_mutex_destry(p_m_t* lock);


void *mythread(void *dummy){
	pthread_t mythid; /* Для идентификатора нити исполнения */
	mythid = pthread_self(); 
	int i, j, k;
	//pthread_mutex_init(&lock, NULL);
	int **A = (int**)malloc(N * sizeof(int*));
	int **B = (int**)malloc(N * sizeof(int*));
	int **C = (int**)malloc(N * sizeof(int*));
	for (i = 1; i < N; i+=2) {
		A[i] = (int*)malloc(N * sizeof(int));
		B[i] = (int*)malloc(N * sizeof(int));
		C[i] = (int*)malloc(N * sizeof(int));
	}
	srand(time(NULL));
	for (i = 1; i < N; i+=2) {
		for (j = 1; j < N; j+=2) {
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	for(i = 1; i < N; i+=2) {
		//pthread_mutex_lock(&lock);
	    for(i = 1; i < N; i+=2) {
			for(j = 1; j < N; j+=2) {
				C[i][j] = 0;
				for(k = 1; k < N; k+=2) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	//pthread_mutex_unlock(&lock);
	   
	}
		// pthread_mutex_destroy(&lock);
	
   
	return C;
}


int main() {
	pthread_t thid, mythid;
	int result;
	result = pthread_create( &thid, (pthread_attr_t *)NULL, mythread, NULL);
	mythid = pthread_self();
	int i, j, k;
	//pthread_mutex_init(&lock, NULL);
	int **A = (int**)malloc(N * sizeof(int*));
	int **B = (int**)malloc(N * sizeof(int*));
	int **C = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++) {
		A[i] = (int*)malloc(N * sizeof(int));
		B[i] = (int*)malloc(N * sizeof(int));
		C[i] = (int*)malloc(N * sizeof(int));
	}
	srand(time(NULL));
	for (i = 0; i < N; i+=2) {
		for (j = 0; j < N; j+=2) {
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	for(i=0; i < N; i+=2) {
		//pthread_mutex_lock(&lock);
	    for(i = 0; i < N; i+=2) {
			for(j = 0; j < N; j+=2) {
				C[i][j] = 0;
				for(k = 0; k < N; k+=2) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
		//pthread_mutex_unlock(&lock);
	   
	}
		//pthread_mutex_destroy(&lock);
	
	//pthread_join(thid, (void **)NULL);
	

	printf("result\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", C[i][j]);
			printf("\n");
	}
	return 0;
}
