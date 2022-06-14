#include <x86intrin.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(){
    unsigned int r;
    int s;
    //while((int)(time(NULL))%10); //sync

    printf("Starting receiving...\n"); 
    

    while(1){
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        s = _rdseed32_step(&r);
        
        if (!s){
            printf("0");
            break;
        }
        usleep(1);
    }

    // int recv[64];


    // for(int i = 0; i<64; ++i){
    //     recv[i] = _rdseed32_step(&r); 
    //     sleep(0.01);
    // }


    // int ones = 0;
    // printf("\nReceived:\n");
    // for(int i=0; i<64; ++i){
    //     ones+=recv[i];
    //     printf("%d", recv[i]);
    // }

    // printf("\n# of 1-s = %d\n", ones);

    

    return 0;
}
