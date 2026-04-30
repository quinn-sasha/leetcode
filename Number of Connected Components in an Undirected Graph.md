## Step1

* 無向グラフであることを、データ構造として正しく表現していなかった（有向グラフになっていた）ことで、バグが発生していた。
* 辺を持たない孤立したノードと、[2, 3]の3のようなノードが同じ状態になってしまっていた。

思考過程：
グラフの連結情報を表すデータ構造に対してDFSをして、繋がっているノードを全て訪問済みにした後に、カウントする。
全てのノードからDFSを開始して、探索では最終的にすべての辺を見ることになるので、時間計算量は O(V + E) になる。V = 2000, E = 5000 で疎なグラフなので、隣接リストを選択する。
隣接行列の場合は、時間計算量と空間計算量がどちらも O(V^2) になって、大体 2000 * 2000 = 4.0 * 10^6 と規模が跳ね上がる。
とりあえずスタックでDFSを書いた。

あとUnionFindも応用できると思った。

```cpp
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> node_to_adjacents;
        for (int i = 0; i < edges.size(); ++i) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            node_to_adjacents[node1].push_back(node2);
            node_to_adjacents[node2].push_back(node1);
        }
        std::vector<bool> visited(n, false);
        int num_components = 0;
        for (int i = 0; i < n; ++i) {
            if (!node_to_adjacents.contains(i)) {
                ++num_components;
                continue;
            }
            if (visited[i]) {
                continue;
            }
            std::stack<int> frontiers;
            frontiers.push(i);
            while (!frontiers.empty()) {
                auto node = frontiers.top();
                frontiers.pop();
                if (visited[node]) {
                    continue;
                }
                visited[node] = true;
                for (auto next_node : node_to_adjacents[node]) {
                    frontiers.push(next_node);
                }
            }
            ++num_components;
        }
        return num_components;
    }
};
```

スタックでも再帰でも探索処理を別の関数に切り出した方が良かった。
区切りをつけることで読みやすくなると思う。

## Step2

* https://github.com/h-masder/Arai60/pull/20/changes#r3109854179
> i が 0～n-1 のため、 list[list[int]] 型にもできます。こちらのほうがハッシュの計算などが省略でき、軽くなるかもしれません。

確かに今回の場合はハッシュマップじゃなくてもいい。
再帰の方がすんなり書けた。

* std::vector<bool>型で訪問ノードを記録していたが、以下のコメントを貰って、unorderedd_set を使うことにした。
* https://github.com/5ky7/arai60/pull/22#discussion_r3165583752

## Step3

最終的に、かかった時間は5分ぐらい。

再帰DFS
```cpp
class Solution {
    void traverse(int node, std::unordered_set<int>& visited,
                  std::vector<std::vector<int>>& neighbors) {
        if (visited.contains(node)) {
            return;
        }
        visited.insert(node);
        for (auto next_node : neighbors[node]) {
            traverse(next_node, visited, neighbors);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> neighbors(n);
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            neighbors[node1].push_back(node2);
            neighbors[node2].push_back(node1);
        }
        std::unordered_set<int> visited;
        int num_components = 0;
        for (int node = 0; node < n; ++node) {
            if (visited.contains(node)) {
                continue;
            }
            traverse(node, visited, neighbors);
            ++num_components;
        }
        return num_components;
    }
};
```

BFS
```cpp
class Solution {
    void traverse(int start_node, std::vector<bool>& visited, 
                  std::vector<std::vector<int>>& neighbors) {
        std::queue<int> nodes;
        nodes.push(start_node);
        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            for (auto next_node : neighbors[node]) {
                nodes.push(next_node);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> neighbors(n);
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        int num_components = 0;
        std::vector<bool> visited(n);
        for (int node = 0; node < n; ++node) {
            if (visited[node]) {
                continue;
            }
            traverse(node, visited, neighbors);
            ++num_components;
        }
        return num_components;
    }
};
```

Uinon Find
```cpp
#include <vector>

class UnionFind {
  std::vector<int> parent_;
  std::vector<int> size_;

public:
  UnionFind(int max_size) {
    parent_.resize(max_size);
    for (int i = 0; i < max_size; ++i) {
      parent_[i] = i;
    }
    size_.resize(max_size, 1);
  }

  int find(int x) {
    if (parent_[x] == x) {
      return x;
    }
    parent_[x] = find(parent_[x]);
    return parent_[x];
  }

  // Returns true if x and y are merged, otherwise false
  bool unions(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root == y_root) {
      return false;
    }
    int smaller = x_root;
    int bigger = y_root;
    if (size_[x_root] > size_[y_root]) {
      smaller = y_root;
      bigger = x_root;
    }
    parent_[smaller] = bigger;
    size_[bigger] += size_[smaller];
    return true;
  }
};

class Solution {
public:
  int countComponents(int n, std::vector<std::vector<int>> &edges) {
    int num_components = n;
    UnionFind union_find(n);
    for (int i = 0; i < edges.size(); ++i) {
      int node1 = edges[i][0];
      int node2 = edges[i][1];
      if (union_find.unions(node1, node2)) {
        --num_components;
      }
    }
    return num_components;
  }
};
```




