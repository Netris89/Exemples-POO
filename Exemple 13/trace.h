class CTrace
{
private:
    char *m_pFct;
    static short m_dLevel;

public:
    CTrace();
    CTrace(char *);
    ~CTrace();
    static short GetLevel();
};