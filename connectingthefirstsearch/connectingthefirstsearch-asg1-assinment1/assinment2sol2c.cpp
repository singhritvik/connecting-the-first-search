#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
vector<pair<int,int> > adj[N];
int ordered[N];
int indegree[N];


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



int no_ofpath(int u,int v,int n){
    vector<int> dp(n+1,0);
    if(!topo(n)) return 0;
    int index = n-1;
    while(index>=0){
        if(ordered[index]==v) break;
        index--;
    }
    dp[ordered[index--]]=1;
    while(index>=0){
        for(auto x:adj[ordered[index]]){
            dp[ordered[index]] += dp[x.first];
            
        }
        if(ordered[index]==u) break;
        index--;
    }
    
    return dp[ordered[index]];
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
    }
     
    cout<<no_ofpath(1,n,n)<<endl;
    return 0;
}