#include <iostream>

using namespace std;
int main()
{
    cout << "Construct two CCircle objects:\n";
    CCircle oC1(33),
        oC2(66);
    // CCircle cnot; // error: no default c'tor
    cout << "Construct two CSquare objects:\n";
    CSquare oS1,
        oS2(25);
    cout << "Construct s3 from s2 (25):\n";
    CSquare oS3(oS2); // copy c'tor
    oS3.Display();
    cout << "Construct s4 from c1 (33):\n";
    CSquare oS4(oC1); // conv c'tor
    oS4.Display();
    cout << "Construct c3 from s1 (default):\n";
    CCircle oC3(oS1); // how does this work?
    oC3.Display();
    cout << "Assign a CCircle to a CSquare, s1 = c2\n";
    oS1 = oC2; // conv c'tor for temp object
    cout << "Assign a CSquare to a CCircle, c1 = s2\n";
    oC1 = oS2; // how does this work?
    return 0;
}