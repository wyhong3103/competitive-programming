Simple recursion to make the moves, literally bruteforcing it. (since the input is extremely small)
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
int n;
int mvr[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int mvc[8] = {0, 1, 0, -1, 1, -1, -1, 1};
const int MX = 10;
string grid[MX];
 
void move( int i, int j, string& res, int mv, int& cnt){
    if (cnt == n){
        return;
    }
    if (i < 0){
        i = n-1;
    }
    else if (i >= n){
        i = 0;
    } 
    if (j < 0){
        j = n-1;
    }
    else if (j >= n){
        j = 0;
    }
 
    res += grid[i][j];
    cnt++;
    move(i+mvr[mv], j+mvc[mv], res, mv, cnt);
}
 
void solve(){
    cin >> n;
 
    for(int i{}; i < n; i++) cin >> grid[i];
 
 
    ll mx = 0;
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            for(int k{}; k < 8; k++){
                int cnt = 0;
                string res = "";
                move(i, j, res,k, cnt);
                ll temp= 0;
                for(int i{}; i < n; i++){
                    temp += (res[i]-'0')*pow(10,n-i-1);
                }
                mx = max(temp, mx);
            } 
        }
    }
 
    cout << mx;
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