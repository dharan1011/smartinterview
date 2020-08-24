# Binary Search
Binary Search is a search algorithm. Most of us are thrgouht in colleges/schools that it can be used to search a sorted array in O(logn) which is better Linear Searches (n). **Is that it ???**

But what does a binary search algorithm work. And why only on sorted data.
If you observe non-decreasing array a[i] <= a[i+1] is always true that because sorted array is monotonic increasing wrt value of i i.e f(n+1) >= f(n) where f can any heuristic function.
Now the value of i must belongs to some range say [lo, hi]. Then lo and hi defines the inclusive boundries of our search space.

Now if we have to find a value x in our array, instread of traversing we make few guesses in our search space to check for value of x. So how do we guess, we compute the median of our search space, check weather f(mid) == x, if yes can stop. Else if f(mid) < x then all the values i from [lo, mid] will be less than x, so we adjust our search space s.t lo = mid + 1. Similary if f(mid) is greater we adjust our search space s.t hi = mid - 1. We continue this until we search space is completely exhausted/becomes zero.

You might have seen that binary search is implemented in many ways.

This is a regular implementation of binary search. This search terminates when low > high. And the mid

```c++
bool bs(int key, int arr[],int size){
	int lo = 0;
	int hi = size - 1;
	while(lo <= hi){
		int mid = lo + (hi - lo)/2;
		if(arr[mid] == key){
			return true;
		}
		if(key > arr[mid]){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	return false;
}
```

```c++
bool bs(int key, int arr[], int size){
	int lo = 0;
	int hi = size - 1;
	while(lo < hi){
		int mid = lo + (hi - lo) / 2; // mid biased to left
		if(arr[mid] < key){
			lo = mid + 1;
		}else{ // >=
			hi = mid;
		}
	}
	return arr[lo] == key;
}
```

```c++
bool bs(int key, int arr[], int size){
	int lo = 0;
	int hi = size - 1;
	while(lo < hi){
		int mid = lo + (hi - lo + 1) / 2; // mid biased to right
		if(arr[mid] > key){
			hi = mid - 1;
		}else{ // <=
			lo = mid;
		}
	}
	return arr[lo] == key;
}
```