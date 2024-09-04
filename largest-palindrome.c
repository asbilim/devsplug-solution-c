#include <stdio.h>
#include <stdlib.h>

int is_palindrome(int number){
    int reverse = 0, original_number = number;
    while (number > 0){
        reverse = (number%10) + reverse*10;
        number /= 10;
    }
    return original_number == reverse;
}

int largest_palindrome_product(){

    int largest = 0;

    for(int i=999;i>=100;i--){
        for(int j=i;j>100;j--){
            int product = i*j;
            if(is_palindrome(product) && product>largest){
                largest = product;
            }
        }
    }

    return largest;

}

int main(void){

    printf("The largest palindrome product of two 3-digit numbers is: %d\n", largest_palindrome_product());
    //result : 906609
    return 0;
}