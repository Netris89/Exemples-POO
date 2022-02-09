#include <iostream>

using namespace std;

class CX
{
public:
    CX()
    {
        m_pPtr = new int[2];
        cout << "X(). ";
    }
    virtual ~CX()
    {
        delete[] m_pPtr;
        cout << "~X().\n";
    }

private:
    int *m_pPtr;
};