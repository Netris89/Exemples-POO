template <typename T, typename U>
void fct(T a, T *b, U c)
{
    T x;
    U *adr;
    … adr = new U[10];
    … N = sizeof(T);
    …
}
int dN, dP;
float fX;
char c;
int *pAdi;
float *pAdf;
CPoint oP, *pP;
fct(dN, pAdi, fX); // instancie la fonction void fct (int, int *, float)
fct(dN, pAdi, pP); // instancie la fonction void fct (int, int *, CPoint*)
fct(fX, pAdf, pP); // instancie la fonction void fct (float, float *, CPoint*)
fct(c, pAdi, fX);  // erreur car char et int * ne correspondent pas à T et
// T *
fct(&dN, &pAdi, fX); // instancie la fonction void fct (int*, int**, float)
fct(*pP, pP, dN);    // instancie la fonction void fct (CPoint,CPoint*, int)