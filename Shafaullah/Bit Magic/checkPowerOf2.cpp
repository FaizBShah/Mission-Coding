#include <bits/stdc++.h>
using namespace std;

bool checkPowerOfTwo(int n){

if(n == 0)
    return false;
return (n & (n-1)) == 0 ;

}

int main(){
    int n;
    cin>>n;
    cout<<checkPowerOfTwo(n);
    return 0;
}