#include <iostream>

using namespace std;

class CRational
{
    friend istream &operator>>(istream &, CRational &);
    friend ostream &operator<<(ostream &, const CRational &);

public:
    CRational(int n = 0, int d = 1) : m_dNum(n), m_dDen(d)
    {
    }
    operator double() const;

private:
    int m_dNum, m_dDen;
};
CRational::operator double() const
{
    return double(m_dNum) / m_dDen;
}
main()
{
    CRational oX(-5, 8);
    cout << " X = " << oX << ", double (X) = " << double(oX);
    const CRational oP(22, 7);
    const double lfPI = double(oP);
    cout << "P = " << oP << ", PI = " << lfPI;
}
//X = -5 / 8, double(X) = -0.625 P = 22 / 7, PI = 3.14286