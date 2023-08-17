
## Abridged Statement
Given a binary array that is of length $n$ for $n \leq 3000$. Denote $l_0$ as the maximal length of consecutive $0$s, and $l_1$ as the maximal length of consecutive $1$s in the array. The score of the array is $a \cdot l_0 + l_1$. You have $k$ operations, in each operation you can flip a bit. Find the answer for $a = 1, 2, ..., n$, such that you cannot use more than $k$ operations.

## Approach

Let's first denote $mx[i]$ as maximal $l_1$ when $l_0 = i$ if we have used no more than $k$ operations on the array. If we have this $mx$ array, we can answer each $a$ independently by bruteforcing the answer for each possible $l_0$, with the $mx[i]$ array. This will give us the optimal answer for each query because, when $l_0 = i$, we have the max $l_1$, there can be no answer better than it when $l_0 = i$. This will take $O(N^2)$, which will fit into the time limit.

But, how do we get $mx$ array?

Let's first discuss about finding the segment that has the maximal $l_0$ that ends before or at $i$ and used at most $j$ operations, for $1 \leq i \leq n$ and $0 \leq j \leq k$. Notice that for each index $i$, to maximize the segment that has $l_0$ that ends at $i$, while having $j$ operations, is to simply toggle the first $j$ number of $1$s (starting in reverse from $i$). This way we can get the maximal consecutive segment of $0$ that ends at $i$ with $j$ operations.

Let's denote $pfz[i][j]$ (**p**re**f**ix **z**ero) as $l_0$ such that the segment ends at $i$ and used $j$ operations.

We can also use the similar technique to find maximal length of segment that **starts** at $i$ and used $j$ operations, let's call that $sfz[i][j]$ (**s**u**f**six **z**ero).

Do the same for $1$ as well, and denote the similar array as $pfo[i][j]$ and $sfo[i][j]$.

There are many ways to implement the above, what I did was using binary search with a prefix sum array, to compute them, time comeplexity for this is $O(N^2 \log N)$

We're not quite there yet, 

$pfz[i][j]$ is currently $l_0$ such that the segment ends at $i$ and used $j$ operation. To make the process of finding $mx$ smoother, we can change $pfz[i][j]$ to the maximal $l_0$ such that the segments ends **before or at** $i$ and **used at most** $j$ operations.

This can be done easily by using the transition below,

$$pfz[i][j] = max(pfz[i][j], pfz[i-1][j], pfz[i][j-1])$$

$$sfz[i][j] = max(sfz[i][j], sfz[i+1][j], sfz[i][j-1])$$

(Same goes to $sfo$ and $pfo$)

With all the above, we can start finding $mx[i]$ now.

In a setting where $l_0, l_1 \geq 1$, the segment of $l_0$ and $l_1$ is disjoint, and either $0$ comes first or $1$ comes first.

So to find $mx$, we can do the transition below,

For the situation when segment with $l_0$ comes before $l_1$.

$$mx[pfz[i][j]] = max(mx[pfz[i][j]], sfo[i+1][k-j])$$

Otherwise,

$$mx[sfz[i][j]] = max(mx[sfz[i][j]], pfo[i-1][k-j])$$

