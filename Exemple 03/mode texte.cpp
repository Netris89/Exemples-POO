// The application reads text files by char, word, and
// line. It duplicates the input file, creating a
// line-numbered file with the extension ".out".
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#define SIZE 256

using namespace std;

void main()
{
    int nCntChars, nCntWords, nCntLines;
    char data[SIZE], ch;
    // Create stream objects using constructors:
    ifstream infile("test.txt", ios::in);
    ofstream outfile("test.out", ios::out);
    if (!infile || !outfile)
    {
        cerr << "Error opening file(s)";
        exit(1);
    }
    /*********** 'char' pass thru input file **********/
    for (nCntChars = 0; infile.get(ch); ++nCntChars)
        ;
    cout << "Input file contained " << nCntChars
         << " characters, ";
    // reset infile for 'word' pass
    infile.clear();             // reset eof state
    infile.seekg(0L, ios::beg); // seek to 0-byte
    /*********** 'word' pass thru input file **********/
    nCntWords = 0;
    while (infile >> data)
        ++nCntWords;
    cout << nCntWords << " words, ";
    // reset infile for 'line' pass
    infile.clear();   // reset eof
    infile.seekg(0L); // seek (default ios::beg)
    /*********** 'line' pass thru input file **********/
    for (nCntLines = 1; infile.getline(data, SIZE);
         ++nCntLines)
    {
        outfile.width(3);             // set width for line #
        outfile << nCntLines << ". "; // insert line #
        outfile << data << endl;      // insert line to file
    }
    cout << --nCntLines << " lines.\n";
    cout << "File-to-file number copy complete.\n\n";
    infile.close();  // close files (disconnect stream)
    outfile.close(); // or the d'tor will (good style!)
    cout << "*** Brain Teaser ***\n";
    cout << " get.(c) reports " << nCntChars
         << " chars.\n";
    cout << "getline.(*) reports " << nCntLines
         << " lines.\n";
    cout << "But, dir cmd shows: "
         << nCntChars + nCntLines << " size.\n";
    cout << "*** Q: Why the difference? ***\n";
}