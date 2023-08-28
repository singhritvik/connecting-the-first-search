/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>


using namespace std;

class dsu
{
private:
    vector<int> par;
public:
    dsu(int n)
    {
        par.resize(n,-1);
    }
    
    int findp(int n){
    if(par[n]<0) return n;
    return par[n]=findp(par[n]);
    }
    
    void unions(int a,int b){
    a = findp(a);
    b = findp(b);
    if(a!=b){
        if(par[b]<par[a]) swap(a,b);
        par[a] += par[b];
        par[b]=a;
    }
    return;
    }
   
};

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    dsu ans(n);
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
    }
    stack<vector<int> > q;
    for (int i = 0; i < k; i++)
    {
        string p;
        cin>>p>>x>>y;
        x--,y--;
        if(p=="ask"){
            q.push({1,x,y});
        }
        else{
            q.push({0,x,y});
        }
    }
    vector<string> answ;
    while(!q.empty()){
        auto x = q.top();
        q.pop();
        if(x[0]){
            answ.push_back((ans.findp(x[1])==ans.findp(x[2]))?"YES\n":"NO\n");
        }
        else{
            ans.unions(x[1],x[2]);
        }
    }
    for(auto it=answ.rbegin();it!=answ.rend();it++){
        cout<<*it;
    }
}
