The idea is simply bitmasking. Also using prefix sum of course, we're doing prefix sum on the number of i-th bits. If the i-th bit is odd after doing range queries, then we should add 2^i it to the sum.
```cpp
#include <bits/stdc++.h>
#include <limits>
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

const int MAX = 2e5 + 5;
int pref[MAX][32];
int cur[32];

void solve(){
    //XOR odd
    int n, q;
    cin >> n >> q;
    for(int i{} ; i < n; i++){
        int n;
        cin >> n;
        //2^32 is the maximum we can go
        for(int j{}; j < 32; j++){
            if ((n >> j) & 1){
                cur[j]++;
            }
            pref[i][j] = cur[j];
        }
    }

    for(int i{}; i < q; i++){
        int f,t ;
        cin >> f >> t;
        f--;t--;
        int temp[32];
        for(int i{}; i < 32; i++) temp[i] = pref[t][i];
        ll sm = 0;   
        if (f > 0){
            for(int i{}; i < 32; i++){
                temp[i] -= pref[f-1][i];
            }
        }
        for(int i{}; i < 32; i++){
            if (temp[i] % 2 != 0)
                sm += (1 << i);
        }
        cout << sm << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```