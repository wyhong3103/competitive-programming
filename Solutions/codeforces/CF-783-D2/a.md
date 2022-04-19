Stuck in this problem for a while, because I didn't understand the problem statement at the very first 20 minutes. So the idea is we're given a rectangle, with n rows, m columns, we need to reach the bottom right corner. And we cannot make 2 consecutive moves that is the same, eg. up up, we can move in 4 directions.
```
I know there's a better solution, but anyways, here's mine

So basically, I have split it into 3 cases

Case #1

n is 1 but m > 2

m is 1 but n > 2

With these, you basically cannot reach to the corner, because you will get out of grid, and since you cannot make 2 consecutive move, so no, it's basically a number line, the best you can move is right or left 1 times, or up down 1 time


Starting from case #2, we will focus on moving diagonally first

Case #2

n >= m 

if n >= m, that means the biggest square inside the rectangle is m * m, so we will move to (m,m) first, and to reach (m,m), it's actually the manhattan distance, simply abs(y1 - y2) + abs(x1 - x1), since both x and y is m here so it's (m-1) * 2, -1 because we're starting from 1

Now we've reach the (m,m), to reach (n,m) , we have to move downward, after a few experiment, I've found out that, to move vertically downward, takes (m-n) * 2, and -1 or don't depends on whether (m-n) is odd or even

Then the final answer is diagonal move + vertical move

Case #3

m >= n

Same as case #2, we first reach the biggest square, which is (n, n), and now we will move horizontally to the destination, to reach there it's also  (m-n) * 2, and -1 or don't depends on whether (m-n) is odd or even

And the answer is the same

```
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
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
 
        if ((n == 1 && m > 2 )|| (m == 1 && n > 2)){
            cout << -1 << '\n';
            continue;
        }else if (n >= m){
            ll diagonal = (m-1)*2;
            ll vertical = (abs(m-n)*2) - ((n-m) % 2 == 0 ? 0 : 1);
            ll ans = diagonal + vertical;
            cout << ans << '\n';
        }else{
            ll diagonal = (n-1)*2;
            ll horizontal = (abs(m-n)*2) - (abs(n-m) % 2 == 0 ? 0 : 1);
            ll ans = diagonal + horizontal;
            cout << ans << '\n';
        }
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```