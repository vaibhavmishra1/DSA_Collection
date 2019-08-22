#include<bits/stdc++.h>
using namespace std;
int findright(int arr[],int l,int r,int k,int n)
{
    int mid=l+(r-l)/2;
    if(mid==n-1)
    {
        return mid;
    }
    if(arr[mid]==k && arr[mid+1]!=k)
    {
        return mid;
    }
    int val=r;
    if(arr[mid]!=k)
    {
    val=findright(arr,l,mid,k,n);
    }
    else if(arr[mid]==k and arr[mid+1]==k)
    {
        val=findright(arr,mid,r,k,n);
    }
    return val;
    
}




int findleft(int arr[],int l,int r,int k,int n)
{
    int mid=l+(r-l)/2;
    if(mid==0)
    {
        return mid;
    }
    if(arr[mid]==k && arr[mid-1]!=k)
    {
        return mid;
    }
    int val=r;
    if(arr[mid]!=k)
    {
    val=findleft(arr,mid,r,k,n);
    }
    else if(arr[mid]==k and arr[mid+1]==k)
    {
        val=findleft(arr,l,mid,k,n);
    }
    return val;
    
}
int main()
 {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    int arr[n];
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int k;
	    cin>>k;
	    int mid=n/2;
	    
	    int r=findright(arr,mid,n,arr[mid],n);
	    int l=findleft(arr,0,mid,arr[mid],n);
	    
	    int ans=r-l+1;
	    if(ans>n/2){
	        cout<<"True"<<endl;
	    }
	    else
	    {
	        cout<<"False"<<endl;
	    }
	}
	
	return 0;
}
