#include <stdio.h>

void fizz_buzz(int n){

    for(int i=0; i<n; i++){
        if(i%3==0 && i%5==0)
            printf("FizzBuzz\n");
        else if(i%3==0)
            printf("Fizz\n");
        else if(i%5==0)
            printf("Buzz\n");
        else
            printf("%d\n", i);
    }

}

int main(){

    int limit;
    printf("FizzBuzz\n");
    printf("Enter a limit (n) to start: ");
    scanf("%d",&limit);
    fizz_buzz(limit);

}