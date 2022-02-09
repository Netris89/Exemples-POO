// Implicitly "inline" functions have the function body
// defined within the class definition.
#include <iostream>
/************** CMoney Class Definition ****************/

using namespace std;
class CMoney
{
public:
    CMoney(long lD, int dC)
        : lDollars(lD), dCents(dC)
    {
    }
    void Display()
    {
        cout << "$" << lDollars << "." << dCents;
    }

private:
    long lDollars;
    int dCents;
};
/**************** Small Test Function *****************/
int main()
{
    CMoney PocketChange(1, 50);
    CMoney CMoneyClip(12, 0);
    PocketChange.Display();
    cout << endl;
    CMoneyClip.Display();
    cout << endl;
    return 0;
}