
//https://practice.geeksforgeeks.org/problems/topological-sort/1
int* topoSort(int n, vector<int> adjlist[])
{
      int ismarked[n]={0};
      int incoming[n];
     for(int i=0;i<n;i++)
     {
         ismarked[i]=0;
         incoming[i]=0;
     }
    
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<adjlist[i].size();j++)
         {
             incoming[adjlist[i][j]]++;
         }
     }
    
     queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(incoming[i]==0)
        {
            
            q.push(i);
            ismarked[i]=1;
            
        }
    }
    vector<int> ans;
    
    while(!q.empty())
    {
        int x=q.front();
        ans.push_back(x);
        q.pop();
        
        
        for(int i=0;i<adjlist[x].size();i++)
        {
            if(!ismarked[adjlist[x][i]]){
             
                incoming[adjlist[x][i]]--;
                
                if(incoming[adjlist[x][i]]==0)
                {
                   
                    q.push(adjlist[x][i]);
                    ismarked[adjlist[x][i]]=1;
                }
            }
        }
    }
     
    
    int *arr=new int[n];
    
     for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
     return arr;
}
