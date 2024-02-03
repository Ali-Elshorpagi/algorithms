#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * Space Complexity :  O(V^2), that's mean O(|V|^2)
 * Time Complexity :
 *  - Checking if there is an edge (u, v) :  O(1) from mat[u][v]
 *  - Given node u: list all its neighbours :  O(V) iterate on row
 *  - Traversing the whole graph :  O(V^2) iterate on matrix
 *
 * # This Representation is good for Dense Graph
 */

/*---------------------------Adjacency Matrix Representation----------------------------*/

void add_directed_edge_using_adjaceny_matrix(vvi &graph, int from, int to)
{
    graph[from][to] += 1;
}

void add_undirected_edge_(vvi &graph, int from, int to)
{
    graph[from][to] += 1;
    graph[to][from] += 1;
}

void print_adjaceny_matrix(vvi &graph)
{
    int len(sz(graph));
    for (int from(0); from < len; ++from)
    {
        for (int to(0); to < len; ++to)
        {
            if (graph[from][to])
                cout << "From " << from << " to " << to
                     << " there ara " << graph[from][to] << " edges" << edl;
        }
    }
}

void build_the_graph_using_adjaceny_matrix()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vvi graph(nodes, vi(nodes));

    for (int e(0); e < edges; ++e)
    {
        // if there is a weight, u can take it and assign it to the matrix -> graph[from][to] = weight;
        int from, to;
        cin >> from >> to;
        add_directed_edge_using_adjaceny_matrix(graph, from, to);
        // add_undirected_edge_using_adjaceny_matrix(graph, from, to);
    }
    print_adjaceny_matrix(graph);
}

/*---------------------------Adjacency List Representation----------------------------*/

/*
 * Space Complexity :  O(E + V), that's mean O(|E| + |V|)
 * Time Complexity :
 *  - Checking if there is an edge (u, v) :  O(Degree), that's mean u must iterate on ur |neighbours|;
 *  - Given node u: list all its neighbours :  O(Degree)
 *  - Traversing the whole graph :  O(E + V)
 *  - In directed graph: counting the in-degree of a node :  O(E + V), which is very expensive;
 *
 * # This Representation is good for Sparse Graph
 */

struct Edge // u can use stl::pair instead of struct
{
    int to, weight;
};

typedef vector<vector<Edge>> GRAPH;

void add_directed_edge_using_adjaceny_list(GRAPH &graph, int from, int to, int weight)
{
    graph[from].push_back({to, weight});
}

void add_undirected_edge_using_adjaceny_list(GRAPH &graph, int from, int to, int weight)
{
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

void print_adjaceny_list(GRAPH &graph)
{
    int len(sz(graph));
    for (int from(0); from < len; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int edge(0); edge < sz(graph[from]); ++edge)
        {
            cout << "(to " << graph[from][edge].to
                 << " weight " << graph[from][edge].weight << ") ";
        }
        cout << edl;
    }
}

void build_the_graph_using_adjaceny_list()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);
    for (int e(0); e < edges; ++e)
    {
        // we build it with weight;
        int from, to, weight;
        cin >> from >> to >> weight;
        add_directed_edge_using_adjaceny_list(graph, from, to, weight);
        // add_undirected_edge_using_adjaceny_list(graph, from, to, weight);
    }
    print_adjaceny_list(graph);
}

void Solve()
{
    // build_the_graph_using_adjaceny_matrix();
    build_the_graph_using_adjaceny_list();

    cout << edl << "DONE" << edl;
}
int main()
{
    __elshorpagi__;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}