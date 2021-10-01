#include <bits/stdc++.h>
using namespace std;

int main() 
{
	#ifndef ONLINE_JUDGE 
        freopen("Input.txt", "r", stdin); 
        freopen("Output.txt", "w", stdout); 
    #endif
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,k,n;
        cin>>x>>y>>k>>n;
        int flag=0;
        for(int i=0; i<n; i++)
        {
            int pages,cost;
            cin>>pages>>cost;
            if(pages>=(x-y) && cost<=k)
            {
                flag=1;
            }
        }
        if(flag)
            cout<<"LuckyChef";
        else
            cout<<"UnluckyChef";
        cout<<endl;
    }
	return 0;
}
