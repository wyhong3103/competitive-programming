This problem is literally about finding the longest substring, which has the interval of m. My approach is below
```
So basically, first we can construct a map of characters as key and it's relevant indinces in the string ,as the value, and it's an array

So, the idea is to find the best substring, which consist of c and has the interval of m

Say we got 

azaaaaaaa

If m = 3, and c = a

The best substring is the entire string, and the interval is 1, so it's valid

The interval we're referring to is the margin between c and c,

If we have 

azzazaaaaa

The best substring which is valid, is still the entire string, because the interval is 3

So this is the idea,

-------------------------------------
But how do we find it??

Remember we got that array of indices, what we can do is

Say we have an array of 

azazzza

1 3 7

for the character a

The idea is to use two pointers and find a subarray which has the interval within m, (sliding window****)

Say m = 1

L = 0			R = 1
(left pointer)	(right pointer)

So the first interval we have is the value the right pointer is pointing to and the value that is before the right pointer, it doesn't necessary have to be the left pointer, it's just a coincidence in this situation, so it's , (3-1)-1, we have to do another -1, this is because interval is the length between the number and another number, which exclude 3

And now we'll try to move the right pointer 

Current interval = 1

Now, since we moved the right pointer, we have to increase the interval, so ,

interval = interval + (7-3)-1 = 4

Which is larger than m, so in this case, we will try to move the left pointer foward, until the interval <= m,

We do that by simply deducting the interval by value after left pointer is pointing to 	- value the left pointer is pointing to

The idea is basically sliding window!

x x x x-x-x x
(x-x-x is our window)

Move the left pointer

x x x x x-x

Notice that one of the - got removed, and that's exactly the value we're deducting.

With this idea , we can find the best substring with length m, in O(N), N = lenght of the indices
```
```cpp
#include <bits/stdc++.h>
#include <limits>
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
    string s;
    cin >> s;

    map<char, vi> ma;
    for(int i{}; i < n; i++){
        ma[s[i]].pb(i);
    }

    int q;
    cin >> q;
    while(q--){
        int m;
        char c;
        cin >> m >> c;
        
        if (!ma.count(c)){
        	//If the character doesn't exist, we print m
            cout << m;
        }else{
            int l = 0, r = 1;
            int interval = 0;
            int count = 0;
            int mx = 0;
            while(r < sz(ma[c])){
                if (interval <= m){
                    count++;
                    interval += (ma[c][r] - ma[c][r-1])-1;
                    r++;
                }else{
                    interval -= (ma[c][l+1] - ma[c][l])-1;
                    l++;
                    count--;
                }
                mx = max(mx, count);
            }
            if (interval <= m) {
                count++;
                mx = max(mx, count);
            }
            cout << min(n, mx+m);
        }
        cout << '\n';
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```