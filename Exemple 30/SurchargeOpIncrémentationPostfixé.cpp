#include <iostream>

using namespace std;

class CRational
{
    friend ostream &operator<<(ostream &, const CRational &);

public:
    CRational(int dN = 0, int dD = 1) : m_dNum(dN), m_dDen(dD)
    {
    }
    CRational operator++();
    CRational operator++(int);

private:
    int m_dNum, m_dDen;
};
CRational CRational::operator++()
{
    m_dNum += m_dDen;
    return *this;
}
CRational CRational::operator++(int)
{
    CRational oTemp = *this;
    m_dNum += m_dDen;
    return oTemp;
}
main()
{
    CRational oX(22, 7), oY = oX++;
    cout << "Y = " << oY << " , X = " << oX << endl;
}
//Résultat : Y = 22 / 7, x = 29 / 7