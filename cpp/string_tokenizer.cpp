#include<bits/stdc++.h>
using namespace std;

// strtok() - string tokenizer function
// // char * strtok( char* str, char* delimiters);
// Splits string into tokens
// a sequence of calls to this function split str into tokens, which are sequence of
// contiguous characters separated by any of the characters that are part of delimiters.

// On a first call, the functions expects a C string as argument for str,
// In subsequent calls, the function expects a NULL pointer

int main(){

    char str[] = "Hi, I am using string tokenizer function in c++";

    char *ptr;

    ptr = strtok(str," ");
    cout<<ptr<<endl; //Output: Hi,

    ptr = strtok(str," ");
    cout<<ptr<<endl; // Output: Hi; -- Strange! ohh read the last line of the description

    ptr = strtok(NULL," ");
    cout<<ptr<<endl;


}
