{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/* The function should return the index of any
   peak element present in the array */
// arr: input array
// n: size of array
int find(int arr[],int l,int r,int n)
{
    int mid=l+(r-l)/2;
    int k;
    if(mid>0)
    {
        if(mid<n-1)
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
        }
        else
        {
            if(arr[mid]>arr[mid-1])
            {
                return mid;
            }
        }
    }
    else
    {
            if(arr[mid]>arr[mid+1])
            {
                return mid;
            }
        
    }
    if(mid>0)
    {
        if(arr[mid]<arr[mid-1])
        {
            k=find(arr,l,mid,n);
        }
        
    }
    
    if(mid<n-1)
    {
        if(arr[mid]<arr[mid+1])
        {
             k=find(arr,mid,r,n);
        }
        
    }
    return k;
}
int peakElement(int arr[], int n)
{
    int k=find(arr,0,n,n);
    return k;
   // Your code here
}
