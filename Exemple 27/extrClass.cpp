#include <iostream>

using namespace std;

ostream &operator<<(ostream &ostr, const CRational &r)
{
    return ostr << r.m_dNum << '/' << r.m_dDen;
}
class CRational
{
    friend ostream &operator<<(ostream &, const CRational &);

public:
    CRational(int n = 0, int d = 1) : m_dNum(n), m_dDen(d)
    {
    }

private:
    int m_dNum, m_dDen;
};
main()
{
    CRational oX(22, 7), oY(-3, 8);
    cout << "X = " << oX << " , Y = " << oY << endl;
}
//Résultat : X = 22 / 7, Y = -3 / 8