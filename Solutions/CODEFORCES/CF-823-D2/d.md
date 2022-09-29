In hindsight, this problem seems easier than it look, I've thought of relevant ideas to the solution during the contest, but didn't really come up with anything at the end, I really wasn't focused in solving this problem after all, first I got good rank at that time, and the number of solve of this problem is way lesser than you think. So, I've basically given up subconsciously, which is a really bad thing to have.
```

It might be a little hard to get the observation by naively swapping the prefixes and suffixes.

Let's try to reverse the second string. And with this, we could swap the same index, but the thing is, everytime we do an operation, we need to reverse the first substring and then put it to second string, we need to reverse the second substring and then put it to the first string, and eventually we will need to form a palindrome (concatenation of s1+s2) in order to solve this problem.


First observation, notice that the relative order of two character doesn't change at all, no matter how you swap them.

bxxxx
axxxx

xxxxa
xxxxb

{a,b} still connected after all

Second observation, we can basically get any pair of character to anywhere we want.


cxxxa
dxxxb

xxdxa
xxcxb

You might be tempted to think that dc is different from cd, but one thing you can do is to put them to the first index and then swap them again

cxxxa
dxxxb Swapping back to first pair

dxxxa
cxxxb Swapping first pair

xxcxa
xxdxb Swapping back to 3rd position, and reversed it

So basically, we can construct this palindrome from back to end, we just need to know whether the pair of letter we need exist (fulfill the criteria).

Third observation, how a palindrome is being mirrored between the strings.

acb
bca

Notice the above is a palindrome (second string reversed, we can reverse it back to original order to make them equivalent).

{a,b} pairs up with another {a,b}. And {c,c} pair up with itself because it is the center pair.

So basically, if n is odd, we need a center pair.

And then, for both even & odd case, we need even pairs (one need to connect with the other).

so basically across all pairs of characters, frequency of all pairs has got to be even, and if n is odd, there has to exist another pair of same character that  has an odd frequency.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;


    reverse(all(b));

    map<pair<char,char>, int> freq;

    for(int i{}; i < n; i++){
        pair<char,char> temp;
        temp.fir = min(a[i], b[i]);
        temp.sec = max(a[i], b[i]);
        freq[temp]++;
    }

    bool ok = 1;
    if (n % 2){
        bool found = 0;
        for(auto& i : freq){
            if (i.sec % 2 && i.fir.fir == i.fir.sec){
                found = 1;
                i.sec--;
                if (i.sec == 0){
                    freq.erase(i.fir);
                }
                break;
            }
        }
        if (!found) ok = 0;
    }

    for(auto& i : freq){
        ok &= (i.sec % 2 == 0);
    }

    cout << (ok ? "YES" : "NO") << '\n';
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