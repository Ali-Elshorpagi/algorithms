#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Worst-Case Time  O(V + E)
 *                    - V = no.Nodes
 *                    - E = no.Edges
 * Worst-Case Space  O(V)
 *
 */

class Algorithm // Using Kahn's Algorithm
{
public:
    void add_directed_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    vi topological_ordering(vvi &graph)
    {
        int len(sz(graph));
        vi indegree(len);
        for (int i(0); i < len; ++i) // compute the indegrees of each node
        {
            for (int &j : graph[i])
                ++indegree[j];
        }
        queue<int> ready_nodes;
        for (int i(0); i < len; ++i)
        {
            if (!indegree[i]) // add all nodes that has indegree(0)
                ready_nodes.push(i);
        }
        vi ordering;
        while (!ready_nodes.empty())
        {
            int cur(ready_nodes.front());
            ready_nodes.pop();
            ordering.emplace_back(cur);
            for (int &neighbour : graph[cur])
            {
                if (!(--indegree[neighbour]))    // if the neighbour become has indegree(0)
                    ready_nodes.push(neighbour); // push it in the queue
            }
        }
        if (sz(ordering) != len) // There is a cycle
            ordering.clear();
        return ordering;
    }
    void TEST()
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vvi graph(nodes);
        for (int e(0); e < edges; ++e)
        {
            int from, to;
            cin >> from >> to;
            add_directed_edge(graph, from, to);
        }
        vi ordering = topological_ordering(graph);
        if (ordering.empty())
            cout << "There is a cycle";
        else
        {
            for (int &it : ordering)
                cout << it << ' ';
        }
        cout << edl;
    }
};

int main()
{
    Algorithm sol;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;

    /*
    intput :

     2
     10 10
     5 0
     5 7
     6 7
     6 8
     0 1
     7 2
     8 2
     1 2
     2 4
     2 3
     9 11
     5 0
     5 7
     6 7
     6 8
     0 1
     7 2
     8 2
     1 2
     2 4
     2 3
     2 6


     Output:

     5 6 9 0 7 8 1 2 4 3
     There is a cycle

     */
    return (0);
}