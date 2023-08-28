#include <bits/stdc++.h>

using namespace std;
const int a = 1e6;
vector<int> adj[a];
vector<int> rev[a];
int vis[a];
bool assing[a];

 
stack<int> st;

void adjdfs(int n){
    vis[n]=true;
    for(auto it:adj[n]){
        if(vis[it]==0) {
        adjdfs(it);
        }
    }
    st.push(n);
}

void revdfs(int n,int cnt){
    vis[n] = cnt;
    for(auto it:rev[n]){
        if(vis[it]==0){ 
        revdfs(it,cnt);
        }
    }
}

int SAT2(int n){
    for (int i = 1; i <= n; i++){
        if(vis[i]) continue;
        adjdfs(i);
    }

    for (int i = 1; i <=n; i++){
        vis[i] = false;
    }
    
    int cnt =1;
    while(!st.empty()){
        int f = st.top();
        st.pop();
        if(vis[f]) continue;
        revdfs(f,cnt);
        cnt++;
    }
    int w = n/2;
    for (int i = 1; i <= w; i++)
    {
        if(vis[i]==vis[w+i]) return false;
        assing[i] = vis[i]>vis[w+i];
    }
    return true;
}

int get_index(int k,bool sign_k,int n){
    if(!sign_k) return k+n;
    return k;
}
void add_edge(int a,int b,bool sign_a,bool sign_b,int n){
    int a1 = get_index(a,!sign_a,n);
    int a2 = get_index(b,sign_b,n);
    int b1 = get_index(b,!sign_b,n);
    int b2 = get_index(a,sign_a,n);
    adj[a1].push_back(a2);
    adj[b1].push_back(b2);

    
    rev[a2].push_back(a1);
    rev[b2].push_back(b1);
    return;
}

int main()
{
    int n,m;
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        char s_x,s_y;
        cin>>s_x>>x>>s_y>>y;
        bool w = s_x=='+';
        bool m = s_y=='+';
        add_edge(x,y,w,m,n);
    }
    if(SAT2(2*n)){
        for(int i =1;i<=n;i++){
            if(assing[i]) cout<<"+ ";
            else cout<<"- ";
        }
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
