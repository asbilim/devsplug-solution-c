#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int print_divisor(int number){

    int divisor_count = 0;

    long long int i;

    for(i=1;i*i<number;i++){
        if(number % i == 0){
            divisor_count += 2;
        }
    }

    if(i*i==number){
        divisor_count++;
    }

    return divisor_count;

}


long long int generate_triangular(int position){

    long long int value  = (position * (position+1)) / 2 ;

    return value;

}


int main(){

    int counter = 1000 ;
    long long int triangular = 1;

    do{
        long long int triangular = generate_triangular(counter);

        int divisors = print_divisor(triangular);


        if(divisors >= 500){
            printf("The number %d has %d divisors\n",triangular, divisors);
            break;
        }

        counter++;
    }while(triangular<500);


    return 0;
}



