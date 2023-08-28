#include <bits/stdc++.h>


using namespace std;

const int a=10^6;
vector<int>adj[a];  //adj list 
bool vis[a];        // visited array

int dis[a];     //distance array

void path(int s){
    queue<int>q;
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto it:adj[f]){
            if(vis[it]!=1){
                dis[it]=dis[f]+1;
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main()
{
    
    int n,m; //n=number of vertix,m=number of edge;
    cin>>n>>m;
    
    for(int i=0;i<a;i++){   //intialize all value 0;
        vis[i]=0;
    }
    
    for(int i=0;i<a;i++){           //intialize distance from all node -1 ,if any vertex does not connect return -1
        dis[i]=-1;
    }
    
    for(int i=0;i<m;i++){     //make adj list
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s;
    cin>>s;  //s=vertex where you start dfs
    
    path(s);
    
    for(int i=0;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    

    return 0;
}