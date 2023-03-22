#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<char> vc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

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

struct Edge
{
    int to;
    int weight;
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
    Mesh_Ali;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}