```
Greedily pick the letters that we could save, letter that we couldn't save automatically become min(d+1, 9), and we can place it anywhere we want,  then print all the letters in sorted order.
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
 
void solve(){
    string s;
    cin >> s;
 
    map<int,int> freq;
    vector<bool> chosen(sz(s));
 
    int last = -1;
    for(int d{}; d <= 9; d++){
        for(int i{last+1}; i < sz(s); i++){
            if (s[i] == '0'+d) {
                last = i;
                chosen[i] = 1;
                freq[d]++;
            }
        }
    }
 
    for(int i{}; i < sz(s); i++){
        if (!chosen[i]) freq[min(s[i]-'0'+1, 9)]++;
    }
 
    for(auto& i : freq){
        for(int j{}; j < i.sec; j++){
            cout << i.fir;
        }
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