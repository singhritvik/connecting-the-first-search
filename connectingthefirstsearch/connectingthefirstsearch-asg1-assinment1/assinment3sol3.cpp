/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>


using namespace std;
const int a = 1e5+10;
vector<int> v[a];

int vis[a]; 

vector<vector<int> > conncomp; 

int id =0; 


void dfs(int ver,vector<int> &temp){
    vis[ver] = id;
    temp.push_back(ver);
    for (auto it:v[ver])
    {
        if(vis[it]) continue;
        dfs(it,temp);
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int conn =0;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if(vis[i]) continue;
        dfs(i,temp);
        conn++;
        id++;
        conncomp.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"Vertex : "<<i<<" has ID: "<<vis[i]<<"\n";
    }
    return 0;
}
