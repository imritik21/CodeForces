/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int N,K;
	    cin>>N>>K;
	    int eachShare=N/(K+1);
	    int myNetPay=N-(eachShare*K);
	    cout<<myNetPay<<endl;
	}
	return 0;
}
/*#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int N,res;
	    int A[N],B[N],max[0];
	    cin>>N;
	    // types
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    
	    // nutrition val
	    for(int i=0;i<N;i++){
	        cin>>B[i];
	    }
	    // max ele in b if a is same
	    for(i = 0;i < N; i++) {
        // Change < to > if you want to find the smallest element
        if(max[0] < max[i])
            max[0] = max[i];
        }
	    // if A is same
	    bool allSame = true;
        for (int i = 0; i < N; i++) 
        {
            if (A[i] !=A[0]) {
            allSame = false;
            break;
            }
        }
        if (allSame) {
            // 
            int res=max[0];
            break;
        }
	}
	return 0;
}
*/

