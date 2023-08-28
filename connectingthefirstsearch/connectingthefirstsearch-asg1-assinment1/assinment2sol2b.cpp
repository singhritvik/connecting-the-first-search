#include <bits/stdc++.h>

using namespace std;

const int a = 1e6;
vector<pair<int,int> > adj[a];
int ordered[a];
int indegree[a];
vector<int> dis(a,INT_MIN);


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



void longest_path(int end,int n){
    int index = n-1;
    while(index>=0){
        if(ordered[index]==end) break;
        index--;
    }
    dis[ordered[index--]]=0;
    while(index>=0){
        for(auto it:adj[ordered[index]]){
            if(dis[it.first]==INT_MIN) continue;
            dis[ordered[index]] = max(dis[it.first]+it.second,dis[ordered[index]]);
        }
        index--;
    }
    return; 
}

void dfs_print(int index,int v){
    cout<<index<<" ";
    if(index==v) return;
    for(auto it:adj[index]){
        if(dis[it.first]+it.second == dis[index]){
            dfs_print(it.first,v);
            break;
        }
    }
}

bool print_longest_path(int u,int v,int n){
    longest_path(v,n);
    if(dis[u]==INT_MIN) return false;
    cout<<dis[u]+1<<"\n";  
    dfs_print(u,v);
    return true;
}
// driver's code

int main( )
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i <m; i++)
    {
 
        int x,y,z=1;
        cin>>x>>y; 
        adj[x].push_back({y,z});
        indegree[y]++;
    }
    
    if(!topo(n)) cout<<"IMPOSSIBLE\n";
    if(!print_longest_path(1,n,n)) cout<<"IMPOSSIBLE\n";
    return 0;
}
