#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a number is 1 to 9 pandigital
bool is_pandigital(const char* num) {
    if (strlen(num) != 9) {
        return false;
    }

    bool digits[9] = {false};

    for (int i = 0; i < 9; i++) {
        if (num[i] == '0') {
            return false;  // No zeros allowed in a 1 to 9 pandigital number
        }
        int digit = num[i] - '1';  // Subtract '1' to index digits from 0
        if (digits[digit]) {
            return false;  // Duplicate digits
        }
        digits[digit] = true;
    }

    // Check if all digits 1 to 9 are used
    for (int i = 0; i < 9; i++) {
        if (!digits[i]) {
            return false;
        }
    }

    return true;
}

// Function to concatenate products of n * (1, 2, ..., k) as a string
void concatenated_product(int n, char* result) {
    char buffer[10];
    result[0] = '\0';  // Initialize result as an empty string
    for (int i = 1; i < 10; i++) {
        sprintf(buffer, "%d", n * i);
        strcat(result, buffer);
        if (strlen(result) >= 9) {
            break;
        }
    }
}

// Function to find the largest pandigital multiple
int largest_pandigital_multiple() {
    int largest = 0;
    char concatenated[20];  // Buffer for concatenated product

    // Iterate over n from 1 to 9999
    for (int n = 1; n < 10000; n++) {
        concatenated_product(n, concatenated);
        if (strlen(concatenated) == 9 && is_pandigital(concatenated)) {
            int pandigital_value = atoi(concatenated);
            if (pandigital_value > largest) {
                largest = pandigital_value;
            }
        }
    }

    return largest;
}

int main() {
    int result = largest_pandigital_multiple();
    printf("The largest pandigital multiple is: %d\n", result);
    return 0;
}
