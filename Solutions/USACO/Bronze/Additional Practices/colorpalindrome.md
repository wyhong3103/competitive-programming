Didn't manage to solve this, but I do want to leave some notes here, so that next time when I revisit this problem, I already got a good grasp on what it is.
<br>
Problem Explanation:
- We have to form k strings using the string given, order doesn't matter, because we're allowed to swap it freely.
- We have to form the longest palindrome we could, and making sure all the characters are evenly distributed.

<br>

My first approach:
- In order to form a palindrome, we can either have even odd even, or even even even....
- eg: aaaaxaaaa, aaaayyyyaaaa, aaaayyyaaaa, xybbyx, xyzyx == xxyyz (even even odd)
- My appracoh was to create a frequency table with hash map, and try to construct the each of the palindrome, (1 to k), at the same time, to make sure its evenly distributed, but it failed.