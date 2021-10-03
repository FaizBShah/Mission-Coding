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
    ll t;
    cin>>t;
    while(t--)
    {
        ll D,d,p,q;
        cin>>D>>d>>p>>q;
        ll quo=D/d;
        ll ans= ((quo*p)+(q*(quo*(quo-1))/2))*d;
        ll s = D - d*quo;
        if(s>0)
        {
            ans+= s*(p + q*(D/d));
        }
        cout<<ans<<"\n";
    }
    return 0;
}