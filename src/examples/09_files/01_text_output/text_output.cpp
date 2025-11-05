#include "text_output.h"

using std::ofstream; using std::cout;
using std::ifstream; using std::string; using std::getline;

void output_to_file()
{
    cout<<"Create file object\n";
    ofstream outFile;
    cout<<"Open the file\n";
    outFile.open("example.dat");

    cout<<"Write to file\n";

    outFile<<"Write line to file\n";
    outFile<<"Write another line to file\n";
    outFile<<"Write another line to file\n";

    cout<<"Close the file\n";
    outFile.close();
}

void read_from_file()
{
    cout<<"Open file object\n";

    string line;//represent a line read from the file
    
    cout<<"Open the file\n";
    ifstream inFile;
    inFile.open("example.dat");

    if(inFile.is_open())
    {
        cout<<"Read from the file\n";

        while(getline(inFile, line))
        {
            cout<<line<<"\n";
        }
        
        cout<<"Close the file\n";
        inFile.close();
    }
    else
    {
        cout<<"Unable to open the file\n";
    }

}