class CCell
{
    int m_dX, m_dY;

public:
    CCell(int, int);
    virtual ~CCell();
    {
    }
    virtual void display();
};
CCell::CCell(int dCoordX, int dCoordY) : m_dX(dCoordX), m_dY(dCoordY)
{
    M_dX = dCoordX;
}
void CCell::display()
{
    cout << "Dessiner une cellule";
}
class CTextCell : public CCell
{
    char *m_pTexte;

public:
    CTextCCell(const char *, int, int);
    ~CTextCCell();
    virtual void display();
} CTextCCell::CTextCell(const char *pContent, int dX, int dY) : CCell(dX,
                                                                      dY)
{
    m_pTexte = new char[(strlen(pContent) + 1)];
    strcpy(m_pTexte, pContent);
}
CTextCell::~CTextCell()
{
    delete[] m_pTexte;
}
void CTextCell::display()
{
    CCell::display();
    cout << m_pTexte << endl;
}
class CNumCell : public CCell
{
    float m_fNum;

public:
    CNumCell(float, int, int);
    ~CNumCell()
    {
    }
    virtual void display();
};
CNumCell::CNumCell(float fVal, int dX, int dY) : CCell(dX, dY)
{
    m_fNum = fVal;
}
CNumCell::display()
{
    CCell::display();
    cout << m_fNum << endl;
}
int main()
{
    const int dNbrCells = 5;
    CCell *tpSpreadS[dNbrCells];
    tpSpreadS[0] = new CNumCell(7.00, 1, 0);
    tpSpreadS[1] = new CNumCell(4.59, 3, 4);
    tpSpreadS[2] = new CNumCell(3.98, 2, 2);
    tpSpreadS[3] = new CTextCell("First", 4, 5);
    tpSpreadS[4] = new CTextCell("Second", 1, 1);
    for (dInd = 0; dInd < dNbrCells; dInd++)
    {
        tpSpreadS[dInd]->display();
        delete tpSpreadS[dInd];
    }
}