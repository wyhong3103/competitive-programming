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
 
void solve(){
    string a, b;
    cin >> a >> b;
 
    map<char,int> rank = {{'M', 2}, {'S', 1}, {'L' , 3}};
 
    if (rank[a.back()] != rank[b.back()]){
        if (rank[a.back()] > rank[b.back()]) cout << ">\n";
        else cout << "<\n";
    }else{
        if (sz(a) == sz(b)) cout << "=\n";
        else{
            if (a.back() == 'L'){
                if (sz(a) > sz(b)) cout << ">\n";
                else cout << "<\n";
            }else{
                if (sz(a) > sz(b)) cout << "<\n";
                else cout << ">\n";
            }
        }
    }
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