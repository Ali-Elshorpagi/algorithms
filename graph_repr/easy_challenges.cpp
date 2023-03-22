#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*---------------------------Problem #1: Edge List Representation--------------------*/

struct Edge_0
{
    int from, to, weight;
    Edge_0(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    const bool operator<(const Edge_0 &e)
    {
        return weight < e.weight;
    }
    void print()
    {
        cout << "Edge (" << from << " " << to << " " << weight << ")" << edl;
    }
};

typedef vector<Edge_0> GRAPH_0;

void add_edge_list_reper(GRAPH_0 &graph, int from, int to, int weight)
{
    graph.push_back({from, to, weight});
}

void print_adjaceny_edge_list(GRAPH_0 &graph)
{
    int len(sz(graph));
    for (int e(0); e < len; ++e)
        graph[e].print();
}

void build_edge_list_epresentation() // O(E) time, O(E) space
{
    // this representation in general is slower representation
    // and it's has very limited usege, but it's very simple
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH_0 graph;

    for (int e(0); e < edges; ++e)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        add_edge_list_reper(graph, from, to, weight);
    }
    sort(all(graph)); // sort depend on the operator overloading;
    print_adjaceny_edge_list(graph);
}

/*-------------------------Problem #2: Adjacency Hashset Representation--------------------*/

typedef vector<unordered_set<int>> GRAPH_1;

void add_directed_edge_hashset_reper(GRAPH_1 &graph, int from, int to)
{
    graph[from].insert(to);
}

void add_undirected_edge_hashset_reper(GRAPH_1 &graph, int from, int to)
{
    graph[from].insert(to);
    graph[to].insert(from);
}

void print_adjaceny_edge_hashset(GRAPH_1 &graph)
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

void build_edge_hashset_representation()
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

    GRAPH_1 graph(nodes);

    for (int e(0); e < edges; ++e)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge_hashset_reper(graph, from, to);
        // add_undirected_edge_hashset_reper(graph, from, to);
    }
    print_adjaceny_edge_hashset(graph);
}

void Solve()
{
    // build_edge_list_epresentation();
    build_edge_hashset_representation();
    cout << edl << "DONE" << edl;
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