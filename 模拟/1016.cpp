#include <iostream>

using namespace std;

int main(){
    int t;
    int ps[21];
    int ws[21];
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>ps[j];
        for(int j=n-1;j>=0;j--)
            ps[j]-=ps[j-1];
        ws[0]=1;
        // ps[0]=0;
        for(int j=1;j<n;j++){
            int temp=0;
            for(int k=j;k>=0;k--){
                if(ps[k]>0){
                    ps[k]--;
                    temp++;
                    break;
                }
                else{
                    temp++;
                }
            }
            ws[j]=temp;
        }
        for(int j=0;j<n;j++){
            cout<<ws[j];
            if(j!=n-1)cout<<" ";
        }
        cout<<endl;
    }
}