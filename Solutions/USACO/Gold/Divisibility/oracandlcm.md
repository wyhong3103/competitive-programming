Took me a while to figure out the solution but okay....
```
Before we start discussing the solution, there's 2 thing we need to know


LCM = prime_factor_1 ^ max(power1, power2) * prime_factor_1 ^ max(power1, power2).... prime_factor_k ^ max(power1, power2)

GCD = prime_factor_1 ^ min(power1, power2) * prime_factor_1 ^ min(power1, power2).... prime_factor_k ^ min(power1, power2)


And for this problem, we know that we are to find the gcd of all LCM of every pairs of number

First observation, 

in order for a prime factor(2, 3, 5, 7....) to be part of the GCD, every numbers must have the prime factor

So in order for this to occur, every number pair must have the prime factor, and there can at most be 1 number that doesn't have the prime factor, For example, if we have

1 2 4

Although 1 doesn't have a factor of 2, but after LCM'ed all of them, we will get

2 4 4

But if we have 

1 1 2 4

lcm of 1 and 1, is still going to be 1

So from this we know that there must be at least n-1 numbers have that prime factor, in order for it to be consider as part of the GCD

Next observation,

Say 2 is guaranteed to be part of the GCD, but how many 2 there is to consider??

1 2 4 gives us 2 4 4 , which GCD = 2

2 2 4 gives us 2 4 4 as well, which GCD = 2

2 4 4 gievs us 4 4 4, which GCD = 4

So what's going on here?

Notice that, we only want the minimum power of 2 among all of the new numbers, 

when there's n-1 numbers that has the power of 2, the GCD for poweer of 2 is guaranteed to be the lowest power of 2 available in the original array

But when all the numbers has a power of 2, the GCD is not going to be the minimum of them all, but, the 2nd minimum. 2 4 gives us 4 as LCM, 2 2 gives us 2 as LCM.
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
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;
    
    //{prime factor : frequency of occurence of the i-th power}
    map<int, vi> freq;
     
    for(auto& i : a){
        map<int,int> factor;
        for(int j{2}; j*j <= i; j++){
            while(i % j == 0){
                i /= j;
                if (!factor.count(j)) factor[j] = 0;
                factor[j]++;
            }
        }
        if (!factor.count(i)) factor[i] = 0;
        factor[i]++;

        for(auto& i : factor){
            if (!freq.count(i.fir)){
                freq[i.fir].resize(32);
            }
            freq[i.fir][i.sec]++;
        }
    }

    ll ans = 1;
    for(auto& i : freq){
        pi mn{-1,-1};
        int cnt = 0;
        for(int j{}; j < 32; j++){
            cnt += i.sec[j];
            if (i.sec[j]){
                if (i.sec[j] >= 2){
                    if (mn.fir == -1){
                        mn.fir = j;
                        mn.sec = j;
                    }
                }
                if (mn.fir == -1){
                    mn.fir = j;
                }
                else if (mn.sec == -1) mn.sec = j;
            }
        }
        if (cnt >= n-1){
            for(int j{}; j < (cnt == n ? mn.sec : mn.fir); j++) ans *= i.fir;
        }
    }

    cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```