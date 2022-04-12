Didn't implement the solution yet, but have the solution in mind.
```
So basically, we're given NxN grids

Say N = 10, K = 4

X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X
X X X X X X X X X X

So this is what its look like in the middle

X X X X X O X X X X X
X X X X O O O X X X X
X X X O O O O O X X X
X X O O O O O O O X X
X O O O O O O O O O X
O O O O O B O O O O O
X O O O O O O O O O X
X X O O O O O O O X X
X X X O O O O O X X X
X X X X O O O X X X X
X X X X X O X X X X X

Almost every time, it will forms this diamond shape, according to your K, so the idea is to travel through each and every cell, and get the maximum sum of the grass on O, you might be tempted to think that it's always optimum to travel from K <= i <= N-K , K <= j <= N-K, but it's actually not, imagine a case where, you have a 1000 in the corner, but the rest is 1, your code is going to fail.

And instead of calculating the sum of each and every cell every time, we could do prefix sum on every row(1D array), so getting the sum of a row is simply prefix[N]-prefix[the right most O]-prefix[the left most O - 1]
```