#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int matrix[105][105];
int dp[105];
int sum[105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    int result=-128;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            memset(sum,0,sizeof(sum));
            for(int k=1;k<=n;k++){
                for(int l=i;l<=j;l++)
                    sum[k]+=matrix[k][l];
            }
            for(int k=1;k<=n;k++){
                dp[k]=max(dp[k-1]+sum[k],sum[k]);
                result=max(result,dp[k]);
            }
        }
    }
    cout<<result<<endl;
    return 0;
}