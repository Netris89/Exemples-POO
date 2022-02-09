// Includes default constructor and destructor
#include <iostream>
/************ CRectangle Class Declaration *************/
// Interface to x and y coordinates not yet implemented.
using namespace std;

class CRectangle // FIXME: CRectangle au lieu de CCRectangle
{
public:                  // Construction section:
    CRectangle();        // constructor (no return value)
    ~CRectangle();       // destructor (no args, no ret)
    void SetHeight(int); // Attributes section:
    void SetWidth(int);
    long GetArea(void);

private: // Implementation section:
    int m_dHeight, m_dWidth;
};
/************ CRectangle Member Functions **************/
CRectangle::CRectangle() // Definition of constructor
{                          // name matches class name
    cout << "CRectangle c'tor.\n";
    m_dHeight = 0; // Member functions have full
    m_dWidth = 0;  // access to data members.
} // C'tors never return a value!
CRectangle::~CRectangle() // Definition of destructor
{                           // ~ and class name
    cout << "CRectangle d'tor.\n";
}
void CRectangle::SetHeight(int dH)
{
    m_dHeight = dH;
}
void CRectangle::SetWidth(int dW)
{
    m_dWidth = dW;
}
long CRectangle::GetArea(void)
{
    return (long)m_dWidth * m_dHeight;
}
/**************** Small Test Program ******************/
int main()
{                    // When instantiating an object
    CRectangle oR1; // the constructor for that
    // class is called (no ()'s).
    /* Why no ()'s? To the compiler, this
    CRectangle oR2(); looks like a function prototype! */
    cout << "The initial area of CRectangle oR1 is "
         << oR1.GetArea() << endl;
    oR1.SetHeight(15); // Set attributes for oR1
    oR1.SetWidth(10);
    cout << "The area of CRectangle oR1 is "
         << oR1.GetArea() << endl;
    return 0; // Note: A call to the d'tor
}