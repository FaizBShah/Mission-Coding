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
	int t=0;
    cin>>t;
    while(t--)
    {
        int n,m,a=0;
        cin>>n>>m;
        vector<int>vec(n+1);
        for(int i=1;i<=m;i++)
        {
            int x=0;
            cin>>x;
            vec[x]++;
        }
        vector<int>chef,assis;
        for(int i=1;i<=n;i++)
        {
            if(vec[i]==0)
            {
                a++;
                if(a%2==1)
                    chef.push_back(i);
                else
                    assis.push_back(i);
            }
        }
        for(int i=0;i<chef.size();i++)
        {
            cout<<chef[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<assis.size();i++)
        {
            cout<<assis[i]<<" ";
        }
        cout<<"\n";
    }   
	return 0;
}
