#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

// link : https://leetcode.com/problems/minimum-height-trees/
// code : leetcode 310

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void add_undirected_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
        graph[to].emplace_back(from);
    }
    vi topological_ordering(vvi &graph)
    {
        int len(sz(graph));
        vi indegree(len);
        fr(i, 0, len)
        {
            fc(j, graph[i]) { ++indegree[j]; }
        }
        queue<int> ready_nodes;
        fr(i, 0, len)
        {                         // leaves
            if (indegree[i] == 1) // cus this is Undirected Graph
                ready_nodes.push(i);
        }
        vi ordering;
        while (!ready_nodes.empty())
        {
            int sze(sz(ready_nodes));
            cl(ordering);
            while (sze--)
            {
                int cur(ready_nodes.front());
                ready_nodes.pop();
                ordering.emplace_back(cur);
                fc(neighbour, graph[cur])
                {
                    if ((--indegree[neighbour]) == 1)
                        ready_nodes.push(neighbour);
                }
            }
        }
        return ordering;
    }
    vi findMinHeightTrees(int n, vvi &edges)
    {
        if (n < 2)
        {
            vi ans;
            fr(i, 0, n) { ans.emplace_back(i); }
            return ans;
        }
        vvi graph(n);
        fc(edge, edges) { add_undirected_edge(graph, edge[0], edge[1]); }
        return topological_ordering(graph);
    }
    void TEST()
    {
        int n(4);
        vvi edges{{1, 0}, {1, 2}, {1, 3}};
        vi ans = findMinHeightTrees(n, edges);
        fc(it, ans) { cout << it << ' '; } // [1]
        cout << edl;
        n = 6;
        edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
        ans = findMinHeightTrees(n, edges);
        fc(it, ans) { cout << it << ' '; } // [3, 4]
    }
};

int main()
{
    Solution sol;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}