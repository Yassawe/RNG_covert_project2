#include <x86intrin.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

struct timespec timer_start(){
    struct timespec start_time;
    clock_gettime(CLOCK_REALTIME, &start_time);
    return start_time;
}

long timer_end(struct timespec start_time){
    struct timespec end_time;
    clock_gettime(CLOCK_REALTIME, &end_time);
    long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
    return diffInNanos;
}



#define READBITS 100

int main(){
    unsigned int r;
    int* buffer = (int *)malloc(READBITS*sizeof(int));
    
    while((int)(time(NULL))%10);

    printf("Started receiving...\n");
    
    usleep(25);

    for(int i = 0; i<READBITS; ++i){    


        buffer[i] = _rdseed32_step(&r);

        usleep(50);
    }

    for(int i =0; i<READBITS; ++i){
        printf("%d", buffer[i]);
    }
        

    return 0;
}
