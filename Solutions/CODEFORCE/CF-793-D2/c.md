This is actually quite an easy problem, but it just had a tricky edge cases. So we're given a sequence, and we want to get the maximum LIS length we could, (min(LIS, LIS')). LIS' denote the LIS for the reverse of the array. We can arrange the array arbitarily. To get the best LIS and LIS', we obviously need to somehow divide the array into two increasing sequences. In order to get such an array, we could simply divide the array into two increasing sequence, with a little bit of greedy. And another observation is that these two sequence can at most share up to one element.
```
Think of this sitiaton

1 1 2 2 3

We could actually arrange to

1 2 3 2 1

LIS = 1 2 3 
LIS' = 1 2 3

This is the part where I missed, I just thought that the only element that we could/would share is the largest element, but apparently this is wrong and naive.

Okay, before that, let's talk about why they would only share one element, not two. Because it's impossible to have two element from an increasing sequence, to be reversed.

1 2 3

If you reversed this array you get,

3 2 1

Clearly, the only increasing sequence after reversing the array, is the single element itself.

Now with this one counter example, you will know that why it's not always optimal to just share the largest element

1 1 2 3 3

to

3 1 2 3 1

If we only share the biggest element, we will get 2 in fact, but the above array gives us 3.

So the idea, is to literally try every element in one array(the one that is longer), and see if it already existed in the other array, if it doesn't exist in the other array, then we can definitely insert into it. And that's essentially it. If we found such an element, than the array with the minimum length can +1.
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
        int n;
        cin >> n;
        vi a(n);
        for(auto& i : a) cin >> i;
        sort(all(a));
 
        vi lis;
        vi lis_rev;
        for(int i{}; i < n; i++){
            if (sz(lis) <= sz(lis_rev)){
                if (!sz(lis) || a[i] > lis[sz(lis)-1]) lis.pb(a[i]);
                else if (!sz(lis_rev) || a[i] > lis_rev[sz(lis_rev)-1]) lis_rev.pb(a[i]);
            }else{
                if (!sz(lis_rev) || a[i] > lis_rev[sz(lis_rev)-1]) lis_rev.pb(a[i]);
                else if (!sz(lis) || a[i] > lis[sz(lis)-1]) lis.pb(a[i]);
            }
        }
 
        if (n <= 2) cout << 1 << '\n';
        else {
            bool found = 0;
            //Let lis be the longest array
            if (sz(lis) < sz(lis_rev)) swap(lis, lis_rev);
            for(int i{}; i < sz(lis); i++){
                int index = lower_bound(all(lis_rev), lis[i]) - lis_rev.begin();
                if (index == sz(lis_rev) || lis_rev[index] != lis[i]) found = 1;
            } 
            cout << min(sz(lis), sz(lis_rev)+found) << '\n';
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

The [editorial](https://codeforces.com/blog/entry/103097) has a much better approach.

```cpp
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        ++mp[x];
    }
    int single = 0, doble = 0;
    for(auto &[i, j]:mp) {
        single += j == 1;
        doble += j > 1;
    }
    cout << doble + (single + 1) / 2 << "\n";
    return 0;
```

