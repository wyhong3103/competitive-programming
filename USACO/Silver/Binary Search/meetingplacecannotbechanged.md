Good problem, learned quite a things from it! Here i am going to explain how I came with this approach and all.
```
First , as always, we're going to look for a thing that is monotonic, that means it should be FFFFFFFTTTTTT something like this. The only value that can be a monotonic function is the time itself, binary searching the coordinates ain't a sane choice, because it ain't monotonic.

So, with that observation, we can start looking into things.

So how do we know if the friends can meet each other in a certain time?

Well we know that, one can travel south or north. So the maximum coordinate it can travel is within the range. We can use a difference array to keep track of where can it be. We don't need the actual coordinate, but rather the compressed coordiante. 

So to determine whether one can gather at one place, we simply need to process the difference array and check if there's a moment where there are n objects.

And that basically it.

```
Key takeaway:
- Whenever encounter such a precision problem that involved a precision of 1e-6 or something, we should use this as everything taht requires changing the border, for example, binary search region is shrinked by the unit of 1e-6.
- Use difference array, whenever encounter such a problem, that requires to find the number of element in a range or something!
- Use a normal binary search where we change high to mid - unit , low to mid + unit, when we encounter such a problem, use an extra variable to store the answer instead of printing the low, my code failed for the first 3-4 times, because of this. 
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
 
const int MAX = 60005;
int a[MAX];
int v[MAX];

bool valid(double t, int n){
    vector<double> indices; 
    vector<pair<double, double>> updates;
    //Coordinate Compression
    for(int i{}; i < n; i++){
        double dist = v[i] * t;
        indices.pb(a[i] + dist + 0.0000001);
        indices.pb(a[i] - dist);
        updates.pb({a[i]-dist, a[i]+dist+0.0000001});
    }
    vi diff(sz(indices));

    sort(all(indices));

    for(auto& i : updates){
    	//Getting compressed coordinate
        int f = lower_bound(all(indices), i.fir) - indices.begin();  
        int t = lower_bound(all(indices), i.sec) - indices.begin();
        diff[f]++;
        diff[t]--;
    }

    int count = 0;
    for(auto& i : diff){
        count += i;
        if (count == n) return true;
    }
    return false;
}



void solve(){
    int n;
    cin >> n;

    pi range{INT_MAX,0};
    for(int i{}; i < n; i++){
        cin >> a[i];
        range.fir = min(range.fir, a[i]);
        range.sec = max(range.sec, a[i]);
    }

    for(int i{}; i < n; i++){
        cin >> v[i];
    }

    double lo = 0, hi = range.sec - range.fir;
    double ans = range.sec-range.fir;
    while (hi >= lo){
        double mid = lo + (hi-lo)/2;
        if (valid(mid, n)){
            ans = min(ans, mid);
            hi = mid - 0.0000001;
        }else{
            lo = mid + 0.0000001;
        }
    }
    cout << setprecision(7) << fixed << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
``