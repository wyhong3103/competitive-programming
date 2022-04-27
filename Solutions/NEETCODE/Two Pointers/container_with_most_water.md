The reason that this algorithm works, is because that, it is almost guaranteed that as long as you have a taller line, you can get your max area, as long as it's taller than the shorter line, so the idea is basically, if the line that the pointer is pointing to is shorter we move foward/backward, depends on which pointer we're using. We will always prioritize having a tall line, until we find a taller one then only we move.
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
 
void solve(){ 
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;

    int l = 0, r = n-1;

    int area = 0;
    while (l <= r){
        area = max(area, ((r-l) * min(a[r], a[l])));
        if (a[r] > a[l]){
            l++;
        }else{
            r--;
        }
    }
    cout << area;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```