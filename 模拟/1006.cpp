#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char ciphertext[70];
    char plaintext[70];
    // string ciphertext,plaintext;
    int ciphercode[70];
    int plaincode[70];
    int key;
    while(scanf("%d%s",&key,ciphertext)&&key){
        int n=strlen(ciphertext);
        for(int i=0;i<n;i++){
            if(ciphertext[i]=='_')
                ciphercode[i]=0;
            else if(ciphertext[i]=='.')
                ciphercode[i]=27;
            else
                ciphercode[i]=ciphertext[i]-'a'+1;
            int j=key*i%n;
            plaincode[j]=(ciphercode[i]+i)%28;
            if(plaincode[j]==0)
                plaintext[j]='_';
            else if(plaincode[j]==27)
                plaintext[j]='.';
            else
                plaintext[j]=(char)plaincode[j]+'a'-1;
        }
        printf("%s\n",plaintext);
    }
    return 0;
}