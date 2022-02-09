#include <iostream>

using namespace std;

istream &operator>>(istream &istr, CRational &oR)
{
    cout << "\t Numérateur : ";
    istr >> oR.m_dNum;
    cout << "\tDénominateur : ";
    istr >> oR.m_dDen;
    oR.reduce();
    return istr;
}
class CRational
{
    friend ostream &operator<<(ostream &, const CRational &);
    friend istream &operator>>(istream &, CRational &);

public:
    CRational(int n = 0, int d = 1) : m_dNum(n), m_dDen(d)
    {
    }

private:
    int m_dNum, m_dDen;
    void reduce();
};
main()
{
    CRational oX, oY;
    cin >> oX >> oY;
    cout << "X = " << oX << " , Y = " << oY << endl;
}
//Résultat : Numérateur : -10 Dénominateur : -24 Numérateur : 36 Dénominateur : -20 X = 5 / 12, Y = -9 / 5