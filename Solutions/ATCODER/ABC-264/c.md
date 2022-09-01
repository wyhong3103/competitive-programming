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
    int h1, w1;
    cin >> h1 >> w1;
 
    vector<vi> a(h1, vi (w1));
    for(int i{}; i < h1; i++){
        for(int j{}; j < w1; j++) cin >> a[i][j];
    }
 
    int h2, w2;
    cin >> h2 >> w2;
    vector<vi> b(h2, vi (w2));
    for(int i{}; i < h2; i++){
        for(int j{}; j < w2; j++) cin >> b[i][j];
    }
 
 
    vector<multiset<int>> row(h1);
    vector<multiset<int>> col(w1);
 
    for(int i{}; i < h1; i++){
        for(int j{}; j < w1; j++){
            row[i].insert(a[i][j]);
        }
    }
    for(int i{}; i < w1; i++){
        for(int j{}; j < h1; j++){
            col[i].insert(a[j][i]);
        }
    }
 
    bool ok = 1;
    int at = 0; 
    for(int i{}; i < h2; i++){
        map<int,int> cnt;
        for(int j{}; j < w2; j++){
            if (!cnt.count(b[i][j])) cnt[b[i][j]] = 0;
            cnt[b[i][j]]++;
        }    
        while (at < h1){
            bool temp_ok = 1;
            for(auto& j : cnt){
                if (row[at].count(j.fir) < j.sec){
                    temp_ok = 0;
                    break;
                }
            }
            if (!temp_ok) at++;
            else break;
            if (!temp_ok && at == h1) ok = 0;
        }
    }
 
    at = 0;
    for(int i{}; i < w2; i++){
        map<int,int> cnt;
        for(int j{}; j < h2; j++){
            if (!cnt.count(b[j][i])) cnt[b[j][i]] = 0;
            cnt[b[j][i]]++;
        }    
        while (at < w1){
            bool temp_ok = 1;
            for(auto& j : cnt){
                if (col[at].count(j.fir) < j.sec){
                    temp_ok = 0;
                    break;
                }
            }
            if (!temp_ok) at++;
            else break;
            if (!temp_ok && at == w1) ok = 0;
        }
    }
 
    cout << (ok ? "Yes" : "No");
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