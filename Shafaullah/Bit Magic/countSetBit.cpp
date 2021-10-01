#include <bits/stdc++.h>
using namespace std;

bool countSetBit(int n, int pos){

int mask = (1<< pos);
    return (mask & n)> 0 ? 1: 0;

}

int main(){
    int n,i;
    cin>>n>>i;
    cout<<countSetBit(n, i-1);
    return 0;
}