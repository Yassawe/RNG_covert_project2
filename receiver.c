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



#define READBITS 16
#define PROBE 8

int main(){
    unsigned int r;
    int* buffer = (int *)malloc(READBITS*PROBE*sizeof(int));
    
    // SYNC
    while((int)(time(NULL))%10);

    printf("Started receiving...\n");


    // RECEIVE
    usleep(25);
    for(int i = 0; i<READBITS; ++i){
        
        for(int j=0; j<PROBE; ++j){
            buffer[i*PROBE + j] = _rdseed32_step(&r);
        }
        usleep(50);

    }

    // DECODE:
    for(int i =0; i<READBITS; ++i){
        int sum = 0;

        for (int j = 0; j<PROBE; ++j){
            sum+=buffer[i*PROBE+j];
        }
        if (sum<PROBE){
            printf("1");    
        }
        else{
            printf("0");
        }
    }
    printf("\n");
        

    return 0;
}
