#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//by Ilya Mirzazhanov
void *myThreadFun(int n) {
    sleep(1);
    printf("Printing GeeksQuiz from Thread %d\n", n);
    return NULL;
}
   
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i < n+1; i++) {
        pthread_t thread_id;
        printf("Thread #%d created\n", i);
        pthread_create(&thread_id, NULL, myThreadFun(i), NULL);
        pthread_join(thread_id, NULL); // part 2
        printf("Thread #%d exited\n", i);
        // exit(0);
    }
}