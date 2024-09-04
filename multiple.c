#include <stdio.h>

int multiple_of_3_or_5(int limit){

    int sum = 0;

    for(int i=1; i<limit; i++){
        if(i%5 == 0 || i%3 ==0 ){
            sum+=i;
        }
    }

    return sum;

}

int main(void){

    int test;
    printf("Enter a limit: ");
    scanf("%d",&test);
    printf("Sum of multiples of 3 or 5: %d\n", multiple_of_3_or_5(test));
    return 0;
}