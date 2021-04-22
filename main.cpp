#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int countLines(string pName);
int countChar(string pName);

int main(int argc, char **argv)
{
    //will get the string to be used for filename
    string fileName="";
    int numLines=0;
    int numChar=0;
    for(int i=1; i<argc;i++)
    {
        fileName=argv[i];
    }
    if(fileName=="")
    {
        numLines = countLines("Ohio University");
        numChar = countChar("Athens");
    }else
    {
        numLines = countLines(fileName);
        numChar = countChar(fileName);
    }
    cout << numLines << " Lines\n";
    cout << numChar << " Characters\n";
}

int countLines(string pName)
{
    int numLines=0;
    ifstream ins;
    ins.open(pName.c_str());
    string tmp = "empty";
    while(!ins.eof())
    {
        getline(ins, tmp);
        numLines++;
    }
    ins.close();
    return numLines;
}
int countChar(string pName)
{
    int numChar=0;
    ifstream ins;
    ins.open(pName.c_str());
    char tmp = 'a';
    while(!ins.eof())
    {
        //to ignore new lines
        if(ins.peek() == '\n' || ins.peek() == '\r'){
            numChar--;
        }
        ins>>tmp;
        numChar++;
    }
    ins.close();
    return numChar;
}