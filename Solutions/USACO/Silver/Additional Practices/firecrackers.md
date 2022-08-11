This problem is simply about greedy/sorting, at least for me, I've used sorted map to solve this problem. It can be done more efficiently using binary search.
```
So first, let's talk about a few observations I made

The distance of the hooligan and the guard will always be the same, if the hooligan choose to move away from the guard, since guard is going to move one step toward everytime. So the maximal number of firecrackers we can place is actually the distance between the hooligan and the guard, because think of it this way, if the hooligan decides to place a firecracker no matter where he is, the guard is going to get closer to him anyways, and eventually the guard will be next to him, so it really doesn't unnecessary for the hooligan to move. We just have to keep track of the movement of the guard, the idea is to place as many firecrackers as possible first, then only start moving after the guard is one step away to catch the hooligan.

So with these observations, we knew the maximum number of firecrackers we can place, but what about the explosion time. We're only going to consider explosion happens before hooligan got caught. We know that we're going to place as many fire crackers as we could then only start running to the edge(when the guard is next to the hooligan), the firecracker that is going to explode is literally, firework that can explode in the time for the guard to reach the last cell, because that's when the hooligan is going to get caught.

To get the optimal firecrackers, we can use sorted maps to get it.
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
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
 
        map<int,int> mp;
        for(int i{}; i < m; i++){
            int s;
            cin >> s;
            if (!mp.count(s)) mp[s] = 0;
            mp[s]++;
        }
 
        int res = 0;
        int total = abs(a-b)-1;
        //The maximum number of fire crackers we can place
        int temp = b;
        while(total--){
            int lim = (a > b ? n-temp : temp-1)-1;
            //Time for guard to catch hooligan at the edge
            auto it = mp.upper_bound(lim);
            if (it == mp.begin()) break;
            it--;
            if (it->fir <= lim){
                res++;
                it->sec--;
                if (it->sec == 0){
                    mp.erase(it->fir);
                }
            }else break;
 
            temp += (a > b ? 1 : -1);
            //Guard moves closer to hooligan
        }
 
        cout << res << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```