

# Definitions :


> Stable Algorithm :
  - an algorithm that preserves the relative order of elements with equal keys. This means that if two elements have the same key, their relative order in the sorted array will be the same as their relative order in the unsorted array.
  - Assume input [1, 2, 5A, 5B, 3, 5C]. [A,B,C just tags]
  - When we sort it: [1, 2, 3, 5A, 5B, 5C]. Equal keys have the SAME old order

> In-Place Algorithm :
  - an algorithm is a type of sorting algorithm that rearranges the elements of the input sequence directly within the same memory space without requiring additional memory proportional to the input size.
  - only requires a constant amount O(1) of additional memory space.

> Adaptive Algorithm :
  - an algorithm that works efficiently for data sets that are already substantially sorted.
  - The time complexity is O(kn) when each element in the input is no more than k places away from its sorted position. If the whole list is already sorted, then k = 1


> Online Algorithm :
  - can sort a list as it receives it
  - Imagine an online **service** that keeps receiving numbers and sort all what we have so far

> Comparison Based Algorithm:
  - a type of algorithms that only relies on comparisons to order the elements of an array. This type cannot use any other information about the elements, such as their values or their relative positions.
  - any comparison-based sorting algorithm must make at least (N * log2(N)) comparisons on average to sort the input array


### Problems

  |ID|  Code  | Problem Name    |  Solution       |  Time           | Space           | Note          | 
|---|----|---------------- | --------------- | --------------- | --------------- | ------------- |
|000|1200|[Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/SPOJ_Knapsack.cpp)|`O(N * log(N))`|`O(1)`||
|001|976|[Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/LeetCode_300.cpp)|`O(N * log(N))`|`O(1)`||
|002|561|[Array Partition](https://leetcode.com/problems/array-partition/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/LeetCode_1143.cpp)|`O(N * log(N))`|`O(1)`||
|003|1921|[Eliminate Maximum Number of Monsters](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/LeetCode_416.cpp)|`O(N * log(N))`|`O(N)`||
|004|1005|[Maximize Sum Of Array After K Negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/LeetCode_1691.cpp)|`O(N * log(N))`|`O(1)`||
|005|581|[Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/LeetCode_198.cpp)|`O(N)`|`O(1)`||
|006|1887|[Reduction Operations to Make the Array Elements Equal](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/DP/pick_or_leave_pattern/LeetCode_309.cpp)|`O(N * log(N))`|`O(1)`||