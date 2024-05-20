class Solution{
public:
    int factorCnt(int n){
        int cnt=0,m=sqrt(n);
        for(int i=1;i<=m;i++){
            if(n%i==0){
                cnt++;
                if(i!=(n/i)) cnt++;
            }
            // else cnt++;
        }
        return cnt;
    }
    int count(int A,int B,int N){ 
        // code here
        int cnt=0;
        for(int i=A;i<=B;i++){
            if(factorCnt(i)==N){
                cnt++;
            }
        }
        return cnt;
    }
};