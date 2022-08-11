Took me a while to figure it out, I was initially going to simulate the process of finding rectangles, which is by removing the common minimum heights 1 by 1. But it turned out too slow, I have to switch to another method, and this method turned out working, but I had a hard time debugging it, since it's literally the first time I came out a solution with stack! And this is actually inspired by the problem I had months ago, which is to find the maximum area of rectangle in a histogram and by using stack.
<br>
```
Explanations

So our goal is to keep our stack as an increasing sequence, for example, if the height of the histogram goes like this

1 2 3 4 5

Our stack would became 1 2 3 4 5 as well, that means we need at least 5 rectangles to cover it, but if it's something below

1 2 3 4 5 3 4 5

We would need at least 8 , just by observing, we knew that, we need 5 for the first 5, and the another 3 for the rest.

At 5-th element

The stack would be 1 2 3 4 5 

Once it met a lower height, it will have to remove the top element on the stack until it's bigger than the top element, the current element is 3 (6-th element)


1 2 3 4 5 --> 1 2 3 4 --> 1 2 3 -- > 1 2
*Everytime we remove an element off the stack we need to keep tracks of how many times we did this, it's equivalent to the rectangle we need

3 is bigger than 2

So it's okay, we can push it onto the stack

1 2 3

4 and 5 (last 2 elements) would be pushed onto the stack with no troubles

So right now, at the end we have a stack of 1 2 3 4 5

We just have to pop each one of them, until the stack is empty, and each one we pop, we need to keep tracks of number of elements we popped, because that's the answer
```
Key takeaway from this problem:
- Always take care of the top element, do not access top() if the stack is empty, always do extra checking!


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
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a){
        int temp;
        cin >> temp >> i;
    }
        
    int count = 0;
    stack<int> s;
    for(int i{}; i < n; i++){
        if (s.empty()) {
            s.push(a[i]);
            continue;
        }
        if (a[i] > s.top()) s.push(a[i]);
        else{
            if (s.top() == a[i]) continue;
            while (!s.empty() && s.top() > a[i]){
                s.pop();
                count++;
            }
            if (s.empty()) s.push(a[i]);
            else if (s.top() != a[i]) s.push(a[i]);
        }
    }

    while(!s.empty()){
        s.pop();
        count++;
    }
    cout << count;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```
A much cleaner solution
```cpp
/*  The idea is that everytime the height increases we have to add a poster
 *  and whenever the height decreases, we add a poster iff there is no previous height of the same height or the height that equals me has another height that's lower than us in between us
 *  this is a common stack problem
 * */
#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

const int N = 5e5 + 2;

int n, d[N], res, h[N];
stack<int> s;

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", d + i, h + i);
        if (s.empty()) {
            res++;
            s.push(h[i]);
        } else {
            while (s.top() > h[i]) {
                s.pop();
                if (s.empty())
                    break;
            }
            if (s.empty()) {
                res++;
                s.push(h[i]);
            } else {
                if (s.top() == h[i])
                    continue;
                else {
                    res++;
                    s.push(h[i]);
                }
            }
        }
    }
    cout << res;
    return 0;
}
```