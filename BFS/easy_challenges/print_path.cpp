#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> GRAPH;

#define _CRT_SECURE_NO_DEPRECATE
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))

const int oo = 10000000; // A big value expressing infinity

class Solution
{
public:
    void add_directed_edge(GRAPH &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    vi BFS(GRAPH &graph, int start)
    {
        queue<int> nodes;
        vi visited(sz(graph), oo);
        vi parent(sz(graph), oo);
        nodes.push(start);
        visited[start] = 0;
        for (int level(0), sze(1); !nodes.empty(); ++level, sze = sz(nodes))
        {
            while (sze--)
            {
                int cur(nodes.front());
                nodes.pop();
                fc(neighbour, graph[cur])
                {
                    if (visited[neighbour] == oo) // never visited
                    {
                        nodes.push(neighbour);
                        visited[neighbour] = level + 1;
                        parent[neighbour] = cur;
                    }
                }
            }
        }
        return parent;
    }
    void print_path(GRAPH &graph, vi &parent) {}

    void TEST()
    {
        int nodes, edges;
        cin >> nodes >> edges;
        GRAPH graph(nodes);
        fr(e, 0, edges)
        {
            int from, to;
            cin >> from >> to;
            add_directed_edge(graph, from, to);
        }
        vi parent = BFS(graph, 0);
        print_path(graph, parent);
    }
};

int main()
{
    Solution sol;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}