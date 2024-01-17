# Stocks
## The problem
You have managed to gather information to be able to predict the exact prices of a stock for the following $N$ days. **Given a sequence of prices $p(1),\ldots,p(N)$ you need to find the maximum profit you can achieve by performing at most $K$ transactions.**
Let $M~:~0\leq M \leq K$ be the number of transactions you perform. Let $b_1,\ldots,b_M$ be the days where you buy a stock and $s_1,\ldots,s_M$ be the days where you sell a stock. The following must be true:
$$1\leq b_1< s_1 < b_2 < s_2 < \ldots < b_M < s_M \leq N$$
i.e. you need to sell a stock before you buy another one.

- This problem is basically the same as [LeetCode 188](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)
## Input
You are given two positive integers separated by a whitespace. The first one corresponds to the number of days $N$ while the second one corresponds to the maximum number of transactions $K$. On the next line you are given $N$ whitespace-separated numbers which correspond to the prices $p(1),\ldots,p(N)$.
## Limitations
- $1\leq N \leq 10^5$
- $1\leq K\leq 10^3$
- $1\leq p(i)\leq 10^4$
- Running time: 1 sec
- Memory: 64 MB
## Example
### Input 1
10 3\
12 12 7 10 15 8 3 4 8 8
### Output 1
13
### Input 2
5 2\
10 9 8 7 6
### Output 2
0
