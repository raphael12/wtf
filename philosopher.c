#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
 //загугленно и как-то понято, не очень понятно #ifdef win32 
#ifdef WIN32
    #include <conio.h>
    #include <Windows.h>
    #define Sleep(X) Sleep(X)
    #define wait() _getch()
#else
    #include <unistd.h>
    #define Sleep(X) sleep(X)
    #define wait() scanf("1")
#endif
 
#define philos 5
 
typedef struct philosopher_tag {
    const char *name;
    unsigned left_fork;
    unsigned right_fork;
} philosopher_t;
 
typedef struct table_tag {
    pthread_mutex_t forks[philos];
} table_t;
 
typedef struct philosopher_args_tag {
    const philosopher_t *philosopher;
    const table_t *table;
} philosopher_args_t;
 
pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;
 
void init_philosopher(philosopher_t *philosopher, const char *name, unsigned left_fork, unsigned right_fork) {
    philosopher->name = name;
    philosopher->left_fork = left_fork;
    philosopher->right_fork = right_fork;
}
 
void init_table(table_t *table) {
    size_t i;
    for (i = 0; i < philos; i++) {
        pthread_mutex_init(&table->forks[i], NULL);
    }
}
 
void* eat(void *args) {
    philosopher_args_t *arg = (philosopher_args_t*) args;
    const philosopher_t *philosopher = arg->philosopher;
    const table_t *table = arg->table;
    unsigned rand;  
 
    while (1) {
        printf("%s started dinner\n", philosopher->name);
 
        pthread_mutex_lock(&entry_point);
        pthread_mutex_lock(&table->forks[philosopher->left_fork]);
        rand_s(&rand);
        rand %= 1000;
        Sleep(rand);
        pthread_mutex_lock(&table->forks[philosopher->right_fork]);
        pthread_mutex_unlock(&entry_point);
 
        printf("%s is eating after %d ms sleep\n", philosopher->name, rand);
 
        pthread_mutex_unlock(&table->forks[philosopher->right_fork]);
        pthread_mutex_unlock(&table->forks[philosopher->left_fork]);
 
        printf("%s finished dinner\n", philosopher->name);
    } 
}
 
void main() {
    pthread_t threads[philos];
    philosopher_t philosophers[philos];
    philosopher_args_t arguments[philos];
    table_t table;
    size_t i;
 
    init_table(&table);
 
    init_philosopher(&philosophers[0], "Vasia", 0, 1);
    init_philosopher(&philosophers[1], "Misha",   1, 2);
    init_philosopher(&philosophers[2], "Seva", 2, 3);
    init_philosopher(&philosophers[3], "Rafa", 3, 4);
    init_philosopher(&philosophers[4], "PodGyzNik", 4, 0);
 
    for (i = 0; i < philos; i++) {
        arguments[i].philosopher = &philosophers[i];
        arguments[i].table = &table;
    }
 
    for (i = 0; i < philos; i++) {
        pthread_create(&threads[i], NULL, eat, &arguments[i]);
    }
 
    for (i = 0; i < philos; i++) {
        pthread_join(threads[i], NULL);
    }
}
