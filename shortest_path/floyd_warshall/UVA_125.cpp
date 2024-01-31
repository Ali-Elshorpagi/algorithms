#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{

public:
    Solution() { __elshorpagi__; }
    void count_paths(vvi &graph)
    {
        int _size(sz(graph));
        fr(k, 0, _size)
        {
            fr(from, 0, _size)
            {
                fr(to, 0, _size)
                {
                    //? combination of paths
                    graph[from][to] += graph[from][k] * graph[k][to];
                }
            }
        }

        //! detect cycles
        fr(k, 0, _size)
        {
            if (graph[k][k]) //! cycle
            {
                fr(from, 0, _size)
                {
                    fr(to, 0, _size)
                    {
                        //? if the node K is in a cycle
                        //? and this path is exist : from -> K -> to
                        //? so this path can relax in a cycle
                        if (graph[from][k] && graph[k][to])
                            graph[from][to] = -1;
                    }
                }
            }
        }
    }
    void Solve()
    {
        int m, n, x, y, tc(0);
        int cnt[31][31] = {};

        while (scanf("%d", &m) == 1)
        {
            memset(cnt, 0, sizeof(cnt));

            n = 0;
            while (m--)
            {
                scanf("%d %d", &x, &y);
                ++cnt[x][y];
                if (x > n)
                    n = x;
                if (y > n)
                    n = y;
            }
            ++n;

            vvi graph(n, vi(n));

            fr(i, 0, n)
            {
                fr(j, 0, n)
                {
                    graph[i][j] = cnt[i][j];
                }
            }

            count_paths(graph);

            printf("matrix for city %d\n", tc++);
            fr(i, 0, n)
            {
                fr(j, 0, n)
                {
                    if (j)
                        putchar(' ');
                    printf("%d", graph[i][j]);
                }
                puts("");
            }
        }
    }
};

int main()
{
    Solution sol;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        sol.Solve();
    return (0);
}

/*
        !input:
                7 0 1 0 2 0 4 2 4 2 3 3 1 4 3
                5
                0 2
                0 1 1 5 2 5 2 1
                9
                0 1 0 2 0 3
                0 4 1 4 2 1
                2 0
                3 0
                3 1
*/