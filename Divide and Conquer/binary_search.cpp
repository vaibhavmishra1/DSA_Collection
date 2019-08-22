#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int l,int r,int k)
{   
    int mid=l+(r-l)/2;
    if(k==arr[mid]){
        return 1;
    }
    else if(r-l==0 || r-l==1){
        return -1;
    }
    int ans;
    if(arr[mid]>k){
       ans= binary_search(arr,0,mid,k);
        
    }
    else
    {
        ans=binary_search(arr,mid+1,r,k);
    }
    return ans;
    
}
int main()
 {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int ans=binary_search(arr,0,n,k);
	    cout<<ans<<endl;
	}
	
	return 0;
}
