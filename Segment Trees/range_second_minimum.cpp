#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 3e5 + 5;
const int INF = 1e9;
const int M = 20;
ll n,q;
vector<ll> arr(N);
vector<pair<ll,ll>> sg(4*N);
pair<ll,ll> merge(pair<ll,ll> a,pair<ll,ll> b){
    vector<ll> v = {a.first,a.second,b.first,b.second};
    sort(v.begin(),v.end());
    return {v[0],v[1]};
}
void build(ll s,ll e,ll index){
    if(s==e){
        sg[index]={arr[s],INF};
        return;
    }
    ll mid = (s+e)/2;
    build(s,mid,2*index);
    build(mid+1,e,2*index +1);
    sg[index] = merge(sg[2*index],sg[2*index +1]);
}
void update(ll s,ll e ,ll index, ll update_index,ll update_val){
    if(s==e){
        sg[index] = {update_val,INF};
        return;
    }
    ll mid = (s+e)/2;
    if(update_index<=mid){
        update(s,mid,2*index,update_index,update_val);
    }else{
        update(mid+1,e,2*index +1 ,update_index,update_val);
    }
    sg[index] = merge(sg[2*index],sg[2*index +1]);
}
pair<ll,ll> query(ll s ,ll e ,ll index , ll l ,ll r){
    if(s>r || e<l){
        return {INF,INF};
    }
    if(s>=l && e<=r){
        return sg[index];
    }
    ll mid = (s+e)/2;
    pair<ll,ll> left_contri = query(s,mid,2*index,l,r);
    pair<ll,ll> right_contri = query(mid+1,e,2*index +1,l,r);
    return merge(left_contri,right_contri);
}
void solve(){
    cin>>n>>q;
    for(ll i=0;i<n;i++) cin>>arr[i];
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll i,x;
            cin>>i>>x;
            i--;
            update(0,n-1,1,i,x);
        }else{
            ll l,r;
            cin>>l>>r;
            l--;r--;
            pair<ll,ll> ans = query(0,n-1,1,l,r);
            cout<<ans.second<<"\n";
        }
    }
} 
int main(){
 int t =1;
 //cin>>t;
 while(t--)	solve();
return 0;}
