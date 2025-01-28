#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 2e5 + 5;
const int INF = 1e9;
const int M = 20;
int n,q;
int depth[N];
int par[N][M];
void dfs(int curr,vector<vector<int>>& adj,int parent){
    depth[curr] = depth[parent]+1;
    par[curr][0] = parent;
    for(int j=1;j<M;j++) par[curr][j]= par[par[curr][j-1]][j-1];
    for(auto neigh:adj[curr]){
        if(neigh!=parent){
            dfs(neigh,adj,curr);
        }
    }
}
int lift(int u,int k ){
    for(int i=M-1;i>=0;i--){
        if((1<<i)&k){
            u= par[u][i];
        }
    }
    return u;
}
int LCA(int u,int v){
    if(u==v) return u;
    if(depth[v]>depth[u]) swap(u,v);
    int diff = depth[u] - depth[v];
    u = lift(u,diff);
    for(int i=M-1;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return (u!=v ? par[u][0]:u);
}
void solve(){
    depth[0]=-1;
    cin>>n>>q;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        adj[x].push_back(i);
    }
    dfs(1,adj,0);
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<LCA(u,v)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
