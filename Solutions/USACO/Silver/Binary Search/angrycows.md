An angry cow can blast every haybales that is within it's radius, so we basically need to binary search the minimum distance between one haybale and another, and make sure the total need of cows is <= k. To test that, we can basically just find how many group of cows are within the range of radius, from i-th cow to j-th cow, at max 2 * radius distance.
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

bool valid(set<int>& s, int r, int k){
    ll total = 0;
    int cur = 0;
    for(auto& i : s){
        if (!cur) cur = i;
        else{
            if (i - cur > (2*r)){
                cur = i;
                total++;
            }
        }
    }
    if (cur) total++;
    return total <= k;
}


void solve(){ 
    int n, k;
    cin >> n >> k;

    set<int> s;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    ll lo = 1, hi = (*(--s.end())) - (*(s.begin()));
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;
        if (valid(s, mid, k)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    cout << lo;
}
 
int main(){
    setio("angry");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```