CString CString::Substitute(char, char)
{
… } 
main()
{
    CString oRiviere("meuse");
    cout << oRiviere << oRiviere.Substitute('m', 'M');
    …
}