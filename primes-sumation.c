#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int number){

    if(number <= 1) return 0;
    if(number %2 == 0) return 0;

    for(int i=3;i<sqrt(number);i++){
        if(number%i == 0) return 0;
    }

    return 1;

}

int primes_sumation(){

    int sum = 0;
    for(int i=1;i<=2000000;i++){
        if(is_prime(i)) sum += i;
    }
    return sum;
    

}

int main(void){

    printf("Sum of prime numbers from 1 to 2 million: %d\n", primes_sumation());
    //Sum of prime numbers from 1 to 2 million: 1308111342

    return 0;
}