#include <iostream>

using namespace std;

class CRational
{
    friend ostream &operator<<(ostream &, const CRational &);

public:
    CRational(int n = 0, int d = 1) : m_dNum(n), m_dDen(d)
    {
    }
    int operator[](int);
    CRational &operator=(const CRational &);

private:
    int m_dNum, m_dDen;
};
CRational &CRational::operator=(const CRational &oR)
{
    m_dNum = oR.m_dNum;
    m_dDen = oR.m_dDen;
    return *this;
};