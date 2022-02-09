#include <iostream>

using namespace std;

class CRational
{
    friend ostream &operator<<(ostream &, const CRational &);

public:
    CRational(int dN = 0, int dD = 1) : m_dNum(dN), m_dDen(dD)
    {
    }
    int operator[](int);

private:
    int m_dNum, m_dDen;
};
int CRational::operator[](int dI)
{
    if (dI == 1)
        return m_dNum;
    if (dI == 2)
        return m_dDen;
    cerr << "ERREUR : index hors limite)";
    exit(1);
}
main()
{
    CRational oX(22, 7);
    cout << " X = " << oX << endl;
    cout << " X[1] = " << oX[1] << " , X[2] = " << oX[2] << endl;
}
/* Résultat : X = 22 / 7;
X[1] = 22, X[2] = 7 */