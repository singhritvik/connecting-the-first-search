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



int main( )
{
    int n,m; 
    cin>>n>>m;
    
    dsu ans(n);
    while(m--){
        string w;
        int a,b;
        cin>>w>>a>>b;
        a--,b--;
        if(w=="union"){
            ans.unions(a,b);
        }
        else{
            int w = ans.findp(a);
            int v = ans.findp(b);
            if(w==v){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
            
        }
    }
    return 0;
}
