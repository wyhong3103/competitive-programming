This is kind of a DP problem, maybe? I solved this with a little luck LMAO, basically trial and error. So basically, this problem is about finding the minimum cost to conquer all the kingdoms. And with more information, you can look it up on the problem itself, here, i am just going to explain my solution.
```
So the idea is to construct prefix sum arrays(Idk if its considered as dp table or something), this problem is obviously a greedy problem, we need to select the best position we could be in

So first, we're going to construct an array of the cost of conquering, and also an array of the cost of switching capital

Example case

5 6 3
1 5 6 21 30

Kingdom    - 	1 	5 	6 	21 	30

			   3x1 3x4 3x1 15x3 9x3
Conquering -    3   12  3   45  27

Prefix sum -    3   15  18  63  90
of conquering

			   6x1 6x4 6x1 15x6 9x6
Capital    -    6   24  6   90  54   

Prefix sum -    6   30  36  126 180
of switching
capital

Prefix sum -    3   18  36  99  189  
of prefix sum
of conquering

Here I will explain why do we need this

Notice that the array of the cost of conquering takes the cost of every interval, and when we take its prefix sum, it became the cost we need to conquer that place if we weren't switching capitals and staying in 1 for the entire session

And the prefix sum of that, gives us the cost we need to conquer 0 to i-th place, why is that? Because with the cost to conquer every kingdom from 0, we can just simply add them up and we get the value to reach the place.

For the capital, it's the same as the prefix sum of conquering.

One key observation is that, it doesn't matter where do you choose to switch capital, for example

If we were to switch capital from 0 to 1 to 5

It cost 6 and 24, which is 30

But if we just switch to 0 to 5 instead,

We got the same amount of number which is 30

So that literally means that, it is always optimal to switch capital everytime, because the cost of switching from one to another always stays the same, it doesn't matter if you switch from one to another

So now, we just have to figure out when should we stop switching capital, because at one point, the cost will go higher, and unnecessary

Hmmm, so how do we know when to stop? Which is the optimal one? We cannot do binary search to search for it, because it's not a monotonic function, the graph will go like this if we switch to i-th capital, and conquer every other kingdom, for this example

___				  _____
   ____      _____
       ______

It's not a monotonic function.

And we literally test all the numbers, because we will get TLE, that's a N^2 operation.

That's when DP comes into play.

Notice that to find the cost to conquer every kingdom, while having capital at i-th kingdom

Is simply just 

(conquer[i] + capital[i]) + (prefix[n-1] - prefix[i]) - ((n - (i+1)) * prefix[i])
//All the -1 and +1 is because of the index in loop

(conquer[i] + capital[i]) - Cost we need to reach i-th kingdom and conquer it

(Prefix[n-1] - prefix[i]) - Because we already considered the cost we need to reach i-th kingdom, we can simply get rid of the amount to reach there in the prefix sum,

And with the rest of the prefix sum, we can simply deduct by (n - (i+1)) * prefix[i]

n - (i+1) is the number of kingdoms left

Why * prefix[i] ? Because notice that the prefix sum is the cost from 0 to i-th kingdom, while we're paying a 100%, but now we at i-th kingdom, we have to deduct every cost by i-th prefix sum, because the prefix sum, has included the cost of 0 to i-th kingdom, why can we do that? Because we've already done settling the cost we need to reach i-th kingdom and switch to it as a capital, by using conquer[i] + capital[i]
```
Below is the implementation

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
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;

        vector<ll> conquer(n);
        vector<ll> capital(n);
        vector<ll> prefix(n);
        vector<ll> arr(n);
        for(int i{}; i < n; i++) {
            cin >> arr[i];
            if (i == 0){
                capital[i] = arr[i] * a;
                conquer[i] = arr[i] * b;
                prefix[i] = conquer[i];
            }else{
                capital[i] = ((arr[i] - arr[i-1]) * a) + capital[i-1];
                conquer[i] = ((arr[i] - arr[i-1]) * b) + conquer[i-1];
                prefix[i] = conquer[i] + prefix[i-1];
            }
        }

        ll mn = prefix[n-1];
        for(int i{}; i < n; i++){ 
            mn = min(mn, (conquer[i] + capital[i]) + (prefix[n-1] - prefix[i]) - ((n-(i+1)) * conquer[i]));
        }

        cout << mn << '\n';
    }
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```