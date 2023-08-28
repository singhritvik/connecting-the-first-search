/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


const int a = 1e5;
vector<pair<long long ,long long > > adj[a];
bool vis[a];
pair<long long ,long long > parent[a];


void dfs(int n)
{
    vis[n] = true;
    for (auto it : adj[n])
    {
        if (vis[it.second])
        {
           
            int u1 = n;
            bool flag = false;
            if (it.first < 0)
                flag = true;
            vector<int> res;
            res.push_back(it.second);
            while (u1!=0 && u1 ^ it.second)
            {
                res.push_back(u1);
                u1 = parent[u1].second;
                if (parent[u1].first < 0)
                    flag = true;
            }
            res.push_back(it.second);
            if (flag)
            {
                reverse(res.begin(),res.end());
                cout << "YES" << endl;
                for (int x : res)
                    cout << x << " ";
                exit(0);
            }
        }
        else
        {
            parent[it.second] = {it.first, n};
            dfs(it.second);
        }
    }
}
int main()
{   
    long long int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        long long   x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({z, y});
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if(vis[i])
            continue;
        parent[i] = {0, 0};
        dfs(i);
    }
    cout << "NO";
    return 0;
}
