#include <iostream>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

// As the graph is sparce, we better use adjaceny list (or set)
typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].emplace_back(to);
}

void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes(sz(graph));
    for (int from(0); from < nodes; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int to(0); to < sz(graph[from]); ++to)
            cout << graph[from][to] << ' ';
        cout << edl;
    }
}

// true if this location inside the matrix
bool is_valid(int new_row, int new_col, int rows, int cols)
{
    if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols)
        return false;
    return true;
}

void Solve()
{
    int rows, cols;
    cin >> rows >> cols;

    GRAPH graph(rows * cols); // observe: empty lists

    int new_row, new_col, to;
    for (int r(0); r < rows; ++r)
    {
        for (int c(0); c < cols; ++c)
        {
            int from((r * cols) + c);

            // check every location if it's valid or not;
            new_row = r + 1, new_col = c, to = new_row * cols + new_col;
            if (is_valid(new_row, new_col, rows, cols))
                add_directed_edge(graph, from, to);

            new_row = r - 1, new_col = c, to = new_row * cols + new_col;
            if (is_valid(new_row, new_col, rows, cols))
                add_directed_edge(graph, from, to);

            new_row = r, new_col = c + 1, to = new_row * cols + new_col;
            if (is_valid(new_row, new_col, rows, cols))
                add_directed_edge(graph, from, to);

            new_row = r, new_col = c - 1, to = new_row * cols + new_col;
            if (is_valid(new_row, new_col, rows, cols))
                add_directed_edge(graph, from, to);
        }
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