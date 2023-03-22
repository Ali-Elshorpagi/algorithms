#include <iostream>
#include <vector>
#include <algorithm>

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

/*---------------------------Problem #1: Edge List Representation--------------------*/

struct Edge
{
    int from, to, weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    const bool operator<(const Edge &e)
    {
        return weight < e.weight;
    }
    void print()
    {
        cout << "Edge (" << from << " " << to << " " << weight << ")" << edl;
    }
};

typedef vector<Edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int weight)
{
    graph.push_back({from, to, weight});
}

void print_adjaceny_edge_list(GRAPH &graph)
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

    GRAPH graph;

    for (int e(0); e < edges; ++e)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        add_edge(graph, from, to, weight);
    }
    sort(all(graph));
    print_adjaceny_edge_list(graph);
}

/*---------------------------Problem #2: Adjacency Hashset Representation--------------------*/

void Solve()
{
    // build_edge_list_epresentation();
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