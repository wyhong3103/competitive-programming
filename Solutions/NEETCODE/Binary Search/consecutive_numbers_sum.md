The idea is pretty simple.
```
First to determine the max container size, it's < 1e5, because if we use summation formula to find out the sum of first 1e5 numbers, it's going to be ~5e9

So it's rather unnecessary, it can be much lower than this.

The next thing we can do is to iterate from 1 to 1e5, then binary serach the sum of number i to i+container size, see if there is any that's equal to n.
```
```cpp
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int MX = 1e5;
        int cnt = 0;
        for(int i{1}; i <= min(n,MX); i++){
            long long lo = 1, hi = 1e9-(i-1);
            while (hi > lo){
                long long mid = lo + (hi-lo)/2;
                long long sm = (((mid+(i-1))*(mid+i))/2) - ((mid-1)*(mid)/2);
                if (sm >= n){
                    hi = mid;
                }else lo = mid+1;
            }
            if ((((lo+(i-1))*(lo+i))/2) - ((lo-1)*(lo)/2) == n) cnt++;
        }
        return cnt;
    }
}
```