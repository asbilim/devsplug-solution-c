#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    // Special cases
    if (n <= 1) {
        return false;
    }

    // Check divisibility from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    // Input the number
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Check if the number is prime and output the result
    if (is_prime(n)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
