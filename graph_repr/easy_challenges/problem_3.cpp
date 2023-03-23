#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*-----Problem #3: Adjacency matrix with multiple Edges--------------------*/

// Each cell in the matrix graph[from][to] is a list of the cost
typedef vector<vector<vector<int>>> GRAPH;

void add_directed_multiple_edges(GRAPH &graph, int from, int to, int weight)
{
    graph[from][to].push_back(weight);
}

void print_adjaceny_multiple_edges(GRAPH &graph)
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

void Solve()
{
    /*
     * Space Complexity is :  O(V^2 + E)
     * Time complexity : O(1) to check edge (u, v)
     */

    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes, vvi(nodes));

    for (int e(0); e < edges; ++e)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        add_directed_multiple_edges(graph, from, to, weight);
    }
    print_adjaceny_multiple_edges(graph);

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