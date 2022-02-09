// Uses block read and write operations to copy a
// file using binary mode.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#define SIZE 256

using namespace std;

void main()
{
    char data[SIZE];   // set i/o buffer size
    int nCount = SIZE; // bytes read, used for eof test
    // Create stream objects:
    ifstream infile;  // - input file stream
    ofstream outfile; // - output file stream
    // fstream flags:
    // ios::in open for input (default)
    // ios::nocreate if does not exist
    // ios::binary mode (default is text)
    infile.open("test.txt", ios::in | ios::binary);
    outfile.open("test.out", ios::out | ios::binary);
    // error checking
    if (!infile || !outfile)
    {
        cerr << "Error opening file(s)";
        exit(1);
    }
    // Loop reads up to 256 characters into data buffer.
    // Each read is size-verified to determine whether
    // end of file was reached.
    while (nCount == SIZE)
    {
        infile.read(data, SIZE);     // read up to SIZE
        nCount = infile.gcount();    // adj. actual size
        outfile.write(data, nCount); // update outfile
        if (outfile.rdstate() != ios::goodbit)
            cout << "Error writing file.\n";
    }
    cout << "File-to-file copy complete.\n";
    infile.close();  // close files (disconnect stream)
    outfile.close(); // or the D'tor will (good style)
}