```
26 letters arranged in a circle

string t was obtained by it, each letter is getting replaced by the next letter.

basically each letter in t was not the actual letter the previous letter in the cycle is the actual letter

The idea is to greedily try to match the character and not to create a cycle. A cycle is allowed only if it's the last character. Although, I didn't understand the problem statement fully, it's quite a reading ngl, but that's what we needed to do.
```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 26;
int ranking[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}
 
bool dsu_union(int a, int b, ll& total){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return false;
 
    if (ranking[a] == ranking[b]) ranking[a]++;
 
    if (ranking[a] > ranking[b]){
        parent[b] = a;
        total--;
    }else{
        parent[a] = b;
        total--;
    }
    return true;
}
 
void solve(){
    int n;
    cin >> n;
 
    string s;
    cin >> s;
    
    vector<bool> found(26);
    string t;
    for(auto& i : s){
        if (!found[i-'a']){
            found[i-'a'] = 1;
            t += i;
        }
    }
    
    set<char> st;
    for(int i{}; i < 26; i++){
        st.insert(i+'a');
        parent[i] = i;
    }
 
 
    ll total = 26;
    vector<char> bind(26);
 
    for(int i{}; i < sz(t); i++){
        auto it = st.begin();
        while (*it == t[i] || (dsu_get((*it)-'a') == dsu_get(t[i]-'a') && total != 1)){
            it++;
        }
        dsu_union((*it)-'a', t[i]-'a', total);
        bind[t[i]-'a'] = *it;
        st.erase(*it);
    }
 
    for(int i{}; i < n; i++){
        cout << (char)bind[s[i]-'a'];
    }
    cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```