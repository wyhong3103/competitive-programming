```

I did not solve this problem on my own, I solved it with hints from Editorial.

It has a pretty interesting idea.

First we split the holes into n/k buckets, as usual, k is sqrt(n).

for each hole i, we store next[i], power[i], jump[i]

next[i] is the first hole that we can reach from i that is not in the same bucket, power[i] is the power of hole i, jump[i] is the number of jumps to reach next[i]

For next[i] that is >= N, we can just mark it as -1. Basically, every holes in the last bucket will have next[i] = -1.

We can preprocess this in O(N)


Update query

When we update power[i], what will be affected is the holes that can reach hole i and that is in the same bucket.

So the idea is we iterate from i to floor(i/k) * k (decreasing order), prorcess every cell

Time complexity = O(k ~ sqrt(n))

Answer query

It takes no more than n/k ~ sqrt(n) to reach last bucket, in the last bucket, because we need to know the last hole that we can reach, so in the last bucket, we need to do another no more than sqrt(n) jumps, to manually count it.

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
int n, m, k;

struct Data{
    int p, j, t;
};

void preprocess(int i, vector<Data>& a){
    if (a[i].p + i >= n){
        a[i].j = 1;
        a[i].t = -1;
    }
    else if ((a[i].p + i) / k != i / k){
        a[i].j = 1;
        a[i].t = a[i].p + i;
    }else{
        preprocess(a[i].p + i, a);
        a[i].j = 1 + a[a[i].p+i].j;
        a[i].t = a[a[i].p+i].t;
    }
}

void solve(){
    cin >> n >> m;

    int lo = 1, hi = 400;
    while (hi > lo){
        int mid = lo + (hi-lo+1)/2;
        if (mid * mid <= n) lo =mid;
        else hi=mid-1;
    }
    k = lo;

    vector<Data> a(n);

    for(int i{}; i < n; i++){
        cin >> a[i].p; 
    } 

    for(int i{}; i < n; i++){
        if (!a[i].j){
            preprocess(i, a);
        }
    }

    while (m--){
        int t;
        cin >> t;
        if (t == 0){
            //change a[i].p to x
            int i, x;
            cin >> i >> x;
            i--;
            a[i].p = x;

            for(int j{i}; j >= (i/k) * k; j--){
                if (a[j].p + j >= n){
                    a[j].j = 1;
                    a[j].t = -1;
                }
                else if ((a[j].p + j) / k != i / k){
                    a[j].j = 1;
                    a[j].t = a[j].p + j;
                }else{
                    a[j].j = 1 + a[a[j].p+j].j;
                    a[j].t = a[a[j].p+j].t;
                }
            }
        }else{
            int i;
            cin >> i;
            i--;
            
            int at = i;
            int cnt = 0;
            while (a[at].t != -1){
                cnt += a[at].j;
                at = a[at].t;
            }

            while (true){
                cnt++;
                if (at + a[at].p < n) at += a[at].p;
                else break;
            }

            cout << at+1 << ' ' << cnt << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```