#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> GRAPH;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

const int oo = 1e7; // A big value expressing infinity

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void add_directed_edge(GRAPH &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    void BFS(GRAPH &graph, int start, vi &parent)
    {
        queue<int> nodes;
        vi visited(sz(graph), oo);
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
    }
    void print_chain(vi &parent, int node)
    {
        if (node == -1)
            return;
        print_chain(parent, parent[node]);
        cout << node << ' ';
    }
    void print_path(GRAPH &graph, int start = 0)
    {
        vi parent(sz(graph), -1);
        BFS(graph, start, parent);
        fr(target, 0, sz(graph))
        {
            if (target == start)
                continue;
            cout << "Path from " << start << " to " << target << " : ";
            if (parent[target] == -1)
                cout << "Not Exist";
            else
                print_chain(parent, target);
            cout << edl;
        }
    }
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
        print_path(graph);
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
    /*
    input :
    2
    5 4
    0 1
    1 2
    2 3
    4 3
    9 13
    1 3
    1 5
    1 6
    3 5
    4 3
    3 7
    5 4
    6 0
    2 4
    2 8
    0 2
    2 8
    2 2


    output :

    Case #2
    Path from 0 to 1 : 0 1
    Path from 0 to 2 : 0 1 2
    Path from 0 to 3 : 0 1 2 3
    Path from 0 to 4 : Not Exist
    Case #1
    Path from 0 to 1 : Not Exist
    Path from 0 to 2 : 0 2
    Path from 0 to 3 : 0 2 4 3
    Path from 0 to 4 : 0 2 4
    Path from 0 to 5 : 0 2 4 3 5
    Path from 0 to 6 : Not Exist
    Path from 0 to 7 : 0 2 4 3 7
    Path from 0 to 8 : 0 2 8

    DONE

    */
}