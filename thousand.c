#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_number_prime(int number){

    int is_prime = 0;

    if(number<=1) return 0;
    if(number==2) return 1;
    if(number%2==0) return 0;

    for(int i = 3; i <= sqrt(number); i+=2){
        if(number % i == 0){
            return is_prime;
        }
    }

    return 1;

}

int _10001_primes(void){

    int prime_counts = 0;
    int counter = 2;
    int next_prime = 2;

    while(prime_counts<100002){
        if(is_number_prime(counter)){
            next_prime = counter;
            prime_counts++;
        }
        counter++;
    }

    return next_prime;
}

int main(void){

    int last_prime = _10001_primes();

    printf("the last prime is %d\n", last_prime);
    printf("The number %d  is prime: %d \n",last_prime,is_number_prime(last_prime));

    return 0;
}

