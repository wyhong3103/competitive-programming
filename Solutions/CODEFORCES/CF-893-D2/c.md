## Abridged Statement

Find a permutation $p$ that consist of integers from $1$ to $n$ such that has the maximal number of distinct integers in $d$ such that $d_i = gcd(p_i, p_{(i \mod n) + 1})$.

## Approach

Let's prove that we can always have at least $\lfloor \frac{n}{2} \rfloor$. There are $\lfloor \frac{n}{2} \rfloor$ even numbers, which can be represented as $2x$, and $gcd(2x, x) = x$. And that proves that we can always have at least $\lfloor \frac{n}{2} \rfloor$ distinct $d_i$. Now let's prove that the answer will not be more than that. Let's assume there exist a number $c, 1 \leq c \leq n$ that is not included in the previous operation, that means $2 \cdot c$ definitely does not exist in the permutation, which means there is no number $x, x \gt c$ such that $gcd(c, x) = c$.

Now we just need a way to properly arrange the numbers. We can simply start with the smallest number that is not in the array at anytime, append it to the array and keep multiplying it by 2 and append it, until the number is greater than $n$, and repeat the entire step.

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
    int n;
    cin >> n;

    vi used(n+1);
    for(int i{1}; i <= n; i++){
        if (used[i]) continue;
        used[i] = 1;
        for(int j{i}; j <= n; j *= 2){
            cout << j << ' ';
            used[j] = 1;
        }
    }
    cout << '\n';
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