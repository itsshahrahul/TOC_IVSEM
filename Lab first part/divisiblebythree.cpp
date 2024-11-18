//dfa that accept string divisible by 3
#include <stdio.h>
int isDivisibleBy3(const char *binaryStr) {
    int state = 0; 
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        char input = binaryStr[i];
        if (input == '0') {
            if (state == 0) {
                state = 0; // 0 -> 0
            } else if (state == 1) {
                state = 2; // 1 -> 2
            } else if (state == 2) {
                state = 1; // 2 -> 1
            }
        } else if (input == '1') {
            if (state == 0) {
                state = 1; 
            } else if (state == 1) {
                state = 0; 
            } else if (state == 2) {
                state = 2; 
            }
        } else {
            printf("Invalid input: Binary string can only contain 0 and 1.\n");
            return 0; 
        }
    }
    return (state == 0);
}
int main() {
    char binaryStr[100];
    printf("Enter a binary string: ");
    scanf("%s", binaryStr);
    if (isDivisibleBy3(binaryStr)) {
        printf("The binary string is divisible by 3.\n");
    } else {
        printf("The binary string is not divisible by 3.\n");
    }
    return 0;
}
