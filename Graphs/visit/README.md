# Visit
## The problem
We can model a network of roads connecting cities with a non-directed weighted graph G(V,E) where the vertices V represent cities, the edges E correspond to roads connecting up two cities and the weights $d(e_i)$ represent the time taken to travel from city $u$ to city $v$ where $e(u,v)\in E$. Your goal is, starting from city A at $T\geq 0$ to reach city $B$ as fast as possible. However at $T = 0$, a convoy starts its journey from city $c(1)$ to city $c(K)$ passing through cities $c(1),c(2),\ldots,c(K - 1), c(K)$ in that order. For the duration of the convoy's journey from $c(u)$ to $c(v)$ where $1\leq u,v\leq K$ and $u\neq v$ the road is blocked off for anyone trying to **enter** it. There is no restriction if someone is already traversing the road while the convoy enters the same road. For example:
- If the convoy reaches city $c(j)$ at time $t(j)$ then the road $\{c(j), c(j + 1)\}$ cannot be used from $t(j)$ up to $t(j) + d(c(j), c(j + 1)) - 1$.
- The same road can be used if someone starts traversing it at any time $t(k)\leq t(j) - 1$ or $t(k)\geq t(j) + d(c(j), c(j + 1))$.
The goal is to find the minimum amount of time to reach city $B$ with the above restrictions.
## Input
From stdin:
- First Line: $N, M$ where $N$ is the number of cities and $M$ is the number of roads.
- Second Line: $A, B, T, K$ where $A, B$ are the start and destination respectively, $T$ is the time at which you start from city $A$ and $K$ is the number of cities the convoy is going to visit.
- Third Line: Will contain $K$ positive integers which correspond to the cities $c(1), c(2),\ldots,c(K)$ in that order.
- For the next $M$ lines: The graph layout will be given in the following form: $u, v, d(u,v)$, meaning there is an edge connecting city $u$ and $v$ with distance $d(u,v)$.
### Assumptions
- The graph is connected.
- There is a road between each consecutive city in the convoy's path.
- The convoy doesn't enter the same road twice.
## Limitations
- $3\leq K \leq N \leq 60000$
- $N - 1\leq M\leq 300000$
- $0\leq d(u,v), T\leq 10000$
- Time limit: 1 sec
- Memory limit: 64MB
## Example
### Input
6 5\
1 6 20 4\
5 3 2 4\
1 2 2\
2 3 8\
2 4 3\
3 6 10\
3 5 15
### Output
21
