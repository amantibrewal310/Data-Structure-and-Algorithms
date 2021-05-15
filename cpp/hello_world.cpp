#include <iostream>
using namespace std;

// If some program compile in some compile then do check iso standard website for the reference. Because there are some standard we need to follow for example return type of main() can't be void according to the standard but some compiler allows the return type of the main() as void.

/* 
    1. cout - standard output
    2. cin - standard input
    3. cerr - error handling use to write on the unbuffered stream
    4. clog - error handling use to write on the buffered stream

    Difference between "\n" and "endl" :
        endl - flushes the buffer output stream along with new line while "\n" just newline that why it advised to use "\n" when we are dealing with competitve programming.
*/

int main()
{
    cout << "Hello World!" << endl;
    // "<<" this operator name is insertion operator. Because it allow to insert data on the output screen.
    // "<<" this operator name is extractor operator.
    // Cout on the monitor.
    // cin means input from the keyboard
    // ceer
    return 0;
}