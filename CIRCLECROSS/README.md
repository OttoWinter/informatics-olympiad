# CIRCLECROSS - Why Did the Cow Cross the Road

> Source: http://www.usaco.org/index.php?page=viewproblem2&cpid=719

The layout of Farmer John's farm is quite peculiar, with a large circular road running around the perimeter of the main field on which his cows graze during the day. Every morning, the cows cross this road on their way towards the field, and every evening they all cross again as they leave the field and return to the barn.

As we know, cows are creatures of habit, and they each cross the road the same way every day. Each cow crosses into the field at a different point from where she crosses out of the field, and all of these crossing points are distinct from each-other. Farmer John owns `N` cows, conveniently identified with the integer IDs 1…`N`, so there are precisely 2·`N` crossing points around the road. Farmer John records these crossing points concisely by scanning around the circle clockwise, writing down the ID of the cow for each crossing point, ultimately forming a sequence with 2·`N` numbers in which each number appears exactly twice. He does not record which crossing points are entry points and which are exit points.

Looking at his map of crossing points, Farmer John is curious how many times various pairs of cows might cross paths during the day. He calls a pair of cows (`a`,`b`) a "crossing" pair if cow aa's path from entry to exit must cross cow bb's path from entry to exit. Please help Farmer John count the total number of crossing pairs.

### Input

The first line of input contains `N` (1≤`N`≤50,000), and the next 2·`N` lines describe the cow IDs for the sequence of entry and exit points around the field.

### Output
Please print the total number of crossing pairs.

### Sample

**Input:**

```text
4
3
2
4
4
1
3
2
1
```


**Output:**

```text
3
```

*Problem credits: Brian Dean*