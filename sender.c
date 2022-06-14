#include <x86intrin.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>

#define DUR 1000  


int main(){
    
    unsigned int r;
    char* secret = "0110010100100100100";

    for(int i = 0; i<strlen(secret); ++i){
        if (secret[i] == "0"){
            usleep(0.336);
        }
        else{
            for(int j=0; j<DUR; j++){
                _rdseed32_step(&r);
            }
        }
    }

    return 0;
}
