#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int dp[101][101];
int b[101][101];
int main(){
    int t;
    cin>>t;
    int l1,l2;
    string str1,str2;
    int map[128];
    map['A']=0;  
    map['C']=1;  
    map['G']=2;  
    map['T']=3;  
    map['-']=4;  
    int score[5][5] =   
    {{5,-1,-2,-1,-3},  
    {-1,5,-3,-2,-4},  
    {-2,-3,5,-2,-2},  
    {-1,-2,-2,5,-1},  
    {-3,-4,-2,-1,0}};
    for(int k=0;k<t;k++){
        cin>>l1>>str1>>l2>>str2;
        memset(dp,0,sizeof(dp));
        int i;
        for(i=1;i<=l1;i++)
            dp[0][i]=dp[0][i-1]+score[4][map[str2[i-1]]];
        for(i=1;i<=l2;i++)
            dp[i][0]=dp[i-1][0]+score[map[str1[i-1]]][4];
        int m1,m2,m3;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                m1=dp[i-1][j]+score[map[str1[i-1]]][4];
                m2=dp[i][j-1]+score[4][map[str2[j-1]]];
                m3=dp[i-1][j-1]+score[map[str1[i-1]]][map[str2[j-1]]];
                dp[i][j]=max(max(m1,m2),m3);
            }
        }
        cout<<dp[l1][l2]<<endl;
    }
}