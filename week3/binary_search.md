# Binary Search

computation of mid in binary search

the mid of range [low, high]
can be computed using formula
~~~
mid = low + high / 2
~~~
But this fails if sum of low and high exceeds 2^31-1. The resultant sum overflows to a negative value. This might result in unpredictable resutls or Index out of bound error.
<br>
The best way to fix this is 
~~~
// Method 1
mid = low + ((high - low) / 2)
// Method 2 : Probably Fast computation
mid = ((unsigned int) low + (unsigned int) high) >> 2
~~~

Now we can compute mid bug free. Lets dive even deeper into computation of mid.
Now I claim that in binary search mid is baised towards left index. To prove this
<br>
Lets us consider any adjacent indices say 0 and 1
i.e low = 0, high = 1
now i we compute mid using above mention formule it will always end upto to be euqal to value of low, in this case value of mid is 0.
<br>
If my modified binary search code is smiliar to one writtern, it will end up running infinitely
~~~
low
high
while(low < high){
    mid = low + (high - low) / 2
    if(f(mid) <= target){
        low = mid;
    }else{
        high = mid - 1;
    }
}
~~~
This can fixed by
~~~
low
high
while(low < high){
    mid = low + (high - low) / 2
    if(f(mid) >= target){
        high = mid;
    }else{
        low = mid + 1;
    }
}
~~~
This loop will never terminate. Apply our above example in these code snippets, consider and observe