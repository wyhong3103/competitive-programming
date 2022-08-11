This problem is very cool ! So the idea of this problem is about splitting the road into segments and segments by inserting traffic lights. And in each splitting process, we need to find the longest passage without a traffic lights.
```
For example

8 3
3 6 2

x = 8, n = 3

p = 3, 6, 2

x is the length of the roads


So initially we have this


0 1 2 3 4 5 6 7 8

And first insert a traffic lights at p = 3
	  |
0 1 2 3 4 5 6 7 8

So the longest passage we have in here is 5

Next insert at 6
	  |	    |
0 1 2 3 4 5 6 7 8

Longest is 3

Lastly insert at 2

	| | 	|
0 1 2 3 4 5 6 7 8

------------------------------------------------------------------------
To solve this problem , we simply need a sorted set, and a sorted map!

Sorted set is used to keep track of the traffic lights, a sorted map with length of the segment as a key and a set of pair as the value, it is used to keep track of the length of each segments

Notice that everytime, we insert a traffic light, we only need to seek for the closest end and head,and then we split it

So the idea is to start with a set with only {0, x}, and map with only {x-0 : {{0, x}} (length of the segment : set of starting, ending points)

Everytime we insert a traffic light we only need to search for it's head and tail(closest), we can simply search for the tail using lower_bound or upper_bound, it doesn't matter here since, all p is distinct and > 0 , < x,  and the head by doing a subtraction on the pointer of the tail

With that, first, we need to remove this segment from the map, all we need to do is search for it's length, and remove the pair from the set, notice that we're using set in here, so everything only takes O(log n) which is incredibly fast. If the set became empty, we simply erase it from the map.

After that we need to insert location p (of the new traffic light) to the sorted set that keeps track of traffic lights.

And we simply print the last element in the map, (which is the longest length)
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
    int x, n;
    cin >> x >> n;

    set<int> tl = {0, x};
    map<int, set<pi>> m;
    m[x-0].insert({0, x});
    for(int i{}; i < n; i++){   
        int p;
        cin >> p;
        auto itr = tl.lower_bound(p);
        auto itl = --(tl.lower_bound(p));
        m[*(itr) - *(itl)].erase({*(itl), *(itr)});
        if (m[*(itr) - *(itl)].empty()){
            m.erase(*(itr) - *(itl));
        }
        m[*(itr) - p].insert({p, *(itr)});
        m[p - *(itl)].insert({*(itl), p});
        tl.insert(p);
        cout << (--(m.end()))->fir << ' ';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```