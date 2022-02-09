// Demonstration of accessor/manipulator pairs.
// Note: Many commercial class packages refer to these
// as functions that access object attributes.
#include <iostream>
/************ CRectangle Class Declaration *************/
using namespace std;

class CRectangle
{
    public:
        void SetHeight(int); // Set member functions:
        void SetWidth(int);  // take an arg as a new value
        int GetHeight(void); // Get member functions:
        int GetWidth(void);  // take no args, return a value
        int m_dHeight, m_dWidth; // FIXME: Est-ce que ça doit vraiment être en private ?! (page 51)
    private:
};
/************* CRectangle Member Functions *************/
void CRectangle::SetHeight(int dH)
{
    m_dHeight = dH;
}
void CRectangle::SetWidth(int dW)
{
    m_dWidth = dW;
}
int CRectangle::GetHeight(void)
{
    return m_dHeight;
}
int CRectangle::GetWidth(void)
{
    return m_dWidth;
}
/**************** Small Test Program ******************/
int main()
{
    CRectangle oR1;                   // Declare a CRectangle object oR1
    oR1.SetHeight(15);                // Set the height attribute.
    oR1.SetWidth(10);                 // Set the width attribute.
    cout << "width " << oR1.m_dWidth; // Illegal access!
    cout << "The area of CRectangle oR1 is "
         << (long)oR1.GetHeight() * oR1.GetWidth()
         << endl;
    return 0;
}