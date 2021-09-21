#include <stdio.h>                                  
#include <time.h>                                       
#include <pthread.h>
//by Ilya Mirzazhanov                                            
int cnt = 0;                                            
#define SLOTS 100                                           
char buffer[SLOTS]; time_t strt; int i = 0;                             
pthread_mutex_t mutex; pthread_cond_t condc, condp;                                                         

void *producer(void *ptr) {
 while(1) {                                             
  pthread_mutex_lock(&mutex);                                                   

  if(cnt == SLOTS) pthread_cond_wait(&condp, &mutex);                                           

  buffer[cnt] = 's'; cnt++;                                 
  time_t end = time(NULL); double frc = (double)(end - strt);                               

  if(frc > i*60) {                                                      
   printf("Time of execution:%f\n", ((double)(end - strt)));
   i++;                                                             
  }

  if(cnt == 1) {
   pthread_cond_signal(&condc); pthread_mutex_unlock(&mutex);
  }                                                             

 }
}

void *consumer(void *ptr) {
 while(1) { 
  pthread_mutex_lock(&mutex);                               

  if(cnt == 0) pthread_cond_wait(&condc, &mutex);

  buffer[cnt] = 't'; cnt--;
  if (cnt == SLOTS - 1) {
   pthread_cond_signal(&condp); pthread_mutex_unlock(&mutex);
  }

 }

}

int main(int argc, char const *argv[]) {
 strt = time(NULL); pthread_t pro, con;

 pthread_mutex_init(&mutex, 0);

 pthread_cond_init(&condc, 0);
 pthread_cond_init(&condp, 0);

 pthread_create(&con, 0, consumer, 0);
 pthread_create(&pro, 0, producer, 0);

 pthread_join(pro, 0);
 pthread_join(con, 0);
 
 pthread_cond_destroy(&condc);
 pthread_cond_destroy(&condp);

 pthread_mutex_destroy(&mutex);
 
 return 0;
}