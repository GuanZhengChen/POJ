#include <iostream>
#include <cstring>
using namespace std;


int fun(int x)
{
    return x>0? x:0;
}
int main(){
    int n;
    int w[3],s[3],d[3],c[3];
    int x[101],y[101];
    int f[2][501][501];
    memset(f,0,sizeof(f));
    int count=1;
    while(cin>>n&&n){
        int dall;
        scanf("%d%d%d",&w[0],&s[0],&d[0]);
        scanf("%d%d%d",&w[1],&s[1],&d[1]);
        scanf("%d%d%d",&w[2],&s[2],&d[2]);
        scanf("%d%d%d%d",&c[0],&c[1],&c[2],&dall);
        for(int i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        int x1=0;
        int x2=0;
        int x3=0;
        int prev=0;
        int now=1;
        int n1,n2;
        int tt;
        for(int i=0;i<n;i++){
            memset(f[now],-1,sizeof(f[now]));
            int a,b,c;
            n1=min(x[i]/w[0],y[i]/s[0]);
            for(a=0;a<=n1;a++){
                n2=min((x[i]-a*w[0])/w[1],(y[i]-a*s[0])/s[1]);
                if(a==0)tt=n2;
                for(b=0;b<=n2;b++){
                    c=min((x[i]-a*w[0]-b*w[1])/w[2],(y[i]-a*s[0]-b*s[1])/s[2]);
                    if(i==0)f[now][a][b]=c;
                    else
                    {
                        for(int k=0;k<=x1;k++){
                            for(int l=0;l<=x2;l++){
                                if(f[prev][k][l]!=-1)
                                    f[now][k+a][l+b]=max(f[now][k+a][l+b],f[prev][k][l]+c);
                            }
                        }
                    }
                }
            }
            x1+=n1;
            x2+=tt;
            swap(prev,now);
            // for(int k1=0;k1<a;k1++){
            //     for(int k2=0;k2<b;k2++){
            //         f[0][k1][k2]=f[1][k1][k2];
            //     }
            // }
        }
        int result=0;
         for(int i=0;i<=x1;i++)
            for(int j=0;j<=x2;j++)
            {
                if(f[prev][i][j]!=-1)
                {
                    int groupNum=65535; //max
                    if(c[0]!=0)
                        groupNum=min(i/c[0],groupNum);
                    if(c[1]!=0)
                        groupNum=min(j/c[1],groupNum);
                    if(c[2]!=0)
                        groupNum=min(groupNum,f[prev][i][j]/c[2]);
                    result=max(result,fun(i-groupNum*c[0])*d[0]+fun(j-groupNum*c[1])*d[1]+fun(f[prev][i][j]-groupNum*c[2])*d[2]+groupNum*dall);
                    // 开始没有加fun函数，没有考虑到i-groupNum等小于0;
                }
            }
        if(count>1)cout<<endl<<endl;
        cout<<"Case "<<count++<<": "<<result;

    }
    return 0;
}