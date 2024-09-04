#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void prime_factor(long long int number){

    while(number%2 == 0){
        printf("2 ");
        number/=2;
    }

    for(int i=3;i<=number;i+=2){
        while(number%i == 0){
            printf("%ld ",i);
            number/=i;
        }
    }

    if(number > 2){
        printf("%ld ",number);
    }
    printf("\n");
}
int main(void){

    long long int result;

    do{
        printf("Enter a number (0 to exit): ");
        scanf("%d",&result);
        prime_factor(result);
        printf("\n");
    }while(result != -1);


    return 0;
}