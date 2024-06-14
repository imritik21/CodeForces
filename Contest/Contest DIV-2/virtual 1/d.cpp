bool isSame(vector<int>&a,int n){
    for(int i=0;i+1<n;i++){
        if(a[i] != a[i+1]) return false;
    }
    return true;
}
int canYouMakeEqual(int n, vector<int> &a, vector<int> &b) {
    // Write your code here.
    if(isSame(a,n)) return 1;
    if(isSame(b, n)) return 1;
    if((a[0] != b[1]) && (a[1]!=b[0])&&(a[n-1]!=b[n-2])&&(b[n-1]!=a[n-2])) return 0;
    // case 2
    bool flag1 = true;
    bool flag2 = true;
    bool flag3 = true;
    bool flag4 = true;
    if(a[0]==b[1]){
        int ele = a[0];
        if(n==2) return 1;
        else{
            for(int i=2;i<n;i++){
                if(a[i]==ele || b[i]==ele) continue;
                else{
                    flag1=false;
                    break;
                }
            }
        }
    }
     if(a[1]==b[0]){
        int ele = a[1];
        if(n==2) return 1;
        else{
            for(int i=2;i<n;i++){
                if(a[i]==ele || b[i]==ele) continue;
                else{
                    flag2=false;
                    break;
                }
            }
        }
    }
     if(a[n-1]==b[n-2]){
        int ele = a[n-1];
        if(n==2) return 1;
        else{
            for(int i=n-1;i>=0;i--){
                if(a[i]==ele || b[i]==ele) continue;
                else{
                    flag3=false;
                    break;
                }
            }
        }
    }
     if(b[n-1]==a[n-2]){
        int ele = a[n-2];
        if(n==2) return 1;
        else{
            for(int i=n-1;i>=0;i--){
                if(a[i]==ele || b[i]==ele) continue;
                else{
                    flag4=false;
                    break;
                }
            }
        }
    }
    // if((flag1&&flag2)) return 1;
    // else if((flag3&&flag4)) return 1;
    if(flag4&&flag3&&flag2&&flag1) return 1;
    return 0;
}