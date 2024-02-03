#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
public:
    Solution() { __elshorpagi__; }
    void add_directed_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    int topological_ordering(vvi &graph, int len)
    {
        vi indegree(len);
        fr(i, 0, len)
        {
            fc(j, graph[i])++ indegree[j];
        }
        queue<int> ready_nodes;
        fr(i, 0, len)
        {
            if (!indegree[i])
                ready_nodes.push(i);
        }
        int cnt(0), pick(0); // instead of the ordering vector to reduce the usage of memory
        while (!ready_nodes.empty())
        {
            int sze(sz(ready_nodes));
            pick += sze;
            while (sze--)
            {
                int cur(ready_nodes.front());
                ready_nodes.pop();
                fc(neighbour, graph[cur])
                {
                    if (!(--indegree[neighbour]))
                        ready_nodes.push(neighbour);
                }
            }
            ++cnt;
        }
        return (pick == len ? cnt : -1);
    }
    int minimumSemesters(int n, vvi &relations)
    {
        vvi graph(n);
        fc(edge, relations) add_directed_edge(graph, edge[0] - 1, edge[1] - 1); // cus it's 1-Based
        return topological_ordering(graph, n);
    }
    void TEST()
    {
        int n(3);
        vvi relations{{1, 3}, {2, 3}};
        cout << minimumSemesters(n, relations) << edl; // 2
        relations = {{1, 2}, {2, 3}, {3, 1}};
        cout << minimumSemesters(n, relations) << edl; // -1
    }
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}