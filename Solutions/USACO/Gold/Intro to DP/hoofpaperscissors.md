The idea is to simply brute force it, but with memoization.
```
state = i-th game, how many k left, gesture used
```
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

const int MXN = 1e5+5;


//0 = hoof, 1 = paper, 2 = scissor
int memo[MXN][21][3];
int N, K;

int recur(vi& a, int i, int k, int cur){
    if (i >= N) return 0; 

    if (memo[i][k][cur] != -1) return memo[i][k][cur];

    int& score = memo[i][k][cur] = 0;

    switch(a[i]){
        case 0:
            score += cur == 1;
            break;
        case 1:
            score += cur == 2;
            break;
        case 2:
            score += cur == 0;
            break;
    }

    int mx = 0;
    if (k){
        if (cur != 0) mx = max(mx, recur(a,i+1, k-1, 0));
        if (cur != 1) mx = max(mx, recur(a,i+1, k-1, 1));
        if (cur != 2) mx = max(mx, recur(a,i+1, k-1, 2));
    }

    mx = max(mx, recur(a,i+1, k, cur));

    score += mx;

    return score;
}

void solve(){
    cin >> N >> K;

    memset(memo, -1, sizeof(memo));
    
    vi a(N);

    for(int i{}; i < N; i++){
        char c;
        cin >> c;
        switch(c){
            case 'H':
                a[i] = 0;
                break;
            case 'P':
                a[i] = 1;
                break;
            case 'S':
                a[i] = 2;
                break;
        }
    }

    cout << max({recur(a, 0, K, 0), recur(a, 0, K, 1), recur(a, 0, K, 2)});
}

int main(){
    setio("hps");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```