int dfs(int node,int ismarked[],vector<int> adj[],int parent)
{
    ismarked[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        if(ismarked[adj[node][i]] && adj[node][i]!=parent){
          return 1;
        }
        
        else if(!ismarked[adj[node][i]])
        {
            int ans= dfs(adj[node][i],ismarked,adj,node);
            if(ans==1)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool isCyclic(vector<int> adj[], int V)
{
    int ismarked[V]={0};
   for(int i=0;i<V;i++)
   {
      if(!ismarked[i]){
        int ans=dfs(i,ismarked,adj,-1);
          if(ans==1)
          {
              return 1;
          }
      }
   }
   return 0;
}

