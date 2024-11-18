// design a finite state machine (fsm) that accepts all the strings over input symbols{0,1} having two consecutive 1's as a substring
#include <iostream>
using namespace std;

int main() {
    char Input[100];
    cout << "Enter a string to validate (Input string should be 0 and 1 only):";
    cin.getline(Input, 100);

    int i = -1; 
    A:
    i++;
    if (Input[i] == '0') {
        goto A;  
    } 
    else if (Input[i] == '1') {
        goto B;  
    } 
    else if (Input[i] == '\0') { 
        goto Invalid;
    } 
    else {
        goto Wrong;  
    }

    B:
    i++;
    if (Input[i] == '0') {
        goto A;  
    } 
    else if (Input[i] == '1') {
        goto C; 
    } 
    else if (Input[i] == '\0') {
        goto Invalid;  
    } 
    else {
        goto Wrong;  
    }

    C:
    i++;
    if (Input[i] == '0') {
        goto C;  
    } 
    else if (Input[i] == '1') {
        goto C;  
    } 
    else if (Input[i] == '\0') {
        goto Valid;  
    } 
    else {
        goto Wrong;  
    }
    Valid:
        cout << "String is accepted.\n";
        goto exit;

    Invalid:
        cout << "String is not accepted.\n";
        goto exit;

    Wrong:
        cout << "\nPlease enter a binary string (only 0 and 1).\n";
    
    exit:
        return 0;
}
