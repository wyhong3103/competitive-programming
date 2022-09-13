Process it from backward, if we ever detect a zero, the next two numbers are one pair.
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
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    string res;
    int at = n-1;
    while (at >= 0){
        if (s[at] == '0'){
            int x = (s[at-2]-'0')*10;
            int y = (s[at-1]-'0');
            res += 'a'+x+y-1;
            at-=3;
        }else{
            res += 'a'+((s[at]-'0')-1);
            at--;
        }
    }
    for(int i{sz(res)-1}; i >= 0; i--) cout << res[i];
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