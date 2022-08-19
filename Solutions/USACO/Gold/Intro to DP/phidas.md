Luck.
```

I somehow got very lucky (with no proof) and passed this problem with AC.

Anyways, I would list my assumption below.

dp state = [i height, j width]
dp value = maximum area we could obtain with i height and j weight

dp transition =

It's either we place a block or we don't

If we do not place a block, the transition would simply be max(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])

Now here comes the tricky part where I have no proof that it actually works.

#########
#####XXXX
#####XXXX


Say X is the place you want to place a block, to know the maximum area you could place a block, you simply need 

AAAAA     	     XXXX
AAAAA  +  BBBB + XXXX
AAAAA
AAAAA

Building blocks of the above sizes.

OR


AAAAAAAAA + BBBBB  + XXXX
			BBBBB    XXXX


Now we could obtain the maximum area of the aboves sizes with dp[a height][a width]+ dp[b height][b width]

So the dp transition is 

max(dp[i][j - x width] + dp[i - x height][x width] + (x area), dp[i - x height][j] + dp[x height][j - x width] + (x area))

I have thought of a few cases where my code would fail, for example, what if there is a block between A and B. But I decided to test my other assumption, what if it's just the matter of block placement, which means the case where block could stand between A and B could actually be placed in another order which would not disrupt the transition. And it just went AC after that.

(My initial idea was sort of like 2D prefix sum, but that's kind of dumb, as all dp states are independent, they're not the same rectangle, but they are the optimal rectangle of their size)
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

const int MXN = 601;
int dp[MXN][MXN];

void solve(){
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<pi> a(n);
    for(auto& i : a) cin >> i.sec >> i.fir;


    for(int i{1}; i <= h; i++){
        for(int j{1}; j <= w; j++){
            for(int k{}; k < n; k++){
                if (i-a[k].fir >= 0 && j-a[k].sec >= 0) {
                    dp[i][j] = max({dp[i][j],dp[i][j-1], dp[i-1][j], dp[i-1][j-1], dp[i-a[k].fir][j]+dp[a[k].fir][j-a[k].sec] + (a[k].fir*a[k].sec), dp[i][j-a[k].sec]+dp[i-a[k].fir][a[k].sec] + (a[k].fir*a[k].sec)});
                }
            }
        }
    }

    cout << (w*h)-dp[h][w];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```
My solution is very flawed. [Editorial](https://usaco.guide/problems/dmoj-phidias/solution) from USACO Guide provides a much clearer and intuitive solution. (We had a similar idea)
```
Let 
dp[i][j] be the minimum total wasted area with a rectangular slab size of i*j. Initialize dp[i][j]
as i*j and set dp[xi][yi] as 0, where xi, yi are the width and heights of the desired plate sizes,
respectively. Check every sub-rectangle with either fixed i or j(but not both) and store the 
minimum total area must be wasted for the optimal sub rectangle.
```
```cpp
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
 
#define f first
#define s second

const int MAXN = 600;
	
/*
 * Let dp[i][j] be the minimum residual area with a 
 * rectangular slab size of i x j
 */
int dp[MAXN + 1][MAXN + 1];

int main(){
	// The width and height of the original slab.
	int w, h; 
	cin >> w >> h;
	int n; 
	cin >> n; 
	vector<pi> plates(n);
	for (int i = 0; i < n; i++) {
		// The width and height of the desired plates
		cin >> plates[i].f >> plates[i].s;
	}
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			dp[i][j] = i * j; // Initialize dp[i][j] as i * j
		}
	}
	for (int i = 0; i < n; i++) {
		/* 
		 * Set dp[x_i][y_i] as 0, where x_i and y_i are the width 
		 * and heights of the desired plate sizes, respectively.
		 */
		dp[plates[i].f][plates[i].s] = 0;
	}
	/* 
	 * Visit all the possible rectangles from with a width of 
	 * i = 1...w and a height of j = 1...h
	 */
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			for (int x = 1; x <= i; x++) {
				/* 
				 * Fix the height of the rectangle and find the 
				 * optimal subrectangle with height j
				 */
				dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j]);
			}
			for (int y = 1; y <= j; y++) {
				/*
				 * Fix the width of the rectangle and find the 
				 * optimal subrectangle with width of i
				 */
				dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y]);
			}
		}
	}
	cout << dp[w][h] << endl;
}
```

But it still left me with a doubt, why couldn't it be i and j at the same time (block placed between a and b).