#include <iostream>

using namespace std;

int one[26];
int two[26];
int three[26];
int main(){
    int m;
    int number=1;
    while(cin>>m&&m){
        char t;
        for(int i=0;i<m;i++){
            cin>>t;
            one[i]=(t-('A'+i)+m)%m;
        }
        for(int i=0;i<m;i++){
            cin>>t;
            two[i]=(t-('A'+i)+m)%m;
        }
        for(int i=0;i<m;i++){
            cin>>t;
            three[i]=(t-('A'+i)+m)%m;
        }
        int n;
        cin>>n;
        if(number!=1)
            cout<<endl;
        cout<<"Enigma "<<number<<":"<<endl;
        number++;
        for(int i=0;i<n;i++){
            int count1=0;
            int count2=0;
            int count3=0;
            int c1,c2,c3;
            string code;
            cin>>code;
            int len=code.length();
            for(int j=0;j<len;j++){
                for(int k=0;k<m;k++){
                    c1=(one[(k-count1+m)%m]+k)%m;
                    c2=(two[(c1-count2+m)%m]+c1)%m;
                    c3=(three[(c2-count3+m)%m]+c2)%m;
                    if(code[j]-'A'==c3)
                        cout<<char('a'+k);
                }
                count1++;
                if(count1==m){
                    count1=0;
                    count2++;
                    if(count2==m){
                        count2=0;
                        count3++;
                        if(count3==m){
                            count3=0;
                        }
                    }
                }
            }
            cout<<endl;
        }
    }


}