#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> GRAPH;

#define _CRT_SECURE_NO_DEPRECATE
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Worst-Case Time  O(E + V)
 *
 * Worst-Case Space O(V)
 *
 * It's similar to DFS
 *
 */

const int oo = 1e7; // A big value expressing infinity

class Algorithm
{
public:
    void add_undirected_edge(GRAPH &graph, int from, int to)
    {
        graph[from].emplace_back(to);
        graph[to].emplace_back(from);
    }

    vi BFS_V1(GRAPH &graph, int start) // return the visited nodes
    {
        // pair<int,int> = node'value - node's level
        queue<pii> nodes;
        vi visited(sz(graph), oo);
        nodes.push({start, 0});
        visited[start] = 0;
        while (!nodes.empty())
        {
            pii p(nodes.front());
            nodes.pop();
            int cur(p.first), level(p.second);
            for (auto &neighbour : graph[cur])
            {
                if (visited[neighbour] == oo) // never visited
                {
                    nodes.push({neighbour, level + 1});
                    visited[neighbour] = level + 1;
                }
            }
        }
        return visited;
    }

    vi BFS_V2(GRAPH &graph, int start) // more smarter
    {
        queue<int> nodes;
        vi visited(sz(graph), oo);
        nodes.push(start);
        visited[start] = 0; // the value == the level
        for (int level(0), sze(sz(nodes)); !nodes.empty(); ++level, sze = sz(nodes))
        {
            while (sze--)
            {
                int cur(nodes.front());
                nodes.pop();
                for (auto &neighbour : graph[cur])
                {
                    if (visited[neighbour] == oo) // never visited
                    {
                        nodes.push(neighbour);
                        visited[neighbour] = level + 1;
                    }
                }
            }
        }
        return visited;
    }

    void TEST()
    {
        int nodes, edges;
        cin >> nodes >> edges;

        GRAPH graph(nodes);

        for (int e(0); e < edges; ++e)
        {
            int from, to;
            cin >> from >> to;
            add_undirected_edge(graph, from, to);
        }
        vi visited = BFS_V1(graph, 1);
        for (auto it : visited)
            cout << it << ' ';
    }
};

int main()
{
    Algorithm algo;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}