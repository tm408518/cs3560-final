#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int countLines(string pName);
int countChar(string pName);
/***
 * main: contains logic to load in the argument with the executable
 * argc: the number of arguments
 * argv: char containing the argument, i.e. our fileName
 * **/
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
    //here, begin catch2 based testing required by instructor
    //Assert::That(countChar("test.txt"), Equals(22));
}
/****
 * countLines: function which will count the number of characters in a given  file
 * string pName: will contain a string, being the name of a file
 * **/
int countLines(string pName)
{
    int numLines=0;
    ifstream ins;
    ins.open(pName.c_str());
    if(ins.fail()){
        cout<<"invalid file name\n";
        return 0;
    }
    string tmp = "empty";
    while(!ins.eof())
    {
        getline(ins, tmp);
        numLines++;
    }
    ins.close();
    return numLines;
}
/****
 * countChar: function which will count the number of characters in a given  file
 * string pName: will contain a string, being the name of a file
 * **/
int countChar(string pName)
{
    int numChar=0;
    ifstream ins;
    ins.open(pName.c_str());
    if(ins.fail()){
        cout<<"invalid file name\n";
        return 0;
    }
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
    numChar++;
    ins.close();
    return numChar;
}