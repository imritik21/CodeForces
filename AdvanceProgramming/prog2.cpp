#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ofstream outFile("hello.txt");
    outFile<<"Hello my name is Ritik Shankar and i live in patia,Bhubaneshwar\n";
    outFile.close();

    // now read from file
    ifstream inFile("hello.txt");
    string line,name,add;

    if(inFile.is_open()){
        while(getline(inFile,line)){
            if(line.find("name is")!=std::string::npos){
                name = line.substr(line.find(" ")+1);
            }
            else if(line.find("live in")!=std::string::npos){
                add = line.substr(line.find(" ")+1);
            }
        }
        inFile.close();
    }
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<add<<endl;
    return 0;
}

//  append the conent of one file with another
// write a program to read a file to display the first and last statement of a file
// wap to read a file having the addition program in c modify to a mul program and saving the file
// modify one c file program with another c file program 
