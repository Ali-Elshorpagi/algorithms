#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*-----Problem #2: Adjacency Hashset Representation--------------------*/

typedef vector<unordered_set<int>> GRAPH;

void add_directed_edge_hashset_reper(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
}

void add_undirected_edge_hashset_reper(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
    graph[to].insert(from);
}

void print_adjaceny_edge_hashset(GRAPH &graph)
{
    int len(sz(graph));
    for (int from(0); from < len; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (auto &to : graph[from])
            cout << to << ' ';
        cout << edl;
    }
}

void Solve()
{
    /*
     Space Complexity is O(E)
     Time complexity
        - O(1) for add/remove/check edge
        - O(Degree) for iterate on neighbors
    Disadvantages
        - No order guarantee for edges
        - Impractical for multiple edges  (we may do workarounds)
        - Hash tables extra memory
        - Like any hash tables, more caution to properly deal with the load (load factor)
    */

    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);

    for (int e(0); e < edges; ++e)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge_hashset_reper(graph, from, to);
        // add_undirected_edge_hashset_reper(graph, from, to);
    }
    print_adjaceny_edge_hashset(graph);
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}