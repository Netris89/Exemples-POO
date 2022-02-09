class CEnseignant;
class CScientifique;
double Sal(const CEnseignant *pEns, const CScientifique *pSci)
{
    return (pEns->m_lfSalaire + pSci->m_lfSalaire);
}
class CEnseignant
{
private:
    double m_lfSalaire;

public:
    friend double Sal(const CEnseignant *, const CScientifique *);
};
class CScientifique
{
private:
    double m_lfSalaire;

public:
    friend double Sal(const CEnseignant *, const CScientifique *);
};