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
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
public:
    Solution() { __elshorpagi__; }
    void add_directed_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    int topological_ordering(vvi &graph)
    {
        int len(sz(graph));
        vi indegree(len);
        fr(i, 0, len)
        {
            fc(j, graph[i]) { ++indegree[j]; }
        }
        queue<int> ready_nodes;
        fr(i, 0, len)
        {
            if (!indegree[i])
                ready_nodes.push(i);
        }
        int cnt(0);
        while (!ready_nodes.empty())
        {
            int cur(ready_nodes.front());
            ready_nodes.pop();
            ++cnt;
            fc(neighbour, graph[cur])
            {
                if (!(--indegree[neighbour]))
                    ready_nodes.push(neighbour);
            }
        }

        return cnt;
    }
    bool canFinish(int numCourses, vvi &prerequisites)
    {
        vvi graph(numCourses);
        fc(edge, prerequisites) { add_directed_edge(graph, edge[1], edge[0]); }
        return topological_ordering(graph) == numCourses;
    }
    void TEST()
    {
        int numCourses(2);
        vvi prerequisites{{1, 0}};
        canFinish(numCourses, prerequisites) ? yes : no; // YES
        prerequisites = {{1, 0}, {0, 1}};
        canFinish(numCourses, prerequisites) ? yes : no; // NO
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