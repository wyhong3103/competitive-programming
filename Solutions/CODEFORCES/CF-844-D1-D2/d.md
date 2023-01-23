```

We're to find the maximal squareness an x can produce.

squareness = number of ai+x that is perfect square for each ai in array a.

Let's first look at the perfect square sequence.

1 4 9 16 25 ....

it is no coincidence that diff between each consecutive is an odd number, and the diff is a sequence of {1, 3, 5, 7 ...}

With the above observation, we can say that, ai and aj can both be a perfect square at the same time (after + x), if their difference is the sum of contiguous part of the sequence {1, 3, 5, 7 ...}

Also, notice that, there are multiple ways for ai and aj to be perfect square.

For example, 

When difference is 15, it can be sum of {3, 5, 7} or just {15}

Also, we define starting point as the first number in the contiguous part of the sequence that produces the sum.

Let's generalize this, for y numbers (sorted), they can all be perfect square at the same time (after + x), if for the i-th number (i > 0), the difference between it and 0-th number is a sum of contiguous part of the sequence of odd numbers and has the same starting point as all the other number

But, how do we do the above efficiently? (How do we find all the solution that produces the sum)

sum of first i numbers in the odd number sequence is basically i^2.

Can we iterate through the size of the part, and then find the starting point that could produce the sum? 

Notice that, the sum of contiguous part of size c, is going to increase, as we increase the starting point. Can we do binary search??

Let's find the maximal size c first.

maximal difference between a[i] and a[j] is 1e9. And sqrt(1e9) ~ 32000, so c wont go above this number.

But still 50*50*32000*32 is around a billion, we need to be faster.

Turned out we can solve this equation easily.

(i+c)^2 - i^2 = d

i^2 + 2ci + c^2 - i^2 = d

2ci + c^2 = d

i = (d-c^2)/(2c)

Sum exists if i is an integer!

Solution

We can fix the i-th number as the smallest perfect square, and then iterate through number that is > i-th number, find all the possible starting points, answer is simply the most perfect square a starting point contains.

Fixing i-th number, essentially means, i-th number must be perfect square. So we fix every i-th number, there is no need to see if the previous numebr (that is smaller) can be perfect square with the current number, because if let's say they would, we would've found the answer previously.
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
    int n;
    cin >> n;
   
    vi a(n);
    for(auto& i :a) cin >> i;

    int mx = 0;
    for(int i{}; i < n; i++){
        unordered_map<ll,int> start;
        for(int j{i+1}; j < n; j++){
            for(ll k{1}; k < 32000; k++){
                if (a[j]-a[i] < k * k){
                    break;
                }else{
                    ll num = a[j]-a[i]-k*k;
                    ll denom = 2*k;
                    if (num % denom == 0 && a[i] <= (num/denom) * (num/denom)){
                        start[num/denom]++;
                        mx = max(mx, start[num/denom]);
                    }
                }
            }
        }
    }

    cout << mx+1 << '\n';
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