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
	    long long int start[n],finish[n];
	     for(long long int i=0;i<n;i++)
	    {
	       cin>>start[i];
	       
	        
	    }
	     for(long long int i=0;i<n;i++)
	    {
	       cin>>finish[i];
	       
	        
	    }
	    vector<pair<long long int ,long long int >> vec;
	    for(long long int i=0;i<n;i++)
	    {
	        vec.push_back(make_pair(finish[i],i));
	    }
	    sort(vec.begin(),vec.end());
	    long long int end=vec[0].first;
	    cout<<vec[0].second+1<<" ";
	    for(long long int i=1;i<n;i++)
	    {
	        long long int comp=vec[i].second;
	        comp=start[comp];
	        if(comp>=end)
	        {
	            cout<<vec[i].second+1<<" ";
	            end=vec[i].first;
	        }
	    }
	    cout<<endl;
	}
	
	return 0;
}
