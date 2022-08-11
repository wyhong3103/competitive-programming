Traditional Knapsack problem, for some reasons, CSES gives TLE when we use much space. Anyways the logic is the same.
```
The idea is to construct the optimal substructure

dp[x][w] = maximum value we can construct using at most x money, and only considering the first w weight

The transition is max(dp[i][j-1], dp[i-weight][j-1] + value of the weight)

Because at each [w] state we're only considering either we're going to add this new weight or don't to the optimal substructure we just consutruct using w-1 weights.
```
O(NX) Space method
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
 
const int MXX = 1e5+1;
const int MXN = 1000;
 
int dp[MXX][MXN];
 
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<pi> books(n);
 
    for(int i{}; i < n; i++){
        cin >> books[i].fir;
    }
 
    for(int i{}; i < n; i++){
        cin >> books[i].sec;
    }
 
    for(int j{}; j < n; j++){
        for(int i{1}; i <= x; i++){
            dp[i][j] = max(dp[i][j-1], (i-books[j].fir >= 0 ? dp[i-books[j].fir][j-1] + books[j].sec : 0));
        }
    }
 
    cout << dp[x][n-1];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```
O(N) Space method
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

const int MXX = 1e5+1;
const int MXN = 1000;


int dp[MXX];
int dp2[MXX];

void solve(){
    int n, x;
    cin >> n >> x;

    vector<pi> books(n);

    for(int i{}; i < n; i++){
        cin >> books[i].fir;
    }

    for(int i{}; i < n; i++){
        cin >> books[i].sec;
    }

    for(int j{}; j < n; j++){
        for(int i{1}; i <= x; i++){
            dp[i] = max(dp2[i], (i-books[j].fir >= 0 ? dp2[i-books[j].fir] + books[j].sec : 0));
        }
        for(int i{1}; i <= x; i++){
            dp2[i] = dp[i];
        }
    }

    cout << dp[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```