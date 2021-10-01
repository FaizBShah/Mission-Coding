#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern){
            count++;
        }
    return count;
}

int maxAND(int arr[], int N)
{
    // Your code here
    int res = 0,count;
    int maxEl = *max_element(arr, arr + N);
    int bit = log2(maxEl);
    for (; bit >= 0; bit--)
    {

         count = checkBit(res | (1 << bit),arr,N);
        if (count > 1)
        {
            res = res | (1 << bit);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxAND(arr, n);
    return 0;
}