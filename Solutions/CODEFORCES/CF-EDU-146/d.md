```

Worst case = n

Fix an element i

Create an array a of size 2 * k + 1 to store the value from [f[i]*d[i]-k, f[i]*d[i]+k]

i-th element is at position k


for every element j, there are only 3 optimal position 

position 1 = (f[i]*d[i])/f[j] * f[j]
position 2 = ((f[i]*d[i])/f[j]+1) * f[j]
position 3 = f[j] * d[j]

It either try to be as close to element i (left and right) or stay at its own position

For 3 of the positions that has a distance <= k between f[i]*d[i], we store {j, 1} at (p*f[j] - f[i]*d[i]-k), if p == d[j] if p == d[j] otherwise  {j, 0}, we have {j, 1} because we could tell when position j has the original element.


We iterate through every segment of length k+1, if every element is present in that segment, our answer is simply the n-number of original elmeents in that segment.

Answer is min of them.


```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, k;
    cin >> n >> k;
    
    vll a(n), b(n);
 
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
 
    int mn = n;
    for(int i{}; i < n; i++){
        vector<vector<pi>> at(k * 2 + 1);
        at[k].pb({i, 1});

        for(int j{}; j < n; j++){
            if (i == j) continue;

            ll p1 = max(1LL, (a[i]*b[i]) / a[j]), p2 = (a[i]*b[i])/a[j] + 1, p3 = b[j];
            if (abs(p1 * a[j] - a[i] * b[i]) <= k){
                at[p1 * a[j] - (a[i]*b[i]-k)].pb({j, 0});
            }
            if (abs(p2 * a[j] - a[i] * b[i]) <= k){
                at[p2 * a[j] - (a[i]*b[i]-k)].pb({j, 0});
            }
            if (abs(p3 * a[j] - a[i] * b[i]) <= k){
                at[p3 * a[j] - (a[i]*b[i]-k)].pb({j, 1});
            }
        }

        int mx = -1;
        vi present(n);
        present[i] = 0;
        int cur = 0;
        int cnt = 0;
        for(int j{}; j <= k; j++){
            for(auto& l : at[j]){
                if (!present[l.fir]) cur++;
                present[l.fir]++;
                cnt += l.sec;
            }
        }

        if (cur == n){
            mx = max(mx, cnt);
        }

        for(int j{}; j < k; j++){
            for(auto& l : at[j]){
                present[l.fir]--;
                if (!present[l.fir]) cur--;
                cnt -= l.sec;
            }

            for(auto& l : at[j+k+1]){
                if (!present[l.fir]) cur++;
                present[l.fir]++;
                cnt += l.sec;
            }
            if (cur == n){
                mx = max(mx, cnt);
            }
        }

        mn = min(mn, n-mx);
    }

    cout << mn << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```



How does this even work???
```

we're given n items, each have fi and di value

we are to find the minimal di we need to change s.t max(fi*di) - min(fi*di) <= k

we can only change di!

worst case = all element are changed, make the lcm of all of them

Solution

We can sort the elements by fi * di first in ascending order.

And then we can use 2 pointers to search for every subarray that has max-min <= k.

For each of that subarray, we can do a O(n log n) checking to see if we can keep the current subarray and change every other element that is not in the subarray to fit in the range.

How to do that?

For each of the elements i that isn't selected, it will either be

ceil(min/f[i]) * f[i] (right border) OR (ceil(min/f[i])-1) * f[i] (left border)

If right border is > max, that means left boder is < min. In this situation, you might be tempted to select the one that is closest to our current max and min, but that is not the case, we have to consider all the other elements.

So we can sort all the unselected elements by the value of their right border in descending order.

Then we can iterate from the largest right border to the smallest, if the current right border - min <= k, that means every element can fit into the range of k, because every element that is unchecked has smaller right border, and right border is guaranteed to be > min.

If right border - min > k, we will have to select the left border for this element, the left border might / might not be the new min of the range. 

At the end just check if max - min <= k.

Also, we have to handle the case when left border = 0, as that cannot happen.

I got a few WAs becase I have overlooked some subarrays when moving the 2 pointers. We need to check every valid subarray of k.


```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, k;
    cin >> n >> k;
    
    vll a(n), b(n);
 
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
 
    vi index(n);
    for(int i{}; i < n; i++) index[i] = i;
 
    sort(all(index),
        [&](int i, int j){
            return (a[i] * b[i] < a[j] * b[j]);
        }
    );
 
    int p1 = 0, p2 = 0;
 
    int mn = n;
    while (p1 < n || p2 < n){
        int i1 = index[p1];
        bool ex = (p2 == n);
        if (a[index[p2-ex]] * b[index[p2-ex]] - a[i1] * b[i1] > k){
            ex = 1; 
        }

        bool ok = 1;
        pll range = {a[i1]*b[i1], a[index[p2-ex]]*b[index[p2-ex]]};
        
        vector<pll> temp;

        for(int i{}; i < p1; i++){
            temp.pb( {
                (((range.fir + (a[index[i]] - 1))/ a[index[i]]) - 1) * a[index[i]], 
                (range.fir + (a[index[i]] - 1))/ a[index[i]] * a[index[i]]
            });
        }
        for(int i{p2+1-ex}; i < n; i++){
            temp.pb( {
                (((range.fir + (a[index[i]] - 1))/ a[index[i]]) - 1) * a[index[i]], 
                (range.fir + (a[index[i]] - 1))/ a[index[i]] * a[index[i]]
            });
        }

        sort(all(temp), 
            [&](pll& a, pll& b){
                return a.sec > b.sec;
            }
        );

        for(auto& i : temp){
            if (max(i.sec, range.sec) - range.fir <= k){
                break; 
            }else{
                range.fir = min(range.fir, i.fir);
            }
        }

        ok &= range.fir != 0 && range.sec-range.fir <= k;

        if (ok){
            mn = min(mn, n-(p2-p1+1-ex));
        }

        if (!ex){
            p2++;
        }else{
            p1++;
        }
    }
    cout << mn << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```