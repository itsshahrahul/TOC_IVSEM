#include <stdio.h>
#include <string.h>

#define MAX 1000

// Tape and pointer
char tape[MAX];
int head = 0;

// States
typedef enum { q0, q1, q2, q_accept, q_reject } State;
State state = q0;

// Function to move head left
void moveLeft() {
    if (head > 0) head--;
}

// Function to move head right
void moveRight() {
    head++;
}

// Function to simulate the Turing Machine
void turingMachine() {
    while (state != q_accept && state != q_reject) {
        char current = tape[head];
        
        switch (state) {
            case q0:
                if (current == 'a') {
                    tape[head] = 'X';  // Mark 'a' as processed
                    moveRight();
                    state = q1;        // Go to state q1 to find 'b'
                } else if (current == 'Y') {
                    moveRight();        // Skip marked 'b'
                } else if (current == '#') {
                    state = q_accept;   // All 'a's and 'b's processed
                } else {
                    state = q_reject;   // Invalid character or mismatch
                }
                break;
                
            case q1:
                if (current == 'b') {
                    tape[head] = 'Y';  // Mark 'b' as processed
                    moveLeft();
                    state = q2;        // Go to state q2 to return and find next 'a'
                } else if (current == 'X' || current == 'Y') {
                    moveRight();        // Skip marked 'a's and 'b's
                } else {
                    state = q_reject;   // No matching 'b' for an 'a'
                }
                break;
                
            case q2:
                if (current == 'X') {
                    moveLeft();         // Keep moving left to find next 'a'
                } else if (current == 'a') {
                    state = q0;         // Go back to state q0 to mark this 'a'
                } else {
                    state = q_reject;   // No more 'a's
                }
                break;
        }
    }
}

int main() {
    printf("Enter the input string (a^n b^n format): ");
    scanf("%s", tape);
    
    // Append blank symbol at the end
    strcat(tape, "#");
    
    turingMachine();
    
    if (state == q_accept) {
        printf("The string is accepted by the Turing Machine.\n");
    } else {
        printf("The string is rejected by the Turing Machine.\n");
    }

    return 0;
}
