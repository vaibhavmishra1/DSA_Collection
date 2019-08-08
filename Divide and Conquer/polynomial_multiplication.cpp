#include <bits/stdc++.h>
using namespace std;
long long int ans[10000];
long long int maxm=-1;
#define ll long long
void bruteforce(ll arr1[],ll arr2[],ll l1,ll r1,ll l2,ll r2)
{
    for(ll i=l1;i<r1;i++)
    {
        for(ll j=l2;j<r2;j++)
        {
            ans[i+j]=ans[i+j]+arr1[i]*arr2[j];
            
            if(i+j>maxm)
            {
                maxm=i+j;
            }
        }
    }
    return ;
}
void divide(ll arr1[],ll arr2[],ll l1,ll r1,ll l2,ll r2)
{
    ll mid1,mid2;
    mid1=l1+(r1-l1)/2;
    mid2=l2+(r2-l2)/2;
    if(r2-l2<2 || r1-l1<2)
    {
        bruteforce(arr1,arr2,l1,r1,l2,r2);
        return;
    }
    divide(arr1,arr2,l1,mid1,l2,mid2);
    divide(arr1,arr2,l1,mid1,mid2,r2);
    divide(arr1,arr2,mid1,r1,l2,mid2);
    divide(arr1,arr2,mid1,r1,mid2,r2);
    
}
int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int m,n;
	    cin>>m>>n;
	     for(ll i=0;i<=10000;i++ )
	    {
	        ans[i]=0;
	    }
	    maxm=-1;
	    long long int arr1[m],arr2[n];
	    for(ll i=0;i<m;i++ )
	    {
	        cin>>arr1[i];
	    }
	    for(ll i=0;i<n;i++ )
	    {
	        cin>>arr2[i];
	    }
	    divide(arr1,arr2,0,m,0,n);
	    for(ll i=0;i<maxm+1;i++)
	    {
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}