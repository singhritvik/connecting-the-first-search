#include <iostream>
#include<vector>
#include<queue>

using namespace std;

const int a=1e5+10;
vector<int>adj[a];
int indegree[a];

vector<int> topo(int n){
    vector<int>topological(n,0);
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int index=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        topological[index++]=f;
        for(auto x:adj[f]){
            indegree[x]=indegree[x]-1;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
     if(index!=n){
         return{ };
     }
    return topological;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    
    vector<int>vec=topo(n);
    
    
    for(auto it:vec){
        cout<<it<<" ";
    }
    if(vec.empty()){
        cout<<"IMPOSSIBLE";
    }
    
    

    return 0;
}