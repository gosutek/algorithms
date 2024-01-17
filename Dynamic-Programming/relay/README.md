# Relay
## The Problem
You represent a mail delivery agency and are given $N$ cities $V_1,\ldots,V_N$. The road network is pretty simple and has a tree structure. Each city $V_i$ has a unique path to the **capital** $V_1$. In **every** city $V_i$ there is a mailman that needs $P_i$ seconds to load the city's mail onto his vehicle and $S_i$ seconds to travel **each** kilometre of the path $V_i-V_1$.
- The mailmen cannot deviate from the path to the capital, i.e. a mailman that starts at $V_i$ can only move on the path $V_i-V_1$.
- When a mailman, who started at city $V_i$, reaches a intermediate town $V_j$ where $j$ lies on the path to $V_1$ he can *relay* the mail he had transported thus far to the mailman at city $V_j$. This mailman will in turn need $P_i$ seconds to load the mail and $S_i$ for each kilometre on the path to the capitcal $V_j-V_1$.
- Each city has a sufficiently large number of mailmen which all share the same characteristics, i.e. all mailmen from city $V_i$ need $P_i$ seconds to load and $S_i$ seconds to travel. Therefore when a mailman from another city reaches $V_i$, he can **always** relay his mail to a mailman in city $V_i$.

You need to find for each city $V_i~:~1< i \leq N$ the minimum amount of time required for that city's mail to reach the capital.
## Input
On the first line you are given a number that corresponds to the number of cities $N$. The next $N - 1$ lines contain three positive integers $V_i,V_j,D_{ij}$ which define a path of length $D_{ij}$ between cities $V_i$ and $V_j$. Then follow $N - 1$ more lines with two positives integers each. The pair of numbers $P_{i + 1}$ and $S_{i + 1}$ indicates that the mailman in city $V_{i + 1}$ needs $P_{i+1}$ seconds to get prepared and $S_{i + 1}$ seconds for each kilometre of the path $V_{i + 1} - V_1$. The road network is connected and has a tree structure.
## Limitations
- $3\leq N\leq 8000$
- $1\leq D_{ij},P_i,S_i\leq 10^7$
- Time limit: 1 sec.
- Memory limit: 64MB
## Example
### Input
5\
1 2 20\
2 3 12\
2 4 1\
4 5 3\
26 9\
1 10\
500 2\
2 30
### Output
206 321 542 328
