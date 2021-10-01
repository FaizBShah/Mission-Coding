#include <bits/stdc++.h>
using namespace std;

void PrintTwoOddApper(int arr[], int n)
{

    int res1 = 0, res2 = 0, Xor = 0;
    int rightMostSetBit = 0;
    for (int i = 0; i < n; i++)
    {
        Xor ^= arr[i];
    }
    rightMostSetBit = Xor & ~(Xor - 1); // eg--->  00010000
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & rightMostSetBit) != 0)
            res1 = res1 ^ arr[i];
        else
        {
            res2 = res2 ^ arr[i];
        }
    }
    cout << res1 << " " << res2 << endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    PrintTwoOddApper(arr, n);
    return 0;
}