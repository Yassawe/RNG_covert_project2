#include <x86intrin.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


#define DUR 10000  


int main(){
    unsigned int r;

    while((int)(time(NULL))%10); //sync

    printf("Starting sending...\n"); 

    while(1){
        _rdseed32_step(&r);
    }

    // for(int i = 0; i<strlen(secret); ++i){
    //     for(int j; j<DUR; ++j){
    //         if (secret[i]=='0'){
    //             _rdseed32_step(&r);
    //         }
    //     }
    //     sleep(0.01);
    // }

    return 0;
}
