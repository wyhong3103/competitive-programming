Totally overcomplicated the problem. You literally just have to fill in the neighbours, no matter how you fill it, as long as there is k different neighbours , it's always going to work.
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
int n, m;
 
int row[4] = {1, -1, 0 ,0};
int col[4] = {0, 0, 1, -1};
 
int countcell(vector<vi>& a, int i, int j){
    auto valid = [](int i, int j){
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    };
    int cnt =0;
    for(int k{}; k < 4; k++){
        if (valid(i+row[k], j+col[k]) && a[i+row[k]][j+col[k]] != a[i][j] && a[i+row[k]][j+col[k]] != -1){
            cnt++; 
        }
    }
    return cnt;
}
 
 
 
void solve(){
    cin >> n >> m;
 
    vector<vi> a(n);
    for(auto& i : a){
        i.resize(m);
        fill(all(i), -1);
    }
 
    auto valid = [](int i, int j){
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    };
 
    a[0][0] = 1;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            int cnt = countcell(a,i,j);
            for(int k{}; k < 4; k++){
                if (valid(i+row[k], j+col[k]) && a[i+row[k]][j+col[k]] == -1 && cnt < 2){
                    a[i+row[k]][j+col[k]] = !a[i][j];
                    cnt++;
                }
            } 
            for(int k{}; k < 4; k++){
                if (valid(i+row[k], j+col[k]) && a[i+row[k]][j+col[k]] == -1){
                    a[i+row[k]][j+col[k]] = a[i][j];
                }
            } 
        }
    }
 
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cout << a[i][j] << ' ';
        }
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