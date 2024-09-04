#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* prime_factors(int number, int* factors_count){

    int initial_number = number;
    int number_of_factors = 0;

    while(number%2 == 0){
        number_of_factors++;
        number/=2;
    }

    for(int i=3;i<=sqrt(number);i+=2){
        while(number%i == 0){
            number_of_factors++;
            number/=i;
        }
    }

    if(number > 2){
        number_of_factors++;
    }


    *factors_count = number_of_factors;
    int index = 0;
    number = initial_number;
    int* factors = (int*)malloc(sizeof(int) * number_of_factors);

    while(number%2 == 0){
        factors[index] = 2;
        index++;
        number/=2;
    }

    for(int i=3;i<=sqrt(number);i+=2){
        while(number % i==0){
            factors[index] = i;
            index++;
            number/=i;
        }
    }

    if(number>2){
        factors[index] = number;
    }

    return factors;

}


int highest_factor(int* factors,int factors_count,int* power){

    int* factors_counts = (int*)malloc(sizeof(int) * factors_count);

    for(int i=0;i<factors_count;i++){
        factors_counts[i] = 0;
    }

    int highest_number_index = 0;
    int highest_number = factors[0];

    //pour trouver l'index et le nombre le plus grand


    for(int i=0;i<factors_count;i++){
        for(int j=0;j<factors_count;j++){
            if(factors[i] == factors[j]){
                factors_counts[i]++;
            }
        }
    }

    for (int i = 1; i < factors_count; i++) {
        if(factors[i]>highest_number){
            highest_number = factors[i];
            highest_number_index = i;
        }
    }

    for(int i=0;i<factors_count;i++){
        if(factors_counts[i]>=factors_counts[highest_number_index]){
            highest_number_index = i;
            highest_number = factors[i];
        }
    }
    
    *power = factors_counts[highest_number_index];
    free(factors_counts);
    return highest_number;    

}

void smallest_multiple_in_range_10(){

    double result = 1;
    int items = 8;
    int* factor_items = (int*)malloc(items*sizeof(int));
    int* factor_items_power=(int*)malloc(items*sizeof(int));
    int counts_unique = 0;
    
    for(int i=2;i<10;i++){
        int factors_count;
        int* factors = prime_factors(i,&factors_count);
        int power;
        int high_factor = highest_factor(factors,factors_count,&power);
        factor_items[i-2] = high_factor;
        factor_items_power[i-2] = power;
        free(factors);
    }


    free(factor_items);
    free(factor_items_power);

}


int main(void){

    // int number_of_factors;
    // int* factors = prime_factors(315,&number_of_factors);
    // int power;

    // int high_factor = highest_factor(factors,number_of_factors,&power);

    smallest_multiple_in_range_10();


}