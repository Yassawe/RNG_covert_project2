#include <x86intrin.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(){
    unsigned int r;

    //while((int)(time(NULL))%10); //sync

    printf("Starting receiving...\n"); 

    int recv[64];


    for(int i = 0; i<64; ++i){
        recv[i] = _rdseed32_step(&r); 
        sleep(0.01);
    }


    int majority = 0;
    printf("\nReceived:\n");
    for(int i=0; i<64; ++i){
        majority+=recv[i];
        printf("%d", recv[i]);
    }
    printf("\n");

    if(majority<32){
        printf("Majority: 0\n");
    }
    else{
        printf("Majority: 1\n");
    }

    return 0;
}
