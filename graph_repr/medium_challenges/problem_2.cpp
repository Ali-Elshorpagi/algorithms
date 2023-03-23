#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*-----Problem #2: Adjacency-based repr for flights v2--------*/

class Convertor
{
    map<string, int> str_to_id;
    map<int, string> id_to_str;

public:
    int get_id(string &str)
    {
        if (str_to_id.count(str))
            return str_to_id[str];
        // ids to strings will be : 0, 1, 2, 3, ...N-1
        int id(sz(str_to_id));
        str_to_id[str] = id;
        id_to_str[id] = str;
        return id;
    }
    string get_str(int id)
    {
        return id_to_str[id];
    }
};

struct Edge
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

void print_adjaceny_list(GRAPH &graph, Convertor &convert)
{
    int nodes(sz(graph));
    for (int from(0); from < nodes; ++from)
    {
        cout << "Node " << convert.get_str(from) << " has neighbors: " << edl;
        for (int edge(0); edge < sz(graph[from]); ++edge)
        {
            cout << "\t(to " << convert.get_str(graph[from][edge].to)
                 << " weight " << graph[from][edge].weight << ")" << edl;
        }
    }
}

void Solve()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);
    Convertor convert;
    for (int e(0); e < edges; ++e)
    {
        string from, to;
        int weight;
        cin >> from >> to >> weight;
        int from_idx(convert.get_id(from));
        int to_idx(convert.get_id(to));
        add_directed_edge_using_adjaceny_list(graph, from_idx, to_idx, weight);
    }
    print_adjaceny_list(graph, convert);
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