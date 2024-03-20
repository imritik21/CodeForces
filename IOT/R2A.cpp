#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    int row1, row2, col1, col2;
    for(int i = 0; i < n; i++) {
        int c = 0, r1 = -1, r2 = -1;
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == '*') {
                c++;
                if(r1 == -1) r1 = j;
                else r2 = j;
            }
        }
        if(c == 2) {
            col1 = r1;
            col2 = r2;
            row1 = i;
        } else if(c == 1) {
            row2 = i;
        }
    }
    if(arr[row2][col1] != '*') cout<<row2 + 1<<" "<< col1+1;
    else cout<<row2 + 1<<" "<<col2+1;

}
