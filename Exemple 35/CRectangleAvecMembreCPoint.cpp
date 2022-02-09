// Classes that contain classes use embedding.
#include <iostream>
/******************* CPoint Class *********************
Declaration and definition since the CPoint class has
only implicitly inline member functions.
*****************************************************/
using namespace std;

class CPoint
{
public: // construction
    CPoint(int x = 0, int y = 0)
        : m_dX(x), m_dY(y)
    {
        cout << "CPoint c'tor\n";
    }
    ~CPoint()
    {
        cout << "CPoint d'tor" << endl;
    }
    // attributes
    int Getx(void) { return m_dX; }
    int Gety(void) { return m_dY; }
    void Setx(int x) { m_dX = x; }
    void Sety(int y) { m_dY = y; }

private: // implementation
    int m_dX, m_dY;
};
/*********** CRectangle Class Declaration *************/
class CRectangle
{
public: // construction
    // Default c'tor creates "point" rect's at 0,0
    CRectangle();
    // 3-arg c'tor (default arg) may invoke CPoint
    // c'tor (and its default copy c'tor) to build
    // a CPoint object at 50,50
    CRectangle(int h, int w, CPoint oP = CPoint(50, 50));
    CRectangle(int h, int w, int x, int y);
    ~CRectangle();
    // attributes
    void SetCenter(CPoint oP);
    CPoint GetCenter(void);
    // implementation
    void Size(int nh, int nw);
    void Draw(void);

private:
    CPoint m_oCenter;
    int m_dHeight, m_dWidth;
};
/******* CRectangle Member Function Definitions *******/
inline CRectangle::CRectangle()
    : m_dHeight(0), m_dWidth(0), m_oCenter(0, 0)
{
    cout << "CRectangle default c'tor\n";
}
inline CRectangle::CRectangle(int h, int w, CPoint oP)
    : m_dHeight(h), m_dWidth(w), m_oCenter(oP)
{
    cout << "CRectangle c'tor: 3 args (int, int, pt)\n";
}
inline CRectangle::CRectangle(int h, int w, int x, int y)
    : m_dHeight(h), m_dWidth(w), m_oCenter(x, y)
{
    cout << "CRectangle c'tor: 4 args (all int's)\n";
}
inline CRectangle::~CRectangle()
{
    cout << "CRectangle d'tor" << endl;
}
inline void CRectangle::SetCenter(CPoint oP)
{
    m_oCenter = oP;
}
inline CPoint CRectangle::GetCenter(void)
{
    return m_oCenter;
}
void CRectangle::Size(int nh, int nw)
{
    m_dHeight = nh;
    m_dWidth = nw;
}
// Currently just a display function
void CRectangle::Draw(void)
{
    cout << "CRectangle at x:" << m_oCenter.Getx()
         << " y:" << m_oCenter.Gety();
    cout << " height:" << m_dHeight
         << " width:" << m_dWidth;
}
/**************** Simple Test Function ***************/
int main()
{
    cout << "Create oP1:"; // Create a CPoint, oP1, at
    CPoint oP1(25, 35);    // coordinates 25,35
    cout << endl;
    cout << "Create oR1:"; // Creating oR1 creates a
    CRectangle oR1;        // CPoint default center 0,0
    cout << endl;
    cout << "Create oR2:";     // Create oR2 using oP1 obj
    CRectangle oR2(1, 2, oP1); // for center at 25,35
    cout << endl;
    cout << "Create oR3:";      // Create oR3 passing
    CRectangle oR3(8, 8, 9, 9); // c'tor 9, 9 for CPoint
    cout << "\nNow leaving main()\n";
/* Note:
    The destruction order of non - embedded objects
                                       with respect to each other is not guaranteed.return 0; */
}