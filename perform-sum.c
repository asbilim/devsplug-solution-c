#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 51
#define MAX_ITEMS 100


char* perform_addition(char* number,char* result){

    int carry = 0 , sum=0;

    for(int i=0;i<MAX_DIGITS;i++){
        sum = (number[i]-'0') + (result[i]-'0') + carry;
        result[i] = (sum % 10) + '0';
        carry = sum/ 10;

    }

    return "dz";
}



int main(void){




    return 0;
}