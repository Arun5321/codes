#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,cur=0;
    cin>>n;
    int a[n];
     for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(i=0;i<n;i++)
    {
        cur=0;
        for(int j=i;j<n;j++)
        {
            cur+=a[j];
            cout<<cur<<endl;
        }
    }
}