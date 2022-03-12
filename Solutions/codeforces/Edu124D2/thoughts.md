I could've done better in A and B, well I didn't feel disappointed neither, A and B is the goal for now. <br>
A:
<br>
I've messed up the implementation, I've figured it out much earlier that the answer is 2^n - 1, but instead of using a ll to store the answer , I've used cout << pow(2,n)-1; which return a value with scientific notation, that's what got me failed in the first place, after minutes of debugging i've finally got it work!
<br><br>
B:
<br><br>
I figured out it much earlier as well, but I've messed up the math a little, my main confusion was how does 512 failed? After minutes of thinking, I've figured out that the optimal difference between 2 number , ai, and aj, is min(ai,aj)\*3,  regardless of the number, when you do | ai - aj | , and \* 2, you always get the same sum between them. But how does 512 failed? first i've thought of integer overflow, but instead of trying 3^512, i did 512^3, which dind't make sense because it's still in the boundary. after minutes and minutes of struggling, i've decided to print out my array, and it turned out it realy is integer overflow, i've to manually count for it, and eventually figured out that it is actually 3 ^ 512, and found out that 3 ^ 18 is the last number we can do , other return "NO".
