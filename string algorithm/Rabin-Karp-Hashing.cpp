#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
struct Hash{
    const int MOD = 1e9 +7 ,BASE1 = 5689,BASE2 = 1013;
    vector<pair<int,int>> hashes,Pow;
    Hash(string s){
        hashes.assign(s.size()+1,{0,0});
        Pow.assign(s.size()+1,{1,1});

        for(int i=0;i<s.size();i++){
            hashes[i+1] = {
                            ((1ll * hashes[i].first *BASE1)%MOD + (s[i]-'a'+1))%MOD,
                            ((1ll * hashes[i].second *BASE2)%MOD + (s[i]-'a'+1))%MOD
            };
            Pow[i+1] = {
                        (1ll * Pow[i].first * BASE1 )%MOD,
                        (1ll * Pow[i].second * BASE2 )%MOD
            };
        }
    }
    pair<int,int> get(int l,int r){
        l++;r++;
        int hash1 = (1ll * hashes[r].first - (1ll * hashes[l-1].first * Pow[r-l+1].first)%MOD + MOD)%MOD;
        int hash2 = (1ll * hashes[r].second - (1ll * hashes[l-1].second * Pow[r-l+1].second)%MOD + MOD)%MOD;
        return {hash1,hash2};
    }
};
void solve(){

}
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}