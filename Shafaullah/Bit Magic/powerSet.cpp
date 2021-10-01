#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string s){
int len =s.length();
int power = pow(2,len);
for(int counter = 0; counter<power;counter++){
    for(int j=0;j<len;j++){
        if((counter & (1<<j)) != 0 ){
            cout<<s[j];
        }
    }
    cout<<endl;
}

}

int main(){
    string s;
    cin>>s;
    printSubsequence(s);
    return 0;
}