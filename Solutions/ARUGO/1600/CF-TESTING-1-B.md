Use a prefix sum array, to calcaulte how many corresponding pairs are there, and then it's just some combinatorics.
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
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 1000;
char grid[MAX][MAX];
int pref_row[MAX][MAX];
int pref_col[MAX][MAX];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (grid[i][j] == '*'){
                pref_row[i][j]++;
                pref_col[i][j]++;
            }
        }
    }

    for(int i{}; i < n; i++){
        for(int j{1}; j < m; j++){
            pref_row[i][j] += pref_row[i][j-1];
        }
    }

    for(int j{}; j < m; j++){
        for(int i{1}; i < n; i++){
            pref_col[i][j] += pref_col[i-1][j];
        }
    }

    ll res = 0;
    for(int i{}; i < n; i++){
        for(int j{};j < m; j++){
            if (grid[i][j] == '*'){
                //++
                res += (pref_row[i][m-1] - (pref_row[i][j])) *  (ll)(pref_col[n-1][j] - (pref_col[i][j]));
                //+-
                res += (pref_row[i][m-1] - (pref_row[i][j])) * (ll)(pref_col[i][j]-1);

                //-+
                res += (pref_row[i][j]-1) * (ll)(pref_col[n-1][j] - (pref_col[i][j]));

                //--
                res +=  (pref_row[i][j]-1) * (ll)(pref_col[i][j]-1);
            }
        }
    }
    cout << res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```