Once we obtained this array, we can answer $a = 1, 2, ..., n$ independently by iterating through each $i$, and find the max of $a * i + mx[i]$.
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vi zeros(n);

    for(int i{}; i < n; i++){
        zeros[i] = s[i] == '0';
        if (i) zeros[i] += zeros[i-1];
    }

    vector<vi> pfz(n, vi(k+1));
    vector<vi> sfz(n, vi(k+1));
    vector<vi> pfo(n, vi(k+1));
    vector<vi> sfo(n, vi(k+1));

    // zero
    for(int i{}; i < n; i++){
        for(int j{}; j <= k; j++){
            //if number of 1s is smaller than number to change
            if (i+1 - zeros[i] <= j){
                pfz[i][j] = i+1;
            }else{
                int lo = 0, hi = i;
                while (hi > lo){
                    int mid = lo + (hi-lo+1)/2;
                    if (i-mid+1 - (zeros[i] - (!mid ? 0 : zeros[mid-1])) >= j+1){
                        lo = mid;
                    }else hi = mid - 1;
                }
                pfz[i][j] = i - lo;
            }
        }
    }
    for(int i{n-1}; i >= 0; i--){
        for(int j{}; j <= k; j++){
            //if number of 1s is smaller than number to change
            if (n - i - (zeros[n-1] - (!i ? 0 : zeros[i-1])) <= j){
                sfz[i][j] = n-i;
            }else{
                int lo = i, hi = n-1;
                while (hi > lo){
                    int mid = lo + (hi-lo)/2;
                    if ((mid-i+1) - (zeros[mid] - (!i ? 0 : zeros[i-1])) >= j+1){
                        hi = mid;
                    }else lo = mid + 1;
                }
                sfz[i][j] = lo - i;
            }
        }
    }

    for(int i{}; i < n; i++){
        for(int j{}; j <= k; j++){
            //if number of 1s is smaller than number to change
            if (zeros[i] <= j){
                pfo[i][j] = i+1;
            }else{
                int lo = 0, hi = i;
                while (hi > lo){
                    int mid = lo + (hi-lo+1)/2;
                    if ((zeros[i] - (!mid ? 0 : zeros[mid-1])) >= j+1){
                        lo = mid;
                    }else hi = mid - 1;
                }
                pfo[i][j] = i - lo;
            }
        }
    }
    for(int i{n-1}; i >= 0; i--){
        for(int j{}; j <= k; j++){
            //if number of 1s is smaller than number to change
            if ((zeros[n-1] - (!i ? 0 : zeros[i-1])) <= j){
                sfo[i][j] = n-i;
            }else{
                int lo = i, hi = n-1;
                while (hi > lo){
                    int mid = lo + (hi-lo)/2;
                    if ((zeros[mid] - (!i ? 0 : zeros[i-1])) >= j+1){
                        hi = mid;
                    }else lo = mid + 1;
                }
                sfo[i][j] = lo - i;
            }
        }
    }

    for(int i{}; i < n; i++){
        for(int j{}; j <= k; j++){
            if (i){
                pfz[i][j] = max(pfz[i][j], pfz[i-1][j]);
                pfo[i][j] = max(pfo[i][j], pfo[i-1][j]);
            }
            if (j){
                pfz[i][j] = max(pfz[i][j], pfz[i][j-1]);
                pfo[i][j] = max(pfo[i][j], pfo[i][j-1]);
            }
        }
    }

    for(int i{n-1}; i >= 0; i--){
        for(int j{}; j <= k; j++){
            if (i < n-1){
                sfz[i][j] = max(sfz[i][j], sfz[i+1][j]);
                sfo[i][j] = max(sfo[i][j], sfo[i+1][j]);
            }
            if (j){
                sfz[i][j] = max(sfz[i][j], sfz[i][j-1]);
                sfo[i][j] = max(sfo[i][j], sfo[i][j-1]);
            }
        }
    }

    vi mx(n+1, -1);

    for(int i{}; i < n; i++){
        for(int j{}; j <= k; j++){
            if (i < n-1) mx[pfz[i][j]] = max(mx[pfz[i][j]], sfo[i+1][k-j]);
            if (i) mx[sfz[i][j]] = max(mx[sfz[i][j]], pfo[i-1][k-j]);
        }
    }

    if (zeros[n-1] <= k){
        mx[0] = n;
    }
    if (n - zeros[n-1] <= k){
        mx[n] = 0;
    }

    for(int i{}; i < n; i++){
        int ans = 0;
        for(int j{}; j <= n; j++){
            if (mx[j] != -1) ans = max(ans, j * (i+1) + mx[j]);
        }
        cout << ans << ' ';
    }
    cout<< '\n';

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