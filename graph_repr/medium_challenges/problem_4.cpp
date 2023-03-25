#include <iostream>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].emplace_back(to);
}

void print_chain(GRAPH &graph, int from)
{
    cout << from << ' ';
    if (sz(graph[from]))
        print_chain(graph, graph[from][0]);
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
        add_undirected_edge(graph, from, to);
    }
    int q, node;
    cin >> q;
    while (q--)
    {
        cin >> node;
        print_chain(graph, node);
        cout << edl;
    }
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