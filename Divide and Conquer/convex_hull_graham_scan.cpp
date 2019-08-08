#include<bits/stdc++.h>
using namespace std;
struct point
{
    long long int x;
    long long int y;
};
point minm;
int dist(point p,point q)
{
    int val=(p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
    return val;
}
int orientation(point p,point q,point r)
{
    long long int val=(p.x*(q.y-r.y)-p.y*(q.x-r.x)+q.x*r.y-q.y*r.x);
    if(val==0)return 0;
    if(val>0)return 1;
    if(val<0)return 2;
}
int compare(point q,point r)
{
    int ori=orientation(minm,q,r);
     if(ori==0){
        int distq=dist(minm,q);
        int distr=dist(minm,r);
        if(distq>distr)
            return 0;
        else {return 1;}
    }
    else if(ori==1)
        return 1;
    return 0;
}
int main(){
	long long int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    vector<point> vec;
	    point ent;
	    for(long long int i=0;i<n;i++){
	        cin>>ent.x>>ent.y;
	        int flag=0;
	        for(long long int j=0;j<vec.size();j++){
	            if(vec[j].x==ent.x && vec[j].y==ent.y){
	                flag=1;
	                break;
	            }
	        }
	        if(flag==0)
	        	vec.push_back(ent);
		}
		      if(n<3)
		    {cout<<"-1"<<endl;
		        continue;
		    }
	    minm=vec[0];
	    n=vec.size();
	    for(long long int i=0;i<n;i++)
	    {
	    	if(vec[i].y<minm.y)
	                minm=vec[i];
	        
	        else if(vec[i].y==minm.y)
	        {
	            if(vec[i].x<=minm.x)
	                minm=vec[i];
	        }
	    }
	    vector<point> vecfinal;
	    for(long long int i=0;i<n;i++)
	    {   if(vec[i].x!=minm.x || vec[i].y!=minm.y)
	        {
	            vecfinal.push_back(vec[i]);
	        }
	    }
	   sort(vecfinal.begin(),vecfinal.end(),compare);
	   stack<point> stk;
	   stk.push(minm);
	   stk.push(vecfinal[0]);
	   for(long long int i=1;i<vecfinal.size();i++)
	    {while(stk.size()>=2)
	        {point p1=stk.top();
    	        stk.pop();
    	        point p2=stk.top();
    	        stk.pop();
    	        int ori=orientation(p2,p1,vecfinal[i]);
    	        if(ori==1)
    	        {stk.push(p2);
    	            stk.push(p1);
    	            stk.push(vecfinal[i]);
    	            break;
    	        }
    	        else if(ori==2)
    	        	stk.push(p2);
    	         
    	        else if(ori==0)
    	        {stk.push(p2);
    	            stk.push(p1);
    	            stk.push(vecfinal[i]);
    	            break;
    	        }
	        }
	    }
	    vector<pair<long long int ,long long int >> ans;
	    if(stk.size()<=2)
	    {cout<<"-1"<<endl;}
	    else
	    {while(!stk.empty()){
    	        point p=stk.top();
    	        ans.push_back(make_pair(p.x,p.y));
    	        stk.pop();
    	    }
	    }
	    sort(ans.begin(),ans.end());
	    for(long long int i=0;i<ans.size();i++)
	    {cout<<ans[i].first<<" "<<ans[i].second;
	        if(i!=ans.size()-1)
	        {
	            cout<<", ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}