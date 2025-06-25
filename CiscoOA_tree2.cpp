#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 3e5 + 5;
const int INF = 1e9;
const int M = 20;
int n,m;
int startnode,endnode;
void dfs(int curr,int parent,vector<vector<int>>& adj,vector<int>& dist){
    if(parent==0){
        dist[curr]=0;
    }else{
        dist[curr] = dist[parent]+1;
    }
    for(auto it:adj[curr]){
        if(it!=parent){
            dfs(it,curr,adj,dist);
        }
    }
}
void dfs1(int curr,int parent,vector<vector<int>>& adj,set<int>& st,vector<bool> & should_visit){
    for(auto it:adj[curr]){
        if(it!=parent){
            dfs1(it,curr,adj,st,should_visit);
            if(should_visit[it]){
                should_visit[curr]=true;
            }
        }
    }
    if(st.find(curr)!=st.end()){
        should_visit[curr] = true;
    }
}
void dfs2(int curr,int parent,int& g_time,vector<vector<int>>& adj,vector<bool>& should_visit){
    for(auto it:adj[curr]){
        if(it!=parent && should_visit[it]){
            g_time+=2;
            dfs2(it,curr,g_time,adj,should_visit);
        }
    }
}
void solve(){
    cin>>n>>m;
    cin>>startnode>>endnode;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> st;
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        st.insert(num);
    }
    vector<int> dist1(n+1,0),dist2(n+1,0);
    dfs(startnode, 0,adj,dist1);
    dfs(endnode, 0 ,adj,dist2);
    vector<bool> should_visit(n+1,0);
    dfs1(startnode,0,adj,st,should_visit);
    int g_time = 0;
    dfs2(startnode,0,g_time,adj,should_visit);
    int farthest_dist  = -1;
    int idx =-1;
    for(int i=1;i<=n;i++){
        if(dist1[i]>farthest_dist){
            farthest_dist = dist1[i];
            idx = i;
        }
    }
    g_time -= farthest_dist;
    g_time += dist2[idx];
    cout<<g_time<<"\n";
}
int main(){
 int t =1;
 cin>>t;
 while(t--)	solve();
return 0;}
