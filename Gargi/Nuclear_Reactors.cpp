#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
    #ifndef ONLINE_JUDGE 
        freopen("Input.txt", "r", stdin); 
        freopen("Output.txt", "w", stdout); 
    #endif
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	// your code goes here
    ll a,n,k;
    cin>>a>>n>>k;
    ll arr[k]={0};
    for(int i=1;i<=a;i++)
    {
        arr[0]++;
        for(int i=0;i<k;i++)
        {
            if(arr[i]<=n)
            break;
            arr[i]=0;
            arr[i+1]++;
        }
    }
    for(int i=0;i<k;i++)
    cout<<arr[i]<<" ";
    return 0;
}