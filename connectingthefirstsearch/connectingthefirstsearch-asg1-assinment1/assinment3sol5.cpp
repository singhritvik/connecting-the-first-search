/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
const int a=1e6;
long long int BIT[a], arr[a];
int n,m;

void update(long long int x,long long int k)
{
      for(; x <= n; x += x&-x)
        BIT[x] += k;
}
long long int query(long long int x)
{
     long long int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i]);
        update(i+1,-arr[i]);
    }
    
    for(int i=0;i<m;i++){
        int s;cin>>s;
        if(s==2){
            long long int k;cin>>k;
            cout<<query(k)<<endl;
        }
        if(s==1){
            long long int k,l,u;
            cin>>k>>l>>u;
            update(l+1, -u);
            update(k, u);
            // for(long long int q=k;q<l;q++){
            //     update(q,u);
            // }
        }
    }
    

    return 0;
}
