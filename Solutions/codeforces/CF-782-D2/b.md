This problem is much more challenging, it's really about the observations. Here below, I'll explain my approach(much more complicated and redundant, could've simplified it a lot further).
```
So basically, we know that everytime, you do the operation(select 1 bit , and flip every other bits), if you do it twice, every other bit other than the bit you're holding, is going to be the same. 

-------------------------------------------------------------------

So, with this idea, we could further extend it,

Since our goal is to make the lexicographically largest bit, so we will always prioritize the 1 at the left most

Say we got

100100

and k = 2

I know that if I start by selecting the left most 1, all my bits is going to be flipped, but the second time I did it with another bit the 1 will definitely got flip, or I do it again on the same bit, but there are no reasons of doing this, because you're basically getting back what you started with

So the idea is that, if k is even, we can start by looking for the first 0, select the 0 as a target, and we can ignore every 1 before the 0, because k is even, as long as we didn't perform an operation on the 1s before the 0, it will stays 1

So with this observation, we can ignore the 1s before it, and just focus on the 0

0 will eventually turn to 1, how?

Say we got

0010

First, we select 0 as the bit and flip others

*0*101

Now, k became odd, we select the first 1 we find after the 0, and flip it

1*1*10

And done, we got ourself a new 1 at left most, and every other 0s before the 1

By now we will have an even number of operations, we can ignore every other 1, and look for the next 0, which is the last bit, notice that, we cannot do anything to the last bit, if you try to do it on 0, you won't get anything out of it

So that's the final answer, all we had to do with the rest of the k's is just to add all of it to the last bit


So right now, with all these little experiments, we can say that,

When k is an even number, we look for the first 0, and perform the operation, 0 will turns to 1

When k is an odd number, we look for the first 1, and perform the operation, 0 will turns to 1, because if we look flip the 1s ,0 will turn to 1s

If the 0 is on the last bit, we cannot perform anything,

Another special case is that, we have 

000

And k = 2, by right we will look for the first 0, which is the first bit, and k will become 1, so now we have to look for a 1, but notice that there isn't any

So the idea is to select the last bit, and flip every other bits, which means stop everytime we reach the last bit

-------------------------------------------------------------------

Now the implementation, we basically couldn't flip the entire bit string everytime, since n <= 200000, we cannot afford the operations, so the idea is that we iterate from the first bit to the last bit, and flip when we have to, we can basically use a counter, to count the times we have performed the operation before i-th bit, and if the counter is even number while we're on i-th bit, we dont do nothing, if its odd we flip it, and if k is even , we look for 0 and flip it to 1, and add it to the operation counter, k is odd, we look for 1, and add 1 on the operation counter, and turn 0 to 1s

Stop when we meet last bit, add number of operations remaining to the last bit
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
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
    
        string s;
        cin >> s;
 
        vi a(n);
 
        int count = 0;
        for(int i{}; i < n; i++){
            if (count % 2 != 0){
                s[i] += (s[i] == '0' ? 1 : -1);
            }
            if (i == n-1){
                break;
            }
            if (k > 0){
                if (k % 2 == 0){
                    if (s[i] == '0'){
                        s[i]++;
                        a[i]++;
                        count++;
                        k--;
                    }
                }else{
                    if (s[i] == '1'){
                        a[i]++;
                        count++;
                        k--;
                    }else{
                        s[i]++;
                    }
                }
            }
        }
        if (k) a[n-1] += k;
        cout << s << '\n';
        for(auto& i : a) cout << i << ' ';
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
A much simplified way of doing it (Not from me , so it might not be so intuitive, because Idk how the author came up with this neither)
```
Instead of thinking which bit should we pick, we should think of the case where if we dont pick any and flip

Even number of operations - nothing change
Odd number of operations - everything flip

It doesn't matter how many the number of operations is, for example, if its 9, it's just equivalent to having 1 number of operations, why? when you've done 8, you're back to doing nothing, so at 9, it's equivalent to having 1 operation

And the idea is that, everytime we do an operations, a bit doesn't change

And everytime we do that, the bit, is one less operation than others, that means, if k is even number, every bit stays the same at the end, but because we hold the bit once, so at the end it will be flipped

So the idea is that, we could literally change k number of 0s to 1, it is always possible to do that. But before that, we have to flip all the bits if k is odd.

And at the end (after we got all the 0s to 1s), if we still have remaining number of operations, if it's odd that means we need to turn the last bit into 1, if its odd, we have to change it back to 0
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
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
    
        string s;
        cin >> s;
 
        vi a(n);
    
        if (k % 2 != 0){
            for(int i{}; i < n; i++){
                s[i] += (s[i] == '0' ? 1 : -1);
            }
        }

        for(int i{}; i < n; i++){
            if (s[i] == '0' && k > 0){
                s[i]++;
                a[i]++;
                k--;
            }
        }
        if (k % 2 != 0) s[n-1] = '0';
        a[n-1] += k;
        cout << s << '\n';
        for(auto& i : a) cout << i << ' ';
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