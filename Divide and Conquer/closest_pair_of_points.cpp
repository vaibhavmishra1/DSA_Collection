#include <bits/stdc++.h>
using namespace std;
pair<long long int ,long long int > p,q;

float findans(vector<pair<long long int ,long long int >> vecx,long long int l,long long int r)
{
    if(r-l==1)
    {
        return FLT_MAX;
    }
    if(l-r==0)
    {
        return FLT_MAX;
    }
    long long int mid=l+(r-l)/2;
    float a=findans(vecx,0,mid);
    float  b=findans(vecx,mid,r);
    float d=0;
    d=min(a,b);
    vector<pair<long long int ,long long int > >vecy;
    for(long long int i=0;i<vecx.size();i++)
    {
        if(abs(vecx[i].first-vecx[mid].first)<d)
        {
            vecy.push_back(make_pair(vecx[i].second,vecx[i].first));
        }
    }
    sort(vecy.begin(),vecy.end());
    for(long long int i=0;i<vecy.size();i++)
    {
        for(long long int j=i+1;i+j<vecy.size(),j-i<=7;j++)
        {
            float euc=0;
            euc=pow(abs(vecy[j].first-vecy[i].first),2)+pow(abs(vecy[j].second-vecy[i].second),2);
            euc=pow(euc,0.5);
            if(euc<d)
            {d=euc;}
        }
    }
    cout<<"D="<<d<<endl;
    return d;
}

int main() {
	long long int n;
	cin>>n;
	vector<pair<long long int ,long long int >> vecx;
	vector<pair<long long int ,long long int >> vecxtmp;
	
	long long int a,b;
	for(long long int i=0;i<n;i++)
	{
	    cin>>a>>b;
	    vecx.push_back(make_pair(a,b));
	}
	  sort(vecx.begin(),vecx.end());
	vecxtmp=vecx;
	float ans=findans(vecx,0,n);
	cout<<ans;
	return 0;
}