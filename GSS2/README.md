# GSS2 - Can you answer these queries II

> Source: http://www.spoj.com/problems/GSS2/

Being a completist and a simplist, the kid Yang Zhe only seems to get "Wrong Answer" for most of the informatics problems. Additionally, he refuses to write two program for the same task, so he always fails in contests.

When having a contest, Yang Zhe looks at the maximum possible points of every problem first. For problems of the same points, Yang Zhe will do **only one** of them. If he's lucky , he can get all the points.

Amber is going to hold a contest in SPOJ. She has made a list of **N** problems which fit Yang Zhe very well, so Yang Zhe can solve all of them. Amber lines up the problems and begins to select some. She will select a subsequence of her list for the final problem list. She'd like to select such a subsequence (can also be empty) that Yang Zhe will get the maximum amount of points.

Amber easily found such a subsequence after a few minutes. To make things harder, Amber decided that Yang Zhe can take this contest only if Yang Zhe can answer her Q questions. The questions are of the form: if the final problems are limited to a subsequence of list[X..Y] (1 <= X <= Y <= N), what's the maximal possible amount of points Yang Zhe can get?

## Input

* Line 1: integer N (1 <= N <= 100000);
* Line 2: N integers denoting the score of each problem, each of them is a integer in range [-100000, 100000];
* Line 3: integer Q (1 <= Q <= 100000);
* Line 3+i (1 <= i <= Q): two integers X and Y denoting the ith question.

## Output

Line i: a single integer, the answer to the ith question.

## Example

**Input:**

```text
9
4 -2 -2 3 -1 -4 2 2 -6
3
1 2
1 5
4 9
```

**Output:**

```text
4
5
3
```
