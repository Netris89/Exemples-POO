#include "..\Exemple 06\ccomplex.cpp"

CComplex CComplex::operator+(CComplex Ocplx)
{
    CComplex oTemp;
    oTemp.m_lfReel = m_lfReel + oCplx.m_lfReel;
    oTemp.m_lfImag = m_lfImag + oCplx.m_lfImag;
    return oTemp;
}
int main()
{
    CComplex oCplxA(1.0, 2.0); // Constructeur
    CComplex oCplxB(2.0, 3.0);
    CComplex oCplxC = oCplxA + oCplxB; // Opérateurs + et =
}