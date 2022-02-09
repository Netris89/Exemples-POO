#include <iostream>
#include <cassert>
#include <cstring>
#include "trace.h"

using namespace std;

short CTrace::m_dLevel = 0; 
// Obligatoirement dans le .CPP afin d’éviter la
// double inclusion dans les 2 fichiers .CPP.
// Le mécanisme de protection d’inclusion marche
// uniquement pour la compilation d’un fichier
// source !
CTrace::CTrace(char *pNom)
{
    m_pFct = (char *) malloc (sizeof(char) * (strlen(pNom) + 1));
    if (m_pFct == NULL)
    assert(0);
    strcpy(m_pFct, pNom);
    m_dLevel++;
    for (int dI = 0 ; dI < m_dLevel ; dI++)
    cerr << "-";
    cerr << "Entering " << m_pFct << endl;
}
CTrace::CTrace()
{
}
short CTrace::GetLevel()
{
    return (m_dLevel);
}
CTrace::~CTrace()
{
    for (int dI = 0; dI < m_dLevel; dI++)
        cerr << "-";
    cerr << "Exiting " << m_pFct <<  "[" << m_dLevel << "]" << endl;
    m_dLevel--;
    free(m_pFct);
}