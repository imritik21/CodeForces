#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	cout << "Input number is " << num << endl;	// Writing output to STDOUT
    for(int k=0;k<num;k++)
		    cout<<"*";
        cout<<endl;
	for(int i=0;i<num-2;i++){
        for(int j=0;j<num-2-i;j++)
            cout<<" ";
        cout<<"*";
        cout<<endl;
	}

        for(int i=0;i<num;i++)
		cout<<"*";
}