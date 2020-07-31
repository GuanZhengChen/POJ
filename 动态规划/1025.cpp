#include <iostream>
#include <algorithm>
using namespace std;

int l[5001];
int w[5001];
int dp[5001];
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>l[j]>>w[j];
        }
        for(int j=0;j<n;j++)
            dp[j]=1;
        int lb=l[0];
        int wb=w[0];
        int le=l[0];
        int we=w[0];
        for(int k=1;k<n;k++){
            if(l[k]<=l[0]&&w[k]<=w[0]){
                dp[k]=dp[k-1];
                // lb=l[k];
                // wb=w[k];
                swap(l[k],l[0]);
                swap(w[k],w[0]);
            }
            else if(l[k]>=le&&w[k]>=we){
                dp[k]=dp[k-1];
                // le=l[k];
                // we=w[k];
                // swap(l[k],l[0]);
                // swap(w[k],w[0]);
            }
            else{
                bool flag=false;
                for(int m=0;m<k-1;m++){
                    if((l[k]>=l[m]&&w[k]>=w[m])&&l[k]<=l[m+1]&&w[k]<=w[m+1]){
                        dp[k]=dp[k-1];
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    cout<<k<<endl;
                    dp[k]=dp[k-1]+1;
                }
            }
        }
        cout<<dp[n-1]<<endl;
    }
}