#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*-------Problem #1: Adjacency-based repr for flights v1--------*/
struct Edge
{
    string to;
    int weight;
    bool operator<(const Edge &e) const
    {
        if (e.to == to)
            return weight < e.weight;
        return to < e.to;
    }
};

typedef map<string, multiset<Edge>> GRAPH;

void add_directed_edge_using_adjaceny_matrix(GRAPH &graph, string from, string to, int weight)
{
    graph[from].insert({to, weight});
}

void print_adjaceny_matrix(GRAPH &graph)
{
    int len(sz(graph));
    for (auto &node : graph)
    {
        cout << "Flights from " << node.first << ": " << edl;
        for (const Edge &edge : node.second)
            cout << "\tTo " << edge.to << " with cost " << edge.weight << edl;
    }
}

void Solve()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph;

    for (int e(0); e < edges; ++e)
    {
        string from, to;
        int weight;
        cin >> from >> to >> weight;
        add_directed_edge_using_adjaceny_matrix(graph, from, to, weight);
    }
    print_adjaceny_matrix(graph);

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