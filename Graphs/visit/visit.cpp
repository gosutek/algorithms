#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sys/types.h>
#include <utility>
#include <vector>

using namespace std;

auto desync_untie = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

typedef pair<uint32_t, uint32_t> uiPair;

struct Graph {
  vector<uiPair> *adj_list;
  uint16_t _v;

  Graph(uint16_t v) : _v(v) { this->adj_list = new vector<uiPair>[v]; }

  void addEdge(uint16_t u, uint16_t v, uint16_t t) {
    this->adj_list[u].push_back(make_pair(v, t));
    this->adj_list[v].push_back(make_pair(u, t));
  }

  uint64_t dijkstra(uint16_t src, uint16_t dst, uint16_t T,
                    map<uiPair, uiPair> &map) {
    auto cmp = [](uiPair a, uiPair b) { return a.second > b.second; };
    priority_queue<uiPair, vector<uiPair>, decltype(cmp)> q(cmp);

    vector<uint64_t> dist(_v, UINT64_MAX);
    set<uint16_t> visited;
    q.push(make_pair(src, T));
    dist[src] = T;
    uint64_t total_time = T;

    while (!q.empty()) {
      uint16_t u = q.top().first;
      uint64_t total_time = q.top().second;
      q.pop();
      if (visited.find(u) != visited.end()) {
        continue;
      } else {
        visited.insert(u);
      }
      for (vector<uiPair>::iterator i = this->adj_list[u].begin();
           i != this->adj_list[u].end(); ++i) {
        uint16_t v = i->first;
        uiPair pair = make_pair(u, v);
        uiPair rev_pair = make_pair(v, u);
        uint64_t t = i->second + total_time;
        if (map.find(pair) != map.end() || map.find(rev_pair) != map.end()) {
          if (total_time >= map[pair].first && total_time <= map[pair].second) {
            t += map[pair].second + 1 - total_time;
          } else if (total_time >= map[rev_pair].first &&
                     total_time <= map[rev_pair].second) {
            t += map[rev_pair].second + 1 - total_time;
          }
        }
        if (dist[v] > t) {
          dist[v] = t;
          q.push(make_pair(v, dist[v]));
        }
      }
    }
    return dist[dst] - T;
  }
};

int main(int argc, char *argv[]) {

  uint16_t N, K, A, B, T;
  uint32_t M;
  vector<uint16_t> c(K);
  map<uiPair, uiPair> umap;
  cin >> N;
  cin >> M;
  cin >> A;
  cin >> B;
  cin >> T;
  cin >> K;
  Graph g(N);
  for (size_t i = 0; i < K; ++i) {
    uint16_t town;
    cin >> town;
    c.push_back(town - 1);
  }
  for (uint32_t i = 0; i < M; ++i) {
    uint16_t u, v, t;
    cin >> u;
    cin >> v;
    cin >> t;
    g.addEdge(u - 1, v - 1, t);
  }
  uint32_t prev = 0;
  for (size_t i = 0; i < c.size() - 1; ++i) {
    uint16_t a = c[i], b = c[i + 1];
    for (vector<uiPair>::iterator j = g.adj_list[a].begin();
         j != g.adj_list[a].end(); ++j) {
      if (j->first == b) {
        umap[make_pair(a, b)] = make_pair(prev, prev + j->second - 1);
        prev += j->second;
      }
    }
  }
  cout << g.dijkstra(A - 1, B - 1, T, umap) << endl;

  return 0;
}
