#include <iostream>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

typedef vector<vector<int>> GRAPH;

// link : https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// code : leetcode 323

class Solution // // O(V + E) time, O(V + E) space
{
public:
    Solution() { Mesh_Ali; }
    void dfs(GRAPH &graph, int root, vector<bool> &visited)
    {
        if (visited[root])
            return;
        visited[root] = true;
        fc(neigh, graph[root])
        {
            if (!visited[neigh])
                dfs(graph, neigh, visited);
        }
    }
    int countComponents(int n, GRAPH &edges)
    {
        GRAPH graph(n);
        int len(sz(edges));
        fr(i, 0, len)
        {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }
        int cnt(0);
        vector<bool> visited(n);
        fr(i, 0, n)
        {
            if (!visited[i])
                ++cnt, dfs(graph, i, visited);
        }
        return cnt;
    }
    void TEST()
    {
        int n(5);
        GRAPH edges{{0, 1}, {1, 2}, {3, 4}};
        cout << countComponents(n, edges) << edl;
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
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}