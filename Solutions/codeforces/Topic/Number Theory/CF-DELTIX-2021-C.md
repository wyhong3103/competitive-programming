I've kind of solved this problem using math and number theory. 
```
Okay, so basically this problem is looking for the number of pairs of i and k, (a[i] * a[i+e] * .... * a[i+ke]) could produce a prime number, this is already a very obvious thing, no products can produce prime number unless if it's 1 * 1 * 1 * ... * prime number. So we just literally have to look for such pairs.

This approach is O(n), mayble slightly more than that... But it worked out pretty fast

So the idae is to actually test every i,

For every i, we will test i+e, i+2e until we hit a certain condition,
- We reach the end of the array
- We found a none prime number
- We found another prime number

And we will only visit i, i+e, i+2e.... once. (not really, because there are certain edge cases)

We will have an array that stores the validity of i, that is initialized as -2 in the beginning, if it's assigned as -1, that means that position shouldn't be explore, because the entire sequence doesn't have a prime number

Or else it will be assigned as the index of the prime number of that sequence, we will only visit a certain i again, if that index of the prime number is before i

For example


1 1 1 7 1 1 1 2

1 1 1 7 1 1 1

is a valid sequence

1 1 1 2

is another valid sequence

Okay now let's talk about how do we count the pairs

1 1 1 7 1 1 1

Part of the answer for this is actually just the number of 1s

Because for example, we can start from
first 1 to 7, second 1 to 7 , third 1 to 7... 7 to forth 1, 7 to fifth 1

i = 0, k = 3
i = 1e, k = 2
i = 2e, k = 1
i = 3e, k = 3 
i = 3e, k = 2
i = 3e, k = 1

Well other than this

We can also do 
i = 0 k = 6, i = 0 k = 5, i = 0 k = 4 
i = 1e k = 6, i = 1e k = 5, i = 1e k = 4
i = 2e k = 6, i = 2e k = 5, i = 2e k = 4 

So the answer is actually 
number of 1s + (number of 1s before the prime number * number of 1s after the prime number) 

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

const int MAXPRIME = 1e6 + 1;
bool not_prime[MAXPRIME];
int n, e;

void sieve(){
    for(int i{2}; i <= MAXPRIME; i++){
        if (not_prime[i]) continue;
        for(int j{i+i}; j <= MAXPRIME; j+=i){
            not_prime[j] = 1;
        }
    }
}

void recur_check(vi& a, vi& valid, int i, int& status, ll& res, ll cnt){
    if (i >= n || not_prime[a[i]] || (a[i] > 1 && !not_prime[a[i]] && status >= 0)){
        //return if
        //reach the end
        //find non prime
        //found another prime
        
        //-1 because of the prime number, another -1 because of the current number that leads to return
        if (status != -1){

        	//First part
        	//(number of 1s after the prime number) * (number of 1s before the prime number)
            res += (((i-e) - (status))/e) * (ll)((cnt-2) - (((i-e) - (status))/e));

            //Second part
            res += cnt-2;
        }
        return;
    }

    if (!not_prime[a[i]] && a[i] != 1) status = i;

    recur_check(a, valid, i+e, status, res, cnt+1);
    
    //Assign the status
    valid[i] = status;
}

void solve(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> e;
        vi a(n);
        for(auto& i : a) cin >> i;

        //if valid, store the index of the prime number
        //else -1
        //-2 at the beginning
        vi valid(n);
        
        fill(all(valid), -2);
    
        ll res = 0;
        for(int i{}; i < n; i++){
            if (valid[i] == -1 || i <= valid[i]) continue;
            int status = -1;
            recur_check(a, valid, i, status, res, 1);
        }

        cout << res << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```