#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fibonacci(int number){

    if(number <=0){
        return 1;
    }

    int current = 0 , next=1;

    for(int i = 1; i < number; i++){
        swap(&current,&next);
        int sum = next + current;
        swap(&next,&sum);
    }

    return next;

}

int evenFibonacci(void){
    int sum = 0, fib = 0;
    for(int i = 0; fib <= 4000000; i++){
        fib = fibonacci(i);
        if(fib % 2 == 0){
            sum += fib;
        }
    }
    return sum;
}

int main(){

    long long int result = evenFibonacci();

    printf("The sum of even Fibonacci numbers below 4,000,000 is: %lld\n", result);

    return 0;
}