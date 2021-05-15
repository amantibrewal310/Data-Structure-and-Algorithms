#include<bits/stdc++.h>
using namespace std;

/*
    Polymorphism - where same name means different thing.
    Function Overloading is great example of polymorphism.

    -- we can have same function name with different input types.
    but not with different return types.
    
    ! This was not the part of the c language.

    for example ,


*/

void print(int i) {
    cout << i << endl;
}

void print(string s) {
    cout << s << endl;
}

signed main() {

    print(10);
    print("Hello World!");

}