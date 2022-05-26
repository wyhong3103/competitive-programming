An interesting problem lol, I never thought that I would be able to solve it. Anyways the idea is to find the product of the pair of number that is x^k.
```
Main observation

In order for a pair of number to product x^k, they have to be x*x*x... k times. 

x*x*x could be a non prime number which would be much difficult to recognise. 

For example, 

a and b, they could be x*x*x*x in disguise, what does that supposed to mean?

Say a = 9, b = 24, and k = 3

They're actually a pair that could produce x^k, 9 * 24 = 216 = 6 ^ 3

Well this might not be obvious at first, but once you prime factorize them

a = 3^2 , b = 2^3 * 3^1

You will realize that in order to produce x^k, the power of both numbers adds up should be divisible by k

a * b = 2^3 * 3^3

And this is actually 6 ^ 3

And that's the idea, we're going to look for numbers that could paired up like this

And surprisingly, we could use a vector of pairs of {prime : how much power we need in order to be divisible by k} as a key of a hash map.

Why prime factorization works?
Prime factorization always produce the simplest form of factors, and also the longest. Which is exactly what we need, with primes, it's easier to find it's pair. If we're using non prime number , it would be a pain in the ass, first we have to worry about what number we need to store, and so much unnecessary confusion. Prime number in this problem acts exactly like a base unit that we need to form the numbers.

Another tricky part of this problem is that, we're not just looking for number that paired up as k exactly, but divisible by k, because imagine k = 2, and we have 2^4, 2^4 is actually equal to 4^2, so it's quite the same thing
-----------------------------------------------------

So the idea is to iterate through every number, and hash what the number is lacking. For example, a = 24, k = 3, a = 2^3 * 3^1, we need a 3^2 to make up our desired pair, so we will store it as {3 : 2} in the hash map, but to look up for our desired pair, we're going to have another vector of pairs which store what we have, in our example, a = 2^3 * 3^1, we're going to store it as {3 : 1}, we can ignore 2^3, because it has already been fulfilled.

So while we're dealing with a = 24, b = 9

Now let's demonstrate how it works
First let's iterate to 24, we're just starting so there is nothing in the hash map, so we're going to store what are we lacking, {3 : 2}

Now to b = 9, we're lacking {3 : 1}, but we have {3 : 2}, so we're going to look up for the number of element that is {3 : 2}, and we found 1, which is the previous number ,24

And now we're going to store it as {3 : 1}, if it already exist, we just add the frequency by 1

And another thing we need to take care of is, 1 and number that has already fulfilled the condition, for example, if k = 3, and a = 8 = 2^3, for all these numbers, we're going to see it as 1. And for every number like this, they could pair up with each other, 

For example,
n = 3, k = 3

1 8 1

You could see them as 1 1 1
Since both 1 can pair up with 8, 1 can pair up with 1 etc etc
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

void primefactor(int n, vector<pi>& need, vector<pi>& have, int k){
    for(int i{2}; i * i <= n; i++){
        pi cur{i , 0};
        while (n % i == 0){
            cur.sec++;
            n /= i;
        }
        if (cur.sec % k != 0){
        	//k - (cur.sec % k) = number we're lacking
            need.pb({cur.fir, k - (cur.sec % k)});
            //cur.sec % k = number we have
            have.pb({cur.fir, cur.sec % k});
        }
    } 
    if (n > 1){
        need.pb({n,k-1});
        have.pb({n, 1});
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto& i : a) cin >> i;


    ll res = 0;
	//{number we're lacking : frequency}
    map<vector<pi>, int> mp;
    int cntone = 0;
    for(auto& i : a){
        if (i == 1){
            res += cntone;
            cntone++;
        }
        else{
            vector<pi> need;
            vector<pi> have;
            primefactor(i, need, have, k);
            if (sz(need)){
                res += mp[have];
                if (!mp.count(need)) mp[need] = 0;
                mp[need]++;
            }else{
                res += cntone;
                cntone++;
            }
        }
    }
    cout << res;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```