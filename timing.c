#include <stdio.h>
#include <time.h>
#include <x86intrin.h>

struct timespec timer_start(){
    struct timespec start_time;
    clock_gettime(CLOCK_REALTIME, &start_time);
    return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
    struct timespec end_time;
    clock_gettime(CLOCK_REALTIME, &end_time);
    long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
    return diffInNanos;
}

#define ITER 1000

int main(){

    unsigned long long r;
    int i = 0;

    struct timespec vartime = timer_start();
    
    for(i=0; i<ITER; ++i){
        _rdseed64_step(&r);
    }

    long time = timer_end(vartime);

    printf("RDSEED instruction latency = %ld ns\n", (time/ITER));

}