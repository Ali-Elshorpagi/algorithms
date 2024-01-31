

### **Definitions :**


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


### **Algorithms :**

|ID| Algorithm Name   |  Time           | Space           | Note          | 
|---|--------------- | --------------- | --------------- | ------------- |
|00|[Bubble Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/bubble_sort.cpp)| `O(N^2)` |`O(1)` ||
|01|[Selection Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/selection_sort.cpp)| `O(N^2)` |`O(1)` ||
|02|[Insertion Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/insertion_sort.cpp)| `O(N^2)` |`O(1)` ||
|03|[Quick Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/quick_sort.cpp)| `O(N^2)` |`O(N)` ||
|04|[Merge Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/merge_sort.cpp)| `O(N * log(N))` |`O(N)` ||
|05|[Count Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/count_sort.cpp)| `O(N + K)` |`O(K)` ||
|06|[Heap Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/heap_sort.cpp)| `O(N * log(N))` |`O(1)` ||
|07|[Bucket Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/bucket_sort.cpp)| `O(N^2)` |`O(N + K)` ||
|08|[Radix Sort](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/radix_sort.cpp)| `O(D * (N + K))` |`O(N + K)` ||

<br><br>

### **Problems :**

|ID|  Code  | Problem Name    |  Solution       |  Time           | Space           | Note          | 
|---|----|---------------- | --------------- | --------------- | --------------- | ------------- |
|00|1200|[Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_1200.cpp)|`O(N * log(N))`|`O(1)`||
|01|976|[Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_976.cpp)|`O(N * log(N))`|`O(1)`||
|02|561|[Array Partition](https://leetcode.com/problems/array-partition/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_561.cpp)|`O(N * log(N))`|`O(1)`||
|03|1921|[Eliminate Maximum Number of Monsters](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_1921.cpp)|`O(N * log(N))`|`O(N)`||
|04|1005|[Maximize Sum Of Array After K Negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_1005.cpp)|`O(N * log(N))`|`O(1)`||
|05|581|[Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_581.cpp)|`O(N)`|`O(1)`||
|06|1887|[Reduction Operations to Make the Array Elements Equal](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_1887.cpp)|`O(N * log(N))`|`O(1)`||
|07|280|[Wiggle Sort](https://leetcode.com/problems/wiggle-sort/)|[C++](https://github.com/Ali-Elshorpagi/algorithms/blob/main/sorting_algorithms/problem_solving/LeetCode_280.cpp)|`O(N)`|`O(1)`||