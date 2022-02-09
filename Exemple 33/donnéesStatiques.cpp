#include <iostream>

using namespace std;

class CRectangle
{
    CRectangle()
    {
        m_dCount++;
    }
    ~CRectangle()
    {
        m_dCount--;
    }
    int getCount()
    {
        return m_dCount;
    }

private:
    static int m_dCount;
};
int CRectangle::m_dCount;
main()
{
    CRectangle oW, oX;
    cout << "Il y a maintenant " << oW.getCount() << "CRectangles\n";
}