#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Worst-Case Time    O(V^3)
 * Worst-Case Space   O(V^2)
 */

class Algorithm
{
    const int OO = 1e9;

public:
    ~Algorithm() { cout << edl << "DONE" << edl; }
    void print(vvi &graph)
    {
        int _size(sz(graph));
        for (int i(0); i < _size; ++i)
        {
            cout << '\t';
            for (int j(0); j < _size; ++j)
            {
                if (graph[i][j] == OO)
                    cout << "OO" << ' ';
                else
                    cout << graph[i][j] << ' ';
            }
            cout << edl;
        }
        cout << "********************************" << edl;
    }
    void print_path(vvi &path, int start, int end)
    {
        int k(path[start][end]);
        if (k == -1) // there's no intermediate node
        {
            cout << '\t' << start << ' ' << end << endl;
            return;
        }

        print_path(path, start, k);
        print_path(path, k, end);
    }
    void Floyd_Warshall(vvi &graph, vvi &path)
    {
        int _size(sz(graph));
        for (int k(0); k < _size; ++k)
        {
            for (int from(0); from < _size; ++from)
            {
                for (int to(0); to < _size; ++to)
                {
                    int relax(graph[from][k] + graph[k][to]);
                    if (relax < graph[from][to])
                        graph[from][to] = relax, path[from][to] = k; // from => k => to
                }
            }
            cout << "After relaxing with node No." << k << ':' << edl;
            print(graph);
        }
    }
    void TEST()
    {
        // vertices and edges
        int v, e;
        cin >> v >> e;
        vvi graph(v, vi(v, OO)); // Initialize all matrix to OO
        vvi path(v, vi(v, -1));

        for (int i(0); i < v; ++i) // loop on the diagonal
            graph[i][i] = 0;       // set self loop = 0

        for (int edge(0); edge < e; ++edge)
        {
            int from, to, weight; // 0-based
            cin >> from >> to >> weight;
            if (from != to) // ignore self loop
                graph[from][to] = min(graph[from][to], weight);
        }

        cout << edl << "Input Matrix:" << edl;
        print(graph);
        Floyd_Warshall(graph, path);

        int start(0), end(4); // case #2
        cout << edl << "Path from " << start << " to " << end << ':' << edl;
        print_path(path, start, end);
    }
};

int main()
{
    Algorithm algo;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    return (0);
}

/*
    !input:
        ?case #1:
                5 12
                0 1 5
                0 1 9
                0 3 2
                1 2 2
                1 1 7
                2 0 3
                2 4 7
                3 2 4
                3 4 1
                4 0 1
                4 1 8
                4 1 3

        ?case #2:
                5 5
                0 1 1
                1 2 2
                2 3 3
                3 4 4
                0 4 15
*/