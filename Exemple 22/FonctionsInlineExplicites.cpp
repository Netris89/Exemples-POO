// Using the "inline" keyword, functions are suggested
// for inlining regardless of the location of body.
#include <iostream>
/************** CMoney Class Definition ****************/
using namespace std;
class CMoney
{
public:
    inline CMoney(long lD, int nC);
    inline void Display();

private:
    signed long m_lDollars;
    int m_dCents;
};
/*********** CMoney Class Member Functions *************/
CMoney::CMoney(long lD, int dC)
    : m_lDollars(lD), m_dCents(dC)
{
}
void CMoney::Display()
{
    cout << "$" << m_lDollars << "." << m_dCents;
}
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