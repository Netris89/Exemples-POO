#include <iostream>

using namespace std;

class CRational
{
    friend ostream &operator<<(ostream &, const CRational &);

public:
    CRational(int n = 0, int d = 1) : m_dNum(n), m_dDen(d)
    {
    }
    CRational operator++();

private:
    int m_dNum, m_dDen;
};
CRational CRational::operator++()
{
    m_dNum += m_dDen;
    return *this;
}
main()
{
    CRational oX(22, 7), oY = ++oX;
    cout << "Y = " << oY << " , X = " << oX << endl;
}
//Y = 29 / 7, x = 29 / 7