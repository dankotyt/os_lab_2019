#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Создаем дочерний процесс
    if ((pid = fork()) == 0) {
        // Код дочернего процесса
        printf("Дочерний процесс с PID %d запущен.\n", getpid());
        // Завершаем дочерний процесс
        exit(0);
    } else if (pid > 0) {
        // Код родительского процесса
        printf("Родительский процесс с PID %d ждет...\n", getpid());
        //wait(NULL);//, sleep убрать
        // Ждем, чтобы дочерний процесс успел завершиться
        sleep(5); // Задержка, чтобы дать время дочернему процессу стать зомби-процессом
        printf("Родительский процесс завершен.\n");
    } else {
        // Ошибка при создании процесса
        perror("fork");
        return 1;
    }

    return 0;
}
