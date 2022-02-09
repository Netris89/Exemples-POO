#include <iostream>
using namespace std;

class CRectangle // FIXME: Page 56
{
    public:
        int m_dLargeur;
        int m_dHauteur;
        CRectangle();
} 
CRectangle::CRectangle()
{
    cout << "exécution du constructeur";
    m_dLargeur = 0;
    m_dHauteur = 0;
}