CChaine ::CChaine(const CChaine &oNew)
{
    m_dLen = oNew.m_dLen;
    m_pStr = new char[m_dLen + 1];
    assert(m_pStr != 0);
    strcpy(m_pStr, oNew.m_pStr);
}