#include<bits/stdc++.h>
using namespace std;

int main()
 {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    long long int sum=0,maxsum=0;
	    long long int arr[n];
	    vector<long long int > vec;
	    vector<long long int >vecsum;
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for(long long int i=0;i<n;i++)
	    {
	        sum=sum+arr[i];
	       // cout<<"sum="<<sum;
	        vec.push_back(arr[i]);
	        if(sum>=maxsum)
	        {
	            
	            vecsum=vec;
	            maxsum=sum;
	        }
	        if(sum<0)
	        {
	            vec.clear();
	            sum=0;
	        }
	        if(arr[i]<0)
	        {
	            sum=0;vec.clear();
	        }
	        
	    }
	    for(long long int i=0;i<vecsum.size();i++)
	    {
	        cout<<vecsum[i]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}