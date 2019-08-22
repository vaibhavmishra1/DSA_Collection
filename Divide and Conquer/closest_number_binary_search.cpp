#include <iostream>
using namespace std;
int binary(int arr[],int l,int r,int k)
{
    if(r-l==0)
    {
        return arr[l];
    }
    if(r-l==1)
    {
        if(arr[r]-k>k-arr[l])
        {
            return arr[l];
        }
        
        if(arr[r]-k<=k-arr[l])
        {
            return arr[r];
        }
    }
    int mid=l+(r-l)/2;
    if(arr[mid]==k)
    {
        return arr[mid];
    }
    if(arr[mid]>k)
    {
        
        int ret=binary(arr,0,mid,k);
        return ret;
    }
    
    if(arr[mid]<k)
    {
        int ret=binary(arr,mid,r,k);
        return ret;
    }
}
int main() {
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    
	}
	
	
	int ret=binary(arr,0,n-1,k);
	cout<<ret<<endl;
	return 0;
}
