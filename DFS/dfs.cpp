#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> GRAPH;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Worst-Case Time    O(N + M)
 *          M = no.Edges = N - 1
 *          so it's O(N + (N - 1)) = O(2N -1) = O(N)
 *          Note : it's O(N^2) for adjacency matrix
 *
 * Worst-Case Space  O(N), but we consider that each Node has a body O(1)
 *                         if the Node body has O(M) memory, it becomes O(N * M)
 */

void add_directed_edge_using_adjaceny_list(GRAPH &graph, int from, int to)
{
    graph[from].emplace_back(to);
}

void print_adjaceny_list(GRAPH &graph)
{
    int nodes sz(graph);
    for (int from(0); from < nodes; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int to(0); to < sz(graph[from]); ++to)
            cout << graph[from][to] << ' ';
        cout << edl;
    }
}

void dfs(GRAPH &graph, int node, vector<bool> &visited)
{
    visited[node] = true;
    for (auto &neighbour : graph[node])
    {
        if (!visited[neighbour]) // avoid cycling
        {
            cout << "\tWe can reach " << neighbour << edl;
            dfs(graph, neighbour, visited);
        }
    }
}
void reachability(GRAPH &graph)
{
    int nodes sz(graph);
    for (int i(0); i < nodes; ++i)
    {
        vector<bool> visited(nodes); // reset
        cout << "Reachable set of node " << i << edl;
        dfs(graph, i, visited);
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
        add_directed_edge_using_adjaceny_list(graph, from, to);
    }
    reachability(graph);
}

int main()
{
    Mesh_Ali;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}