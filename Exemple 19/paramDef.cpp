// Functions that define default values for selected
// arguments streamline the interface and allow
// class users multiple variations
#include <iostream>
/************ CRectangle Class Declaration *************/
using namespace std;
class CRectangle
{
public:
    // This c'tor is equivalent to three c'tors
    CRectangle(int h, int w, int x = 0, int y = 0);
    ~CRectangle();
    void SetCenter(int, int);
    void SetSize(int, int);
    void Draw();

private:
    int m_dX, m_dY;
    int m_dHeight, m_dWidth;
};
/******* CRectangle Member Function Definitions ********/
CRectangle::CRectangle(int h, int w, int x, int y)
    : m_dHeight(h), m_dWidth(w), m_dX(x), m_dY(y)
{
    cout << "Rect c'tor\n";
}
CRectangle::~CRectangle()
{
    cout << "Rect d'tor\n";
}
void CRectangle::SetCenter(int dX, int dY)
{
    m_dX = dX;
    m_dY = dY;
}
void CRectangle::SetSize(int dH, int dW)
{
    m_dHeight = dH;
    m_dWidth = dW;
}
void CRectangle::Draw(void)
{ // Currently just a display function
    cout << "CRectangle at x:" << m_dX << " y:" << m_dY;
    cout << " height:" << m_dHeight
         << " width:" << m_dWidth;
}
/**************** Small Test Function *****************/
int main()
{
    CRectangle oR1(1, 2),      // default x and y as 0
        oR2(5, 6, 8),          // default y as 0
        oR3(10, 10, 100, 100); // no defaults
    // CRectangle oR5 (9, 9, , 40);// Error: improper syntax
    cout << "Displaying oR1:\n";
    oR1.Draw();
    cout << endl;
    oR1.SetSize(11, 12);
    oR1.SetCenter(-10, -10);
    cout << "Displaying oR1 after manipulation:\n";
    oR1.Draw();
    cout << endl;
    cout << "Displaying oR2:\n";
    oR2.Draw();
    cout << endl;
    cout << "Displaying oR3:\n";
    oR3.Draw();
    cout << endl;
    return 0;
}