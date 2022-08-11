This is one tough problem, my initial approach , which is to move the pointer into the space one by one, is obviously wrong, I just couldn't figure out a nice approach, if I were to do that the time complexity would not just be O(N), but much bigger. Anyways, here are the solution : 
<br>
(Sleep Cow Herding)[https://youtu.be/BvgV7f3pwcI]
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
    vector<int> a(n);
    for(auto& i : a) cin >> i;

    sort(all(a));

    //check if the condition exist
    int mn = 0;

    int p1 = 0, p2 = 1;
    while (p2 < n){
        if (a[p1] + n - 1>= a[p2]){
            p2++;
        }else{
            mn = max(mn, p2-p1);

            p1++;
        }
    }

    mn = n - max(mn, n-p1);

    if ((a[n-2] - (a[0] - 1) + 1 == n && a[n-1] - a[n-2] - 1 > 1)|| (a[n-1] - (a[1] - 1) + 1 == n && a[1] - a[0] - 1 > 1)){
        mn = 2;
    }

    cout << mn << '\n';
    cout << max(a[n-2]-a[0]-1-(n-3), a[n-1]-a[1]-1-(n-3));
}
 
int main(){
	setio("herding");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```