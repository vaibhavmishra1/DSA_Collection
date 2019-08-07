#include <bits/stdc++.h>
using namespace std;
pair<long long int ,long long int > p,q;

float bruteforce(vector<pair<long long int ,long long int >> vecx,long long int l,long long int r)
{
    float min=FLT_MAX;
    for(long long int i=l;i<r;i++)
    {
        for(long long int j=i+1;j<r;j++)
        {
            float dist;
            dist=pow(abs(vecx[j].first-vecx[i].first),2)+pow(abs(vecx[j].second-vecx[i].second),2);
            dist=pow(dist,0.5);
            if(dist<min)
            {
                min=dist;
                p=make_pair(vecx[i].first,vecx[i].second);
                q=make_pair(vecx[j].first,vecx[j].second);
            }
        }
    }
    return min;
}
float findans(vector<pair<long long int ,long long int >> vecx,long long int l,long long int r)
{
    if(r-l<4)
    {
        
        float ret=bruteforce(vecx,l,r);
        return ret;
    }
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
    float d;
    d=min(a,b);
    vector<pair<long long int ,long long int > >vecy;
    for(long long int i=0;i<vecx.size();i++)
    {
        if(abs(vecx[i].first-vecx[mid].first)<d && i!=mid)
        {
            vecy.push_back(make_pair(vecx[i].second,vecx[i].first));
        }
    }
    sort(vecy.begin(),vecy.end());
    for(long long int i=0;i<vecy.size();i++)
    {
        for(long long int j=i+1;i+j<vecy.size(),j-i<=7;j++)
        {
            float euc;
            euc=pow(abs(vecy[j].first-vecy[i].first),2)+pow(abs(vecy[j].second-vecy[i].second),2);
            euc=pow(euc,0.5);
            
            if(euc<d)
            {d=euc;
                p=make_pair(vecx[i].first,vecx[i].second);
                q=make_pair(vecx[j].first,vecx[j].second);
            }
        }
    }
    
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
        vecxtmp=vecx;
      sort(vecx.begin(),vecx.end());

    float ans=findans(vecx,0,n);

    long long int m=0,z=0;
    cout<<p.first<<" "<<p.second<<endl;
    cout<<q.first<<" "<<q.second;
    cout<<endl;
    for(long long int i=0;i<n;i++)
    {
        if(vecxtmp[i]==p)
        {
            long long int m=i;
        }
        if(vecxtmp[i]==q)
        {
            long long int z=i;
        }
    }
    cout<<m<<" "<<z<<" "<<ans;
    return 0;
}