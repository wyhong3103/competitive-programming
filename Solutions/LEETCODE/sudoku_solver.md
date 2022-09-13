Backtracking algorithm.
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


bool recur(int i, int j, vector<vi>& a){
    if (a[i][j] != -1) {
        if (j+1 < 9) return recur(i, j+1, a);
        else if (i+1 < 9) return recur(i+1, 0, a);
        else return true;
    }

    vector<bool> used(9);
    for(int r{}; r < 9; r++){
        if (a[i][r] == -1) continue;
        used[a[i][r]-1] = 1;
    }
    for(int c{}; c < 9; c++){
        if (a[c][j] == -1) continue;
        used[a[c][j]-1] = 1;
    }
    
    pi start = {(i/3) * 3, (j/3) * 3};

    for(int r{}; r < 3; r++){
        for(int c{}; c < 3; c++){
            if (a[start.fir+r][start.sec+c] == -1) continue;
            used[a[start.fir+r][start.sec+c]-1] = 1;            
        }
    }
    
    for(int k{}; k < 9; k++){
        if (used[k]) continue;

        a[i][j] = k+1;
        if (j+1 < 9){
            if (recur(i,j+1, a)) return true;
            else{
                a[i][j] = -1;
                continue;
            }
        }else if (i+1 < 9){
            a[i][j] = k+1;
            if (recur(i+1,0, a)) return true;
            else{
                a[i][j] = -1;
                continue;
            }

        }else return true;
    }

    return false;
}
 
void solve(){
    int n = 9;
    vector<vi> ori(n, vi(n));
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> ori[i][j];
        }
    }

    vector<vi> a = ori;

    cout << recur(0,0,a) << '\n';
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