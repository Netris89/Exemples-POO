// Functions that take reference arguments have access
// to the callers data.
#include <iostream>

using namespace std;
// CHANGE #1
// function prototype
void swap(int &, int &); // reference to integer
void main()              // Identical to swap.cpp
{                        // two local variables
    int nX(5), nY(10);   // Note: equivalent to:
    // int nX=5, nY=10;
    cout << "X is " << nX
         << " and Y is " << nY << endl;
    swap(nX, nY); // function call
    cout << "X is " << nX
         << " and Y is " << nY << endl;
}
// CHANGE #2 Now takes
// references as arguments
void swap(int &nA, int &nB)
{
    int nTemp;
    // same as original SWAP!
    nTemp = nA;
    nA = nB;
    nB = nTemp;
}