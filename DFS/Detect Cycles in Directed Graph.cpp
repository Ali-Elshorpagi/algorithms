#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

/** Detect Cycles in Directed Graph */

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void add_directed_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    void dfs(vvi &graph, vi &started, vi &finished, int node, int &time)
    {
        started[node] = time++;
        fc(it, graph[node])
        {
            if (started[it] == -1)
            {
                cout << "Tree Edge : " << node << ' ' << it << edl;
                dfs(graph, started, finished, it, time);
            }
            else // 3 cases for a visited node
            {
                if (started[node] < started[it])
                    cout << "Forward Edge : " << node << ' ' << it << edl;
                else if (finished[it] == -1) // cycle: started before me, didn't finish yet, that's the node must be active in the stack calls;
                    cout << "Back Edge ( Cycle ) : " << node << ' ' << it << edl;
                else
                    cout << "Cross Edge : " << node << ' ' << it << edl;
            }
        }
        finished[node] = time++;
    }
    void classify_edges(vvi &graph)
    {
        int nodes(sz(graph)), time(1);
        vi started(nodes, -1), finished(nodes, -1);
        fr(i, 0, nodes)
        {
            if (started[i] == -1) // not visited
                dfs(graph, started, finished, i, time);
        }
        cout << "*****************************" << edl;
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
        classify_edges(graph);
    }
};

int main()
{
    Solution sol;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);

    /**
    input :

    5
    3 3
    0 1
    0 2
    2 1
    3 3
    0 1
    0 2
    1 2
    9 9
    1 2
    2 3
    3 4
    1 5
    5 6
    6 7
    6 8
    6 3
    4 2
    7 11
    0 1
    0 6
    1 2
    1 6
    2 3
    2 0
    3 1
    3 6
    4 2
    4 3
    4 5
    9 9
    0 1
    0 2
    1 3
    1 4
    2 5
    2 6
    4 7
    8 2
    8 6


    output :

    Case #5
    Tree Edge : 0 1
    Tree Edge : 0 2
    Cross Edge : 2 1
    *****************************
    Case #4
    Tree Edge : 0 1
    Tree Edge : 1 2
    Forward Edge : 0 2
    *****************************
    Case #3
    Tree Edge : 1 2
    Tree Edge : 2 3
    Tree Edge : 3 4
    Back Edge ( Cycle ) : 4 2
    Tree Edge : 1 5
    Tree Edge : 5 6
    Tree Edge : 6 7
    Tree Edge : 6 8
    Cross Edge : 6 3
    *****************************
    Case #2
    Tree Edge : 0 1
    Tree Edge : 1 2
    Tree Edge : 2 3
    Back Edge ( Cycle ) : 3 1
    Tree Edge : 3 6
    Back Edge ( Cycle ) : 2 0
    Forward Edge : 1 6
    Forward Edge : 0 6
    Cross Edge : 4 2
    Cross Edge : 4 3
    Tree Edge : 4 5
    *****************************
    Case #1
    Tree Edge : 0 1
    Tree Edge : 1 3
    Tree Edge : 1 4
    Tree Edge : 4 7
    Tree Edge : 0 2
    Tree Edge : 2 5
    Tree Edge : 2 6
    Cross Edge : 8 2
    Cross Edge : 8 6
    *****************************

    DONE
    */
}