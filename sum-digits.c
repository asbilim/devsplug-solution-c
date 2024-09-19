#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;

    // Make sure n is positive for easier manipulation
    if (n < 0) {
        n = -n;
    }

    // Sum digits
    while (n > 0) {
        sum += n % 10;  // Get the last digit
        n /= 10;        // Remove the last digit
    }

    return sum;
}

int main() {
    int n;

    // Input the number
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Output the sum of digits
    printf("Sum of digits: %d\n", sum_of_digits(n));

    return 0;
}
