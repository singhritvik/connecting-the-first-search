#include <bits/stdc++.h>

using namespace std;

const int a=10^6;
bool vis[a];
vector<pair<int ,int> >adj[a];

int tin[a];
int low[a];

int t;

vector<pair<int ,int> >v1;

void deleteb(int x,int y){
    for(int i=0;i<adj[x].size();i++){
        if(adj[x][i].first==x){
            adj[x][i].second=1;
        }
    }
     for(int i=0;i<adj[y].size();i++){
        if(adj[y][i].first==y){
            adj[y][i].second=1;
        }
    }
    v1.push_back(make_pair(x,y));
}

void dfs(int x,int p=-1){
    vis[x]=true;
    tin[x]=low[x]=t++;
    
    for(auto it:adj[x]){
        if(it.first==p)continue;
        if(vis[it.first]){
            low[x]=min(low[x],tin[it.first]);
        }
        else{
            dfs(it.first,x);
            low[x]=min(low[x],low[it.first]);
            if(low[it.first]>tin[x]){
                deleteb(x,it.first);
            }
        }
    }
}

int main()
{
    int n,m;       // n=vertex,m=edges;
    cin>>n>>m;
    for(int i=0;i<a;i++){
        vis[i]=0;
    }
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(make_pair(y,0));
         adj[y].push_back(make_pair(x,0));
    }
    
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it:adj[i]){
            if(it.second==1)continue;
            cout<<it.first<<" ";
        }
        cout<<endl;
    }
    
    for(auto it:v1){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}