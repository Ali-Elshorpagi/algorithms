#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

// link : https://leetcode.com/problems/course-schedule-ii/
// code : leetcode 210

/*
 * # Complexities
 *
 * Worst-Case Time  O(V + E)
 *                    - V = no.Nodes
 *                    - E = no.Edges
 * Worst-Case Space  O(V + E)
 *
 */

class Algorithm // Using DFS Algorithm
{
public:
    Algorithm() { Sukuna; }
    void add_directed_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    bool dfs(vvi &graph, int node, vi &started, vi &finished, int &time, vi &ordering)
    {
        started[node] = time++;
        fc(neighbour, graph[node])
        {
            if (started[neighbour] == -1)
            {
                if (dfs(graph, neighbour, started, finished, time, ordering))
                    return true; // cycle
            }
            else if (finished[neighbour] == -1)
                return true; // back edge
        }
        finished[node] = time++;
        ordering.emplace_back(node); // like print Node in slides;
        return false;                // no cycle
    }
    vi topological_ordering(vvi &graph)
    {
        int nodes(sz(graph)), time(1);
        vi started(nodes, -1), finished(nodes, -1), ordering;
        fr(i, 0, nodes)
        {
            if (started[i] == -1) // not visited
            {
                if (dfs(graph, i, started, finished, time, ordering))
                    return vi(); // cycle
            }
        }
        reverse(all(ordering));
        return ordering;
    }
    vi findOrder(int numCourses, vvi &prerequisites)
    {
        vvi graph(numCourses);
        fc(edge, prerequisites) { add_directed_edge(graph, edge[1], edge[0]); }
        return topological_ordering(graph);
    }
    void TEST()
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vvi graph(nodes);
        fr(e, 0, edges)
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
            fc(it, ordering) { cout << it << ' '; }
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


    output:

    9 6 8 5 7 0 1 2 3 4
    There is a cycle

    */
    return (0);
}