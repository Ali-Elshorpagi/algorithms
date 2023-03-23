#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*---------------------------Problem #1: Edge List Representation--------------------*/

struct Edge
{
    int from, to, weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
    void print()
    {
        cout << "Edge (" << from << " " << to << " " << weight << ")" << edl;
    }
};

typedef vector<Edge> GRAPH_0;

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

void build_problem_1() // O(E) time, O(E) space
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

void build_problem_2()
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

/*-------------------------Problem #3: Adjacency matrix with multiple Edges--------------------*/

// Each cell in the matrix graph[from][to] is a list of the cost
typedef vector<vector<vector<int>>> GRAPH_2;

void add_directed_multiple_edges(GRAPH_2 &graph, int from, int to, int weight)
{
    graph[from][to].push_back(weight);
}

void print_adjaceny_multiple_edges(GRAPH_2 &graph)
{
    int len(sz(graph));
    for (int from(0); from < len; ++from)
    {
        for (int to(0); to < len; ++to)
        {
            for (int &weight : graph[from][to])
            {
                cout << "From " << from << " to " << to
                     << " the weight is " << weight << edl;
            }
        }
    }
}

void build_problem_3()
{
    /*
     * Space Complexity is :  O(V^2 + E)
     * Time complexity : O(1) to check edge (u, v)
     */

    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH_2 graph(nodes, vvi(nodes));

    for (int e(0); e < edges; ++e)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        add_directed_multiple_edges(graph, from, to, weight);
    }
    print_adjaceny_multiple_edges(graph);
}

void Solve()
{
    // build_problem_1();
    // build_problem_2();
    build_problem_3();
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}