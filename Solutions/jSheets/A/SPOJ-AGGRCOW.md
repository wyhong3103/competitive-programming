This problem took me quite a while for thinking how to approach it with binary search. This problem is alright, it's probably because of the lesson I learned from the previous problem. Alright so basically, this probelm is about looking for the maximal minimum distances between cows.
<br>
Approach : 
- For this particular problem, it wasn't really about placing your cow 1 by 1 and form the solution. I realized that binary search that applied to these type of problems, are quite similar with the idea of complete search. Because all we're doing is basically reducing the search space by log n. 
- So the approach is, to test every distance we set, for example, we start by testing distance 1,which means placing each cow at least a distance of 1, if it's feasible to place cow with a minimum of distance 1, a function called valid(), will return true.
- With this approach, we can use binary search to reduce the search space for the distance that is true. And we're essentially looking for the last true, we can find, because that's the maximum.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

bool valid(vector<ll>& stall, ll dist, int c){
    ll margin = stall[0];
    c--;
    for(auto& i : stall){
        if (i - margin >= dist){
            margin = i;
            c--;
        }
        if (!c) break;
    }
    return (c ? false : true);
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;

        vector<ll> stall(n);
        for(auto& i : stall) cin >> i;
        sort(all(stall));

        int lo = 0, hi = stall[n-1]; //A better way is to set hi = stall[n-1] - stall[0]
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (valid(stall, mid, c)){
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        cout << lo << '\n';
    }
}

int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```