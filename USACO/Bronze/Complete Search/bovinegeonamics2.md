I haven't solve this problem, but I will one day. 
<br>
Key takeaway from the editorial:
- We need a O(m^3 . n) solution, my original solution take O(m^3 . n^2)
- Here's a brief explantion on how the base 4 thingy on the editorial (on USACO) works
- Normally, when we got i,j,k ,we iterate through every genome in that 3 locations with the one in plain, it will essentially be n^2
- But a brilliant way of testing / comparing this is , store the 'ATGC' as a number, 'A' - 0, 'T' - 1, 'G' - 2, 'C' - 3, stores this number in a multidimensional array \[n\]\[m\], and whenever we're ready for the iteration for the 3 number distinct locations (i,j,k), we can use a function, that :
	- So we have 3 numbers for the locations, which is i,j,k, and we can retrieve it's value, using the multidimensional array we initialized previously. And get its sum of weight (see it as a base 4 number), 16 * \[i\](refer to its value, whether its 3 , 2 1 or 0) + 4 * \[j\] + k, this would result in a different sum with different permutations of the letters.
	- With the sum of weight of it, we can use another array (which can at least contain the highest number of the sum of weight, case of 16 * 3 + 4 * 3 + 3), with the sum of weight as the index, we initialize it to 1, (each row of spotted cow's genome)
	- Then we do the same thing, but this time with plain cow's genome and instead of assigning 1 to it, we compare it, if the value we're pointing to (with the plain cow's genome value) is 1 , that means the following locations cannot be use, because it has the same value as the spotted cow
	- This would only take n time to test! basically, we set the distinct value location as 1, compare it, if we got 1, that means its not usable 