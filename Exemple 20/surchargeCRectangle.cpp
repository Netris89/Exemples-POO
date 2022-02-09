#include <iostream>
#include "Exemple 05\crectangle.cpp"

using namespace std;

CRectangle oR4; // legal with default c'tor
cout << "Displaying oR1:\n";
oR1.Draw();
cout << "\nDisplaying oR2:\n";
oR2.Draw();
cout << "\nDisplaying oR3:\n";
oR3.Draw();
cout << "\nDisplaying oR4:\n";
oR4.Draw();
cout << endl;
Goodbye();
// Note: The destruction of the temporary CRectangle
Goodbye(oR4); // created when oR4 was passed by value.
cout << "\nend of main\n";
return 0;
}
void Goodbye(int dX)
{
    cout << "Hello from Goodbye(int x = "
         << dX << ")\n";
}
void Goodbye(CRectangle oR)
{
    cout << "Hello from Goodbye(CRectangle)\n";
}