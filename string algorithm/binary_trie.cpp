#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct Node{
    vector<int> children;
    int strings_ending_here;
    int strings_ending_below;
    Node(){
        children.resize(2,-1);
        strings_ending_here=0;
        strings_ending_below=0;
    }
    void markSpecial(){
        strings_ending_here++;
    }
    void unmarkSpecial(){
        strings_ending_here--;
    }
    bool canDeleteNode(){
        for(auto it:children){
            if(it!=-1){
                return false;
            }
        }
        return (strings_ending_here==0);
    }
    void setChildIndex(char ch,int index){
        children[ch-'0'] = index;
    }
};
struct Trie{
    vector<Node> nodes;
    int sizeofNodes=0;
    Trie(){
        nodes.emplace_back();
        sizeofNodes=1;
    }
    void addString(string a){
        int current =0;
        for(auto ch:a){
            int index= ch -'0';
            if(nodes[current].children[index]==-1){
                nodes[current].children[index]= sizeofNodes;
                nodes.emplace_back();
                sizeofNodes++;
            }
            nodes[current].strings_ending_below++;
            current = nodes[current].children[index];
        }
        nodes[current].markSpecial();
    }
    bool searchString(string a){
        int current =0;
        for(auto ch:a){
            int index= ch -'0';
            if(nodes[current].children[index]==-1)return false;
            current = nodes[current].children[index];
        }
        return (nodes[current].strings_ending_here>0);
    }
    bool recurse(string a, int current, int index) {
    if (index == a.size()) { 
        nodes[current].unmarkSpecial();
        nodes[current].strings_ending_below--;
        return nodes[current].canDeleteNode();
    }
    int childNode = nodes[current].children[a[index] - '0'];
    bool chk = recurse(a, childNode, index + 1);
    if (chk) {
        nodes[current].setChildIndex(a[index], -1);
        nodes[current].strings_ending_below--;
    }
    return nodes[current].canDeleteNode();
}
    void deleteString(string a){
        if(searchString(a)){
            recurse(a,0,0);
        }
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