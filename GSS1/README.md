# GSS1 - Can you answer these queries I

> Source: http://www.spoj.com/problems/GSS1/

You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ **N** ≤ 50000 ). A query is defined as follows: 

```text
Query(x, y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
``` 

Given **M** queries, your program must output the results of these queries.

### Input

* The first line of the input file contains the integer **N**.
* In the second line, **N** numbers follow.
* The third line contains the integer **M**.
* M lines follow, where line i contains 2 numbers xi and yi.

### Output

Your program should output the results of the **M** queries, one query per line.

### Example

**Input:**
```text
3 
-1 2 3
1
1 2
```

**Output:**
```text
2
```
