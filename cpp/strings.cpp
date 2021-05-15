#include<bits/stdc++.h>
using namespace std;

signed main() {
    // char str[] = "gfg";
    // cout << str;
    // cout << sizeof(str);


    // Output of the following programs is compiler depended as some complier might add "\0" at the end some may not.
    // char str[] = {'g', 'f', 'g'};
    // cout << str;
    // cout << sizeof(str);


    /*
        ! Functions
        1. strlen(str)
        2. strcmp(s1, s2)
        3. strcpy(s1, s2)
    */

   // output of the the following programs
//    char str[5];
//    str = "gfg";
//    cout << str;
    // output error at second second line it can be replace by strcpy(str, "gfg")

    /*
        ! C++ Strings
        1. Richer Libray
        2. supports operators like +, <, >, ==, <=, >= are possible
        3.  can assign a string later
        4. Do not have to worry about size.
        5. We can use  c_str() to convert to c-style string.

        ! initialise the string 
            string s(n, 'a');

        ! C++ strings methods
        1. length()
        2. substr(start, end)
        3. find("sample string") - if no result than returns string::npos
    */
    // string s(5, 'a');
    // cout << s;

    /*
        Reading the Stings from the console
        string s;
        cin >> s; 
        stops after space

        so we use 
        getline(cin, s);
        read untill enter is press

        modified getline(cin, s, 'a');
        stops reading untill 'a' is found.
    
    */

}