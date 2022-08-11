For this problem, it was half luck tbf. The state is obvious, it's the \[day\]\[activity we do on that day\]. It's necessary to compute all the path, but in a more efficient way. The only restriction on this problem is that we cannot do an activity on two consecutive days. So the idea is basically to choose the previous day that is a different activity and has a maximum points.
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

const int MAX = 1e5 + 5;
int dp[MAX][3];

void solve(){
    int n;
    cin >> n;
    vector<vi> arr(n);
    for(int i{}; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a,b,c};
    }

    for(int i{}; i < 3; i++){
        dp[0][i] = arr[0][i];
    }

    for(int i{1}; i < n; i++){
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);

        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);

        dp[i][2] = arr[i][2] + max(dp[i-1][1], dp[i-1][0]);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```