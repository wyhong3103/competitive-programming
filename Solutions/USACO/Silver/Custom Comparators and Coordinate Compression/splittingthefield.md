I failed at my first attempt, because of integer overflow. Alright, this seemingly very long solution, is not that complicated (although it's still complicated). Anyways, it worked for the big cases, I believe the time complexity is O(N log N). Here below I am going to explain everything. 
```
Problem:
So this problem is basically asking for the smallest 2 rectangles we can form, that will enclose every cow within it. And we need to get the absolute difference between the area of these 2 rectangles and the area of the original rectangle(which is the 1 rectangle that enclose every cow).


Approach:

One key observation about having 2 rectangles that doesn't intersect each other is , there will always be a border between them, it's either vertically or horizontally.

For example

..............
.xxxx.........
.xxxx.........
.xxxx.........
........xxxx..
........xxxx..
........xxxx..
........xxxx..
..............
..............

Notice that between these 2 rectangles

......|.......
.xxxx.|.......
.xxxx.|.......
.xxxx.|.......
......|.xxxx..
......|.xxxx..
......|.xxxx..
......|.xxxx..
......|.......
......|.......

There is ths big divider, same goes to horizontal cases.

With this observation, the solution then comes up to my mind, which is to form the rectangle from the left most coordinate, to the right most coordinate.

Something like this

oxxxxxxx

oooxxxxx

ooooxxxx

oooooooo

O is the first triangle , X is the second triangle

At first I was thinking of doing it parallel, which means, getting the area of 2 at once, but then I found out that it's impossible, because doing this, you will be getting the left most coordinate and the right most coordinate, but you don't have the height between them, you might be able to get the max and min from the coordinates you have iterated, but for the other side of the rectangle, you don't have the heights. If you were to look for the max and min in every iteration for both rectangle, it will definitely take N^2. So I knew we can't do that.

So my approach is, we first compute the area of the first rectangle, and put the area into an array accordingly.

We can simply keep track of the min and max y coordinates, and get the height, and multiply by the i-th x coordinate - 0-th x coordinate. 

Then we travel the array reversely, compute the rectangle and add it into it's corresponding area.

One key point while during the iteration is that, we only compute the area, when we've captured all the same x-coordaintes , waht does it mean?

Say we got 

(1,1,1,1,2,2,2)

As all the x-coordinates

We will only compute the area when we captured all the 1, then the next time we compute is when we're done with 2.

Notice that we only compute the area, when we know we done capturing the new coordinates, and we know that by bumping into one new different coordinate, so that also implies that for the last x-coordiante, will never be computed, that's right, and we dont need to, because that belongs to the other triangle.

How do we know if we have done capturing the numbers? We will have a boolean variable to keep track of it, and a variable to keep track of the x-coordinate of the previous x-coordiante. You can see the implmenetation below.

The reason we're doing this is because, the rectangle doesn't intersect! That means they cannot share a coordiante on the same line.

Same goes to vertically, after getting all the areas, we simply need to get the max absolute difference.

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
    
    pi hi = {numeric_limits<int>::max(), 0};
    pi wi = {numeric_limits<int>::max(), 0};

    vector<pi> coords(n);
    for(auto& i : coords){
        cin >> i.fir >> i.sec;
        hi.fir = min(hi.fir, i.sec);
        hi.sec = max(hi.sec, i.sec);
        wi.fir = min(wi.fir, i.fir);
        wi.sec = max(wi.sec, i.fir);
    }


    //Area of the original rectangle, that one big rectangle
    ll onearea = abs(hi.fir - hi.sec) * (ll)abs(wi.fir - wi.sec);



    //Compute horizontally

    sort(all(coords), [](pi a, pi b){
        if (a.fir == b.fir){
            return a.sec < b.sec;
        }
        return a.fir < b.fir; 
    });

    vector<ll> horizontal;
    
    int prev = -1;
    bool found = false;
    pi height = {numeric_limits<int>::max(), 0};
    for(int i{}; i < n; i++){
        if (coords[i].fir != prev && !found){
            prev = coords[i].fir; 
            found = true;
        }else if (coords[i].fir != prev && found){
            found = false;
            ll area = abs(coords[0].fir - coords[i-1].fir) * (ll)abs(height.fir - height.sec);
            horizontal.pb(area);
            i--;
            //i-- is a workaround, if we don't do i--, the next new coordiante will be ignored
        }
        height.fir = min(coords[i].sec , height.fir);
        height.sec= max(coords[i].sec , height.sec);
    }

    prev = -1;
    found = false;
    height = {numeric_limits<int>::max(), 0};
    
    //Pointer to keep tracks on which i-th area to add 
    int p = sz(horizontal)-1;
    for(int i{n-1}; i >= 0; i--){
        if (coords[i].fir != prev && !found){
        	//Found new coordiantes, start capturing
            prev = coords[i].fir; 
            found = true;
        }else if (coords[i].fir != prev && found){
        	//When we're done capturing the new coordaintes
            found = false;
            ll area = abs(coords[n-1].fir - coords[i+1].fir) * (ll)abs(height.fir - height.sec);
            horizontal[p] += area;
            p--;
            i++;
        }
        height.fir = min(coords[i].sec , height.fir);
        height.sec= max(coords[i].sec , height.sec);
    }


    //Compute vertically

    sort(all(coords), [](pi a, pi b){
        if (a.sec == b.sec){
            return a.sec < b.sec;
        }
        return a.sec < b.sec; 
    });

    vector<ll> vertical;
    
    prev = -1;
    found = false;
    pi width = {numeric_limits<int>::max(), 0};
    for(int i{}; i < n; i++){
        if (coords[i].sec != prev && !found){
            prev = coords[i].sec; 
            found = true;
        }else if (coords[i].sec != prev && found){
            found = false;
            ll area = abs(coords[0].sec - coords[i-1].sec) * (ll)abs(width.fir - width.sec);
            vertical.pb(area);
            i--;
        }
        width.fir = min(coords[i].fir , width.fir);
        width.sec= max(coords[i].fir , width.sec);
    }


    prev = -1;
    found = false;
    width = {numeric_limits<int>::max(), 0};
    p = sz(vertical)-1;
    for(int i{n-1}; i >= 0; i--){
        if (coords[i].sec != prev && !found){
            prev = coords[i].sec; 
            found = true;
        }else if (coords[i].sec != prev && found){
            found = false;
            ll area = abs(coords[n-1].sec - coords[i+1].sec) * (ll)abs(width.fir - width.sec);
            vertical[p] += area;
            p--;
            i++;
        }
        width.fir = min(coords[i].fir , width.fir);
        width.sec= max(coords[i].fir , width.sec);
    }

    
    ll mx = 0;
    for(auto& i : horizontal){
        mx = max(mx, onearea - i);
    }
    for(auto& i : vertical){
        mx = max(mx, onearea - i);
    }

    cout << mx;
}
 
int main(){
    setio("split");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```