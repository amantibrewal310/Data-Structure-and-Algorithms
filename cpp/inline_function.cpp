#include<bits/stdc++.h>
using namespace std;

inline int square(int x) {
    return (x*x);
}

/*
    ?What is benifits of the inline function?

    When we call normal function some extra work is also done i.e save the state of the calls so their is some extra time is taken to execute the function.

    So, when we make a function very short than it is not good idea to waste the extra time so it is advise to use inline key word before the return type of the function. whiich represent the request to compiler for make the function inline so, it is not confirm that everytime you use the inline keyword function will become inline as it is only the request to the compiler so compiler may accept it or not.

    Alernatively, macro also does the same work but while using macro their may be issue like :

    #defind macro(x, y) x+y;
    cout << 10*macro(10, 15) << endl;

    here, we get output 115 but we expecting 250.
    This issue can be resolve by the inline function as compiler make sure that this doesn't occur.
    !Macro doesn't do type checking. 

    Also, now modern complier are smart enough that they already make some short function inline so we need not to request them to make the function inline.

*/
signed main() {

    cout << square(10) << endl;

}