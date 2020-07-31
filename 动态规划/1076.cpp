#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
struct pairs{
    int bpos;
    int epos;
    int pos;
};
bool comp(const pairs& p1,const pairs& p2){
    if(p1.bpos==p2.bpos)return p1.epos<p2.epos;
    else return p1.bpos<p2.bpos;
}
pairs data[1005];
int dp[1005];
int b1[1005];
stack<int>result;
int main(){
    int n;
    int b,e;
    while(cin>>n&&n){
        while(!result.empty())result.pop();
        for(int i=1;i<=n;i++){
            cin>>b>>e;
            data[i]={b,e,i};
        }
        sort(data+1,data+n+1,comp);
        dp[0]=0;
        int maxpos=-1;
        int maxval=0;
        memset(b1,0,sizeof(b1));
        // dp[1]=1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++){
                if(data[i].bpos>data[j].epos){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        b1[i]=j;
                    }
                }
            }
            if(dp[i]>maxval){
                maxval=dp[i];
                maxpos=i;
            }
        }
        while(maxpos>0){
            result.push(data[maxpos].pos);
            maxpos=b1[maxpos];
        }
        while(!result.empty()){
            cout<<result.top();
            if(result.size()>1)cout<<" ";
            result.pop();
        }
        cout<<endl;
    }
    return 0;
}