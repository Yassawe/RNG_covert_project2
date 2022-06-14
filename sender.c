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

#define ITER 1000  


int main(){
    
    unsigned int r;
    char* secret = "1110001110000001";
    printf("Secret is: %s\n", secret);

    while((int)(time(NULL))%10);

    printf("Started sending...\n");

    for(int i = 0; i<strlen(secret); ++i){
        if (secret[i] == '0'){
            usleep(50);
        }
        else{
            for(int j=0; j<ITER; ++j){
                _rdseed32_step(&r);
            }
        }
    }

    return 0;
}
