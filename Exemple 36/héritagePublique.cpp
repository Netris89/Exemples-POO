// CGeoShape has an embedded CPoint. CRectangle inherits
// from CGeoShape and calls base member functions.
#include <iostream>
/***** Declaration and Definition of CPoint Class *****/
using namespace std;

class CPoint
{
public: // construction
    CPoint(int dX = 0, int dY = 0)
        : m_dX(dX), m_dY(dY)
    {
        cout << "CPoint c'tor\n";
    }
    ~CPoint()
    {
        cout << "CPoint d'tor" << endl;
    }
    int Getx(void) { return m_dX; } // attributes
    int Gety(void) { return m_dY; }
    void Setx(int dX) { m_dX = dX; }
    void Sety(int dY) { m_dY = dY; }

private: // implementation
    int m_dX, m_dY;
};
/********** CGeoShape Class Declaration ***************
Base class for the 2-D geometrical classes CRectangle,
Ellipse, and Triangle. Dimensions do not make sense
for a generic shape, but a center point does.
*****************************************************/
class CGeoShape
{
public: // construction
    CGeoShape(CPoint oP = CPoint(0, 0));
    CGeoShape(int dX, int dY);
    ~CGeoShape();
    void SetCenter(CPoint oP); // attributes
    CPoint GetCenter(void);
    void Draw(void);  // operations
private:              // implementation
    CPoint m_oCenter; // CPoint is "embedded" in CGeoShape
};
/*********** CRectangle Class Declaration *************/
class CRectangle : public CGeoShape // Inheritance!
{
public: // construction
    CRectangle();
    CRectangle(int dH, int dW, CPoint oP = CPoint(50, 50));
    CRectangle(int dH, int dW, int dX, int dY);
    ~CRectangle();
    void Size(int dH, int dW); // operations
    void Draw(void);

private: // implementation
    int m_dHeight, m_dWidth;
};
/******* CGeoShape Member Function Definitions ********/
inline CGeoShape::CGeoShape(CPoint oP)
    : m_oCenter(oP)
{
    cout << "CGeoShape c'tor: 1 arg\n";
}
inline CGeoShape::CGeoShape(int dX, int dY)
    : m_oCenter(dX, dY)
{
    cout << "CGeoShape c'tor: 2 arg\n";
}
inline CGeoShape::~CGeoShape()
{
    cout << "CGeoShape d'tor" << endl;
}
inline void CGeoShape::SetCenter(CPoint p)
{
    m_oCenter = p;
}
inline CPoint CGeoShape::GetCenter(void)
{
    return m_oCenter;
}
/* Currently just a display function */
void CGeoShape::Draw(void)
{
    cout << "Center at x:" << m_oCenter.Getx()
         << " y:" << m_oCenter.Gety() << endl;
}
/******* CRectangle Member Function Definitions *******/
inline CRectangle::CRectangle()
    : m_dHeight(0), m_dWidth(0), CGeoShape(0, 0)
{
    cout << "CRectangle default c'tor\n";
}
inline CRectangle::CRectangle(int dH, int dW, CPoint oP)
    : m_dHeight(dH), m_dWidth(dW), CGeoShape(oP)
{
    cout << "CRectangle c'tor: 3 arg (int, int, Pt)\n";
}
inline CRectangle::CRectangle(int dH, int dW, int dX, int dY)
    : m_dHeight(dH), m_dWidth(dW), CGeoShape(dX, dY)
{
    cout << "CRectangle c'tor: 4 arg (all int's)\n";
}
inline CRectangle::~CRectangle()
{
    cout << "CRectangle d'tor" << endl;
}
void CRectangle::Size(int dH, int dW)
{
    m_dHeight = dH;
    m_dWidth = dW;
}
/* Currently just a display function */
void CRectangle::Draw(void)
{
    CGeoShape::Draw(); // :: used for qualification
    cout << " height:" << m_dHeight
         << " width:" << m_dWidth;
}
/**************** Small Test Program *****************/
void main()
{
    cout << "Create p:";
    CPoint oP(55, -55);
    cout << "Creating two generic objects:\n";
    CGeoShape oG1, oG2(12, -12);
    cout << "Creating three CRectangles:\n";
    CRectangle oR1(2, 4, 150, 150),
        oR2(10, 10, oP),
        oR3(55, 55);
    cout << "\n\"Draw\" two objects:\n";
    cout << "g1 draws as: \n";
    oG1.Draw();
    cout << "oR2 draws as: \n";
    oR2.Draw();
    cout << "\nEnding main()" << endl;
}