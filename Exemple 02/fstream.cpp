#include <fstream> // For file stream support
#include <cctype>  // For character macro
#include <iostream>

using namespace std;

void FileCreate(); // prototype file functions
void FileUpdate();
void FileWrite();
int main(void)
{
    FileCreate(); // Create ofstream & output strings.
    FileUpdate(); // Read and append to an fstream.
    FileWrite();  // Get from cin, put to an ofstream.
    return 0;
}
// Creates a file, test.txt, and outputs two lines.
// Create disk file: test.txt. Note: the 2nd arg
// to the c'tor is the default: ios::out | ios::app
void FileCreate()
{
    ofstream outfile("test.txt");
    if (!outfile) // check for successful open
        cerr << "Cannot open 'test.txt' for output.\n";
    else
        outfile << "This is test data.\n"
                << "File will be closed at destruction.\n ";
                   cout
                << "File created.\n";
}
// Read an input file, test.txt, getting a character
// at a time, appends the files content as all capital
// letters at the end of the original file.
// fstream inherits input & output
void FileUpdate()
{
    int iCount = 0; // ::in input mode
    char data[100]; // ::app append additions
    fstream iofile("test.txt", ios::in | ios::app);
    if (!iofile) // error handling
        cerr << "Trouble opening file 'test.txt'. "
                "Function 'FileUpdate()' failed.\n";
    while (!iofile.eof())           // While data exists, load
        iofile.get(data[iCount++]); // data by char
    iofile.clear();                 // Clear eof error state
    iCount--;                       // Adjust for 'off by one'
    for (int j = 0; j < iCount; j++)
    { // Put uppercase char to file
        data[j] = (char)toupper(data[j]);
        iofile.put(data[j]);
        cout.put(data[j]); // Echo characters to cout
    }
    cout << "File appended.\n";
}
// Take user keyboard input and write characters
// to a file "test.out".
void FileWrite()
{
    char ch;
    ofstream outfile("test.out", ios::out);
    if (!outfile) // Detect error opening file
        return;
    cout << "Enter characters. "
         << "(Use Ctrl-Z and ENTER to Quit)\n";
    while (cin.get(ch))  // While data exists,
        outfile.put(ch); // put char to file.
    cin.clear();         // Clear eof error for cin
}
// What would happen without the line above?
// What if main() was changed to "cin" more data?