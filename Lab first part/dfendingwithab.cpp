//DFA for string ending with ab
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char input[100];
    cout << "Enter a string to validate (Input string should be 'a' and 'b'):";
    cin >> input;

    int state = 0;  

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            if (state == 0) state = 1;  
            else if (state == 1) state = 1; 
            else if (state == 2) state = 1;  
        } else if (input[i] == 'b') {
            if (state == 0) state = 0;  
            else if (state == 1) state = 2;  
            else if (state == 2) state = 0;  
        } else {
            cout << "Invalid input. Only 'a' and 'b' are allowed." << endl;
            return 1;
        }
    }

    if (state == 2) {
        cout << "String is accepted." << endl;
    } else {
        cout << "String is not accepted." << endl;
    }

    return 0;
}
