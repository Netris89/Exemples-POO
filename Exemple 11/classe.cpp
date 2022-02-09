#include "..\Exemple 06\ccomplex.cpp"

class CComplex
{
    public:
        CComplex();
        CComplex(double, double);
        double m_lfReel, m_lfImag;
} 
CComplex::CComplex()
{
    m_lfReel = 0;
    m_lfImag = 0;
}
CComplex::CComplex(double lfR, double lfI)
{
    m_lfReel = lfR;
    m_lfImag = lfI;
}