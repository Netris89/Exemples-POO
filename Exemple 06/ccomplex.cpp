class CComplex
{
private:
    double m_lfReel, m_lfImag;

public:
    CComplex Set(double r, double i);
    void Print(void);
    CComplex Add(CComplex c);
    CComplex Sub(CComplex c);
};