#include <bits/stdc++.h>

using namespace std;

const int a = 1e6;
vector<pair<int,int> > adj[a];
int ordered[a];
int indegree[a];
vector<int> dis(a,INT_MAX);


bool topo(int n){
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if(indegree[i]==0){
            q.push(i);
        }
    int index = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        ordered[index++]=f;
        for(auto it: adj[f]){
            int x = it.first;
            indegree[x] -=1;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    if(index!=n){
        return false;
    }
    return true;
}



void short_path(int end,int n){
    int index = n-1;
    while(index>=0){
        if(ordered[index]==end) break;
        index--;
    }
    dis[ordered[index--]]=0;
    while(index>=0){
        for(auto child:adj[ordered[index]]){
            if(dis[child.first]==INT_MAX) continue;
            dis[ordered[index]] = min(dis[child.first]+child.second,dis[ordered[index]]);
        }
        index--;
    }
    return; 
}

void dfs_print(int index,int v){
    cout<<index<<" ";
    if(index==v) return;
    for(auto child:adj[index]){
        if(dis[child.first]+child.second == dis[index]){
            dfs_print(child.first,v);
            break;
        }
    }
}

bool print_short_path(int u,int v,int n){
    short_path(v,n);
    if(dis[u]==INT_MAX) return false;
    cout<<dis[u]+1<<"\n";  
    dfs_print(u,v);
    return true;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
         
        int x,y,z=1;
        cin>>x>>y; 
        adj[x].push_back({y,z});
        indegree[y]++;
    }


    if(!topo(n)) cout<<"IMPOSSIBLE\n";
    if(!print_short_path(1,n,n)) cout<<"IMPOSSIBLE\n";
    return 0;
}
