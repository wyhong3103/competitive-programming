```

Stupid constructive problem that I bricked so hard. Just need to do snake like movement


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
    int n;
    cin >> n;
 
    vector<vi> a(n, vi(n));
    
    pi p{1, n*n};
    for(int i{}; i < n; i++){
        if (n % 2){
            if (i % 2 == 0){
                for(int j{}; j < n; j++){
                    if (j % 2 == 0) a[i][j] = p.fir++;
                    else a[i][j] = p.sec--;
                }
            }else{
                for(int j{n-1}; j >= 0; j--){
                    if (j % 2 == (n-1) % 2) a[i][j] = p.sec--;
                    else a[i][j] = p.fir++;
                }
            }
        }else{
            if (i % 2 == 0){
                for(int j{}; j < n; j++){
                    if (j % 2 == 0) a[i][j] = p.fir++;
                    else a[i][j] = p.sec--;
                }
            }else{
                for(int j{n-1}; j >= 0; j--){
                    if (j % 2 != (n-1) % 2) a[i][j] = p.sec--;
                    else a[i][j] = p.fir++;
                }
            }
 
        }
    }
 
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
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