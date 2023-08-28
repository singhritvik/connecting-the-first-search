#include <bits/stdc++.h>

using namespace std;

const int a=1e5+3;
vector<int>adj[a];
vector<int>rev[a];
int vis[a];
int vis1[a];
stack<int>st;

void adjdfs(int n){
    vis[n]=1;
    for(auto it:adj[n]){
        if(vis[it]==0){
            adjdfs(it);
        }
    }
    st.push(n);
}

void revdfs(int n,int cnt){
    vis1[n]=cnt;
    for(auto it:rev[n]){
        if(vis1[it]==0){
            revdfs(it,cnt);
        }
    }
}

int find(int n){
    int cnt=1;
    while(!st.empty()){
        int f=st.top();
        st.pop();
        if(vis1[f]==0){
        revdfs(f,cnt);
        cnt++;
        }
    }
    return cnt-1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
        vis1[i]=0;
    }
    
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            adjdfs(i);
        }
    }
    
    
    cout<<find(n)<<endl;
    
    for(int i=1;i<=n;i++){
        cout<<vis1[i]<<" ";
    }

    return 0;
}