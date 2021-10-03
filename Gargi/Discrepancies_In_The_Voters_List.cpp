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
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    map <int,int> mp;
    for(int i=0;i<n1+n2+n3;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<int> v1;
	map<int,int>::iterator itr;
	for (itr = mp.begin(); itr != mp.end(); itr++)
	{
		if(itr -> second >= 2)
		v1.push_back(itr->first);
	}
	sort(v1.begin(),v1.end());
	cout << v1.size() << endl;
	for (int i = 0; i < v1.size(); ++i)
	cout << v1[i] << endl;
    return 0;
}