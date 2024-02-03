#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n<3){
	        cout<<"NO"<<endl;
	    }
        else{
	    if(n%3==0 || n%3==4 && n%4==0 || n%4==3){
	        cout<<"YES"<<endl;
	    }
	    else
	    cout<<"NO";
        }
	}
	return 0;
}
