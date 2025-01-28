#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 200005;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int LOG = 20;

int n;
vector<int> in_time(N), out_time(N), subtree(N, 1), depth(N);
vector<vector<int>> ancestor(N, vector<int>(LOG, -1));
int global_time = 1;
void dfs(int curr, vector<vector<int>>& adj, int parent) {
    in_time[curr]=global_time++;
    depth[curr]= depth[parent]+ 1;
    ancestor[curr][0] = parent;

    for (int neigh : adj[curr]) { 
        if (neigh!=parent) {
            dfs(neigh,adj,curr);
            subtree[curr] += subtree[neigh];
        }
    }
    out_time[curr]=global_time++;
}

void calculateAncestor() {
    for (int k=1;k<LOG;k++) {
        for (int u=1;u<=n;u++) {
            if (ancestor[u][k -1] != -1) {
                ancestor[u][k]=ancestor[ancestor[u][k -1]][k -1];
            }
        }
    }
}
int lift(int u,int k) {
    for (int j=0;j<LOG;j++) {
        if ((k>> j) &1){
            u =ancestor[u][j];
            if (u==-1)break; 
        }
    }
    return u;
}
void solve() {
    cin >> n;
    vector<vector<int>> adj(n+1,vector<int>()); // 1-based
    for(int i=0;i<n- 1;i++){
        int u,v;
        cin >>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0]= -1;
    dfs(1,adj,0);
    calculateAncestor();
    
    int q;
    cin >>q;
    while (q--){
        int node,k;
        cin >>node>>k;
        cout << lift(node,k)<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
