#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000




int largest_product_series(int adjacent_digits){

    //adjacent digits for 4 is for example 5832

    char* datas = "73167176531330624919225119674426574742355349194934"
                   "96983520312774506326239578318016984801869478851843"
                    "85861560789112949495459501737958331952853208805511"
                    "12540698747158523863050715693290963295227443043557"
                    "66896648950445244523161731856403098711121722383113"
                    "62229893423380308135336276614282806444486645238749"
                    "30358907296290491560440772390713810515859307960866"
                    "70172427121883998797908792274921901699720888093776"
                    "65727333001053367881220235421809751254540594752243"
                    "52584907711670556013604839586446706324415722155397"
                    "53697817977846174064955149290862569321978468622482"
                    "83972241375657056057490261407972968652414535100474"
                    "82166370484403199890008895243450658541227588666881"
                    "16427171479924442928230863465674813919123162824586"
                    "17866458359124566529476545682848912883142607690042"
                    "24219022671055626321111109370544217506941658960408"
                    "07198403850962455444362981230987879927244284909188"
                    "84580156166097919133875499200524063689912560717606"
                    "05886116467109405077541002256983155200055935729725"
                    "71636269561882670428252483600823257530420752963450";

    int* digits_array = (int*)malloc(sizeof(int)*SIZE);

    for(int i=0; i<SIZE; i++){
        digits_array[i] = datas[i] - '0' ;
    }

    int greatest_sum = 0;

    for(int i=0; i<SIZE; i++){
        for(int j=i+adjacent_digits; j<SIZE-adjacent_digits; j++){
            int product = 1;
            for(int k=0;k<adjacent_digits;k++){
                product*= digits_array[i+k];
            }
            if(product > greatest_sum){
                greatest_sum = product;
            }
        }
    }


    free(digits_array);

    return greatest_sum;
}

int main(void){

    srand(time(NULL));


    int adjacent_digits ;

    printf("Enter the adjacent digits: ");
    scanf("%d", &adjacent_digits);

    int greatest_sum = largest_product_series(adjacent_digits);

    printf("The greatest product of a series of %d consecutive digits is: %d\n", adjacent_digits,greatest_sum);
    //Enter the adjacent digits: 13
    //The greatest product of a series of 13 consecutive digits is: 2091059712
    return 0;
}