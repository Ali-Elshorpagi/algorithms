#include <iostream>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].emplace_back(to);
}

void print_paths_len_2(GRAPH &graph)
{
    int nodes(sz(graph)), first, second;
    for (int i(0); i < nodes; ++i) // iterate on nodes
    {
        for (int j(0); j < sz(graph[i]); ++j) // iterate on the node's neighbors
        {
            first = graph[i][j];
            for (int k(0); k < sz(graph[first]); ++k) // iterate on the neighbors
            {
                second = graph[first][k];
                cout << i << ' ' << first << ' ' << second << edl;
            }
        }
    }
}

void Solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    GRAPH graph(nodes);
    for (int e(0); e < edges; ++e)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }
    print_paths_len_2(graph);
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}