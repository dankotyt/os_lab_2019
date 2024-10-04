#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Объявление двух мьютексов
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

// Функция, которую будет выполнять первый поток
void* thread1_function(void* arg) {
    // Блокировка первого мьютекса
    pthread_mutex_lock(&mutex1);
    printf("Поток 1: заблокировал mutex1\n");

    // Задержка для демонстрации deadlock
    sleep(1);

    // Попытка блокировки второго мьютекса
    printf("Поток 1: пытается заблокировать mutex2\n");
    pthread_mutex_lock(&mutex2);
    printf("Поток 1: заблокировал mutex2\n");

    // Разблокировка мьютексов
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    return NULL;
}

// Функция, которую будет выполнять второй поток
void* thread2_function(void* arg) {
    // Блокировка второго мьютекса
    pthread_mutex_lock(&mutex2);
    printf("Поток 2: заблокировал mutex2\n");

    // Задержка для демонстрации deadlock
    sleep(1);

    // Попытка блокировки первого мьютекса
    printf("Поток 2: пытается заблокировать mutex1\n");
    pthread_mutex_lock(&mutex1);
    printf("Поток 2: заблокировал mutex1\n");

    // Разблокировка мьютексов
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Создание потоков
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);

    // Ожидание завершения потоков
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Программа завершена.\n");

    return 0;
}