#include <bits/stdc++.h>
using namespace std;
long long int vec[10000001];
long long int inversion(long long int l,
long long int r)
{
       long long int left,right;
       if(l>=r)
       {
           return 0;
       }
       if(r-l==1)
       {
           return 0;
       }
       long long int cnt=0;
       long long int mid=l+(r-l)/2;
	    left=inversion(l,mid);
	    right=inversion(mid,r);
	    long long int itrl=l,itrr=mid;
	   // vector<long long int >ans;
	    long long int ans[r-l];
	    long long int k=0;
	    while(itrl<mid && itrr<r)
	    {
	        if(vec[itrr]<vec[itrl])
	        {
	            cnt+=mid-itrl;
	            ans[k]=vec[itrr];
	           // ans.push_back(vec[itrr]);
	            itrr++;
	            k++;
	        }
	        else
	        {
	           // ans.push_back(vec[itrl]);
	           ans[k]=vec[itrl];
	           k++;
	            itrl++;
	        }
	    }
	    while(itrl<mid)
	    {
	         ans[k]=vec[itrl];
	           k++;
	       // ans.push_back(vec[itrl]);
	        itrl++;
	    }
	    
	    while(itrr<r)
	    {
	         ans[k]=vec[itrr];
	           k++;
	       // ans.push_back(vec[itrr]);
	        itrr++;
	    }
	    for(long long int i=l,j=0;i<r;i++,j++)
	    {
	        vec[i]=ans[j];
	        
	    }
	  
	    return cnt+left+right;
	    
}
int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>vec[i];
	    }
	    long long int ans=inversion(0,n);
	    cout<<ans<<endl;
	}
	return 0;
}