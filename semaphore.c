#include<stdio.h>
#include<pthread.h>
#define MAX 10000
int count = 0;

int main(){
    void *add(void* ptr);
    pthread_t thread1,thread2;
//Creating two threads that calls the function add with argument
//as the thread number.
    pthread_create(&amp;thread1,NULL,add,(void*)1);
    pthread_create(&amp;thread2,NULL,add,(void*)2);
//Joining the threads with the main thread of the function
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
//Checking the output
    if(count != 2*MAX){
        printf("\n BOOM!! Count is : %d",count);
    }
//Expected output
    else 
        printf("\n Correct!! count is : %d",count);
    return 0;

}
//Function to increment count. Here count and MAX are 
//global variables. They form the critical section.
void* add(void *ptr){
    int i,tmp;
    int tnum=(int)ptr;
    for(i=0; i &lt; MAX ;i++){
        count++;
    }

}
