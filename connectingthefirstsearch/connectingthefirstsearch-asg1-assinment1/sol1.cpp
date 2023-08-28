#include <bits/stdc++.h>

using namespace std;

const int a=10^6;
bool vis[a];        //visited array 
vector<int>adj[a];   //adj list 

vector<int>tin(a,0);
vector<int>tout(a,0);

int cont=0;

void dfs(int s){
    tin[s]=cont++;
    vis[s]=true;
    for(auto x:adj[s]){
        if(vis[x]!=1){
            dfs(x);
        }
    }
    tout[s]=cont++;
    return;
}

bool tree_ed(int first,int second){
    return tin[first]<tin[second] && tout[first]>tout[second];
}


int main()
{
     int n,m;
    cin>>n>>m;
    for(int i=0;i<a;i++){
        vis[i]=0;
    }
    
    vector<pair<int,int> >edge;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
       edge.push_back(make_pair(x,y));
    }
    
     dfs(0);
    
    cout<<" tree edge"<<endl;
   
     for (int i=0;i<n;i++)
    {
        if(tree_ed(edge[i].first,edge[i].second)){
            cout<<"("<<edge[i].first<<","<<edge[i].second<<") ";
        }
        else{
            cout<<"("<<edge[i].first<<","<<edge[i].second<<") ";
        }
    }
    cout<<endl;
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Vertex : "<<i<<" tin: "<<tin[i]<<" tout: "<<tout[i]<<"\n";    
    }

    return 0;
}