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
    string s;
    cin >> s;
 
    string ori = "atcoder";
    
 
    int cnt = 0;
    for(int i{}; i < 7; i++){
        if (ori[i] != s[i]){
            int at = 0;
            for(int j{i+1}; j < 7; j++){
                if (s[j] == ori[i]) at = j;
            }
            for(int j{at}; j > i; j--){
                swap(s[j], s[j-1]);
                cnt++;
            }
        }
    }
    cout << cnt;
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```