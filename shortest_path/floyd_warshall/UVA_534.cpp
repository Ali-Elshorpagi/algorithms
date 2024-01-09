#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
public:
    Solution() { Sukuna; }
    void compute_min_max(vvi &graph)
    {
        int _size(sz(graph));
        fr(k, 0, _size)
        {
            fr(from, 0, _size)
            {
                fr(to, 0, _size)
                {
                    auto &ref(graph[from][to]);
                    ref = min(ref, max(graph[from][k], graph[k][to]));
                }
            }
        }
    }
    int Solve(int tc)
    {
        int n;
        cin >> n;

        if (!n)
            return n;

        vvi graph(n, vi(n));
        vector<int> x(n), y(n);

        fr(i, 0, n) { cin >> x[i] >> y[i]; }

        fr(i, 0, n)
        {
            fr(j, 0, n)
            {
                int dx(x[i] - x[j]), dy(y[i] - y[j]);
                graph[i][j] = dx * dx + dy * dy;
            }
        }

        compute_min_max(graph);

        cout << "Scenario #" << tc << edl
             << "Frog Distance = " << fixed << setprecision(3) << sqrt(graph[0][1]) << edl << edl;
        return 1;
    }
};

int main()
{
    Solution sol;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(0);
    // cin >> tc;
    while (true)
        if (!sol.Solve(++tc))
            break;
    return (0);
}

/*
        !input:
                2
                0 0
                3 4
                3
                17 4
                19 4
                18 5
                0

*/