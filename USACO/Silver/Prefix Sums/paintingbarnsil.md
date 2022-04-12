2D difference array problem.<br>
The problem statement is stupid anyways, I don't know if it's that I misread something. But, the corner of the painted area should've been inclusive, but somehow, it's not inclusive.
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
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 

int diff[1002][1002];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i{}; i < n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++;y1++;x2++;y2++;
        diff[y1][x1]++;
        diff[y2][x1]--;
        diff[y1][x2]--;
        diff[y2][x2]++;
    }

    int ans = 0;
    for(int j{1}; j <= 1000; j++){
        for(int i{1}; i <= 1000; i++){
            diff[i][j] += diff[i-1][j];
        }
    }
    for(int i{1}; i <= 1000; i++){
        for(int j{1}; j <= 1000; j++){
            diff[i][j] += diff[i][j-1];
            if (diff[i][j] == k)ans++;
        }
    }
    cout << ans;

}

int main(){
    setio("paintbarn");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```