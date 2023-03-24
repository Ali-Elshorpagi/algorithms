#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

void print_adjaceny_matrix_0(vvi &graph, int rows, int cols)
{
    for (int r(0); r < rows; ++r)
    {
        for (int c(0); c < cols; ++c)
        {
            if (!r && !c)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r][c + 1] << ' ' << graph[r + 1][c] << edl;
            else if (!r & c < cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r][c + 1] << ' ' << graph[r + 1][c] << ' '
                     << graph[r][c - 1] << edl;
            else if (!r && c == cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r + 1][c] << ' ' << graph[r][c - 1] << edl;
            else if (r < rows - 1 && !c)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r - 1][c] << ' ' << graph[r][c + 1] << ' ' << graph[r + 1][c] << edl;
            else if (!c && r == rows - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r][c + 1] << ' ' << graph[r - 1][c] << edl;
            else if (r == rows - 1 && c < cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r][c - 1] << ' ' << graph[r][c + 1] << ' ' << graph[r - 1][c] << edl;
            else if (r < rows - 1 && c < cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r][c + 1] << ' ' << graph[r + 1][c] << ' '
                     << graph[r][c - 1] << ' ' << graph[r - 1][c] << edl;
            else if (r == rows - 1 && c == cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << graph[r][c - 1] << ' ' << graph[r - 1][c] << edl;
        }
    }
}

void print_adjaceny_matrix_1(int rows, int cols)
{
    for (int r(0); r < rows; ++r)
    {
        for (int c(0); c < cols; ++c)
        {
            if (!r && !c)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << ((r * cols) + (c + 1)) << ' ' << (((r + 1) * cols) + c) << edl;
            else if (!r & c < cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << ((r * cols) + (c + 1)) << ' ' << (((r + 1) * cols) + c) << ' '
                     << ((r * cols) + (c - 1)) << edl;
            else if (!r && c == cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << (((r + 1) * cols) + c) << ' ' << ((r * cols) + (c - 1)) << edl;
            else if (r < rows - 1 && !c)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << (((r - 1) * cols) + c) << ' ' << ((r * cols) + (c + 1)) << ' ' << (((r + 1) * cols) + c) << edl;
            else if (!c && r == rows - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << ((r * cols) + (c + 1)) << ' ' << (((r - 1) * cols) + c) << edl;
            else if (r == rows - 1 && c < cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << ((r * cols) + (c - 1)) << ' ' << ((r * cols) + (c + 1)) << ' ' << (((r - 1) * cols) + c) << edl;
            else if (r < rows - 1 && c < cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << ((r * cols) + (c + 1)) << ' ' << (((r + 1) * cols) + c) << ' '
                     << ((r * cols) + (c - 1)) << ' ' << (((r - 1) * cols) + c) << edl;
            else if (r == rows - 1 && c == cols - 1)
                cout << "Node " << ((r * cols) + c) << " has neighbors: "
                     << ((r * cols) + (c - 1)) << ' ' << (((r - 1) * cols) + c) << edl;
        }
    }
}

void Solve()
{
    // to convert from matrix to array use this equation : ((i * cols) + j);
    int rows, cols;
    cin >> rows >> cols;
    vvi graph(rows, vi(cols));

    for (int r(0); r < rows; ++r)
    {
        for (int c(0); c < cols; ++c)
        {
            graph[r][c] = ((r * cols) + c);
        }
    }

    print_adjaceny_matrix_0(graph, rows, cols);
    print_adjaceny_matrix_1(rows, cols);

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