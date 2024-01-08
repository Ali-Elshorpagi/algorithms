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
    const int OO = (int)1e6;

public:
    ~Algorithm() { cout << edl << "DONE" << edl; }
    void print(vvi &adjacent_matrix)
    {
        int _size(sz(adjacent_matrix));
        for (int i(0); i < _size; ++i)
        {
            cout << '\t';
            for (int j(0); j < _size; ++j)
            {
                if (adjacent_matrix[i][j] >= OO)
                    cout << "OO" << ' ';
                else
                    cout << adjacent_matrix[i][j] << ' ';
            }
            cout << edl;
        }
        cout << "********************************" << edl;
    }
    void floyd_warshall(vvi &adjacent_matrix)
    {
        int _size(sz(adjacent_matrix));
        for (int k(0); k < _size; ++k)
        {
            for (int i(0); i < _size; ++i)
            {
                for (int j(0); j < _size; ++j)
                {
                    int relax(adjacent_matrix[i][k] + adjacent_matrix[k][j]);
                    adjacent_matrix[i][j] = min(adjacent_matrix[i][j], relax);
                }
            }
            cout << "After relaxing with node no." << k << ':' << edl;
            print(adjacent_matrix);
        }
    }
    void TEST()
    {
        // vertices and edges
        int v, e;
        cin >> v >> e;
        vvi adjacent_matrix(v, vi(v, OO)); // Initialize all matrix to OO

        for (int i(0); i < v; ++i)     // loop on the diagonal
            adjacent_matrix[i][i] = 0; // set self loop = 0

        for (int i(0); i < e; ++i)
        {
            int from, to, weight; // 0-based
            cin >> from >> to >> weight;
            if (from == to) // self loop
                continue;
            adjacent_matrix[from][to] = min(adjacent_matrix[from][to], weight);
        }

        cout << edl << "Input Matrix:" << edl;
        print(adjacent_matrix);
        floyd_warshall(adjacent_matrix);
    }
};

int main()
{
    Algorithm algo;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    return (0);
}

/*
    input:
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
*/