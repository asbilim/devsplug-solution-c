#include <stdio.h>
#include <math.h>


int sum_square(int range){

    int sum_squares = (range * (range+1)*(2*range + 1)) / 6;
    int square_sums = (range * (range+1)) / 2;

    return pow(square_sums,2) - sum_squares;
}

int main(void){

    int result = sum_square(100);

    printf("The sum square difference of the first 100 natural numbers is: %d\n", result);

    return 0;
}