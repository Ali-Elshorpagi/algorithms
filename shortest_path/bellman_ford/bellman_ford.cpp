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
 * Worst-Case Time    O(V * E)
 * Worst-Case Space   O(V)
 */

class Algorithm
{
    const int OO = 1e9;

    struct Edge
    {
        int from, to, weight;
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    };

public:
    ~Algorithm() { cout << edl << "DONE" << edl; }
    vi Bellman_Ford(vector<Edge> &edge_list, int n, int src)
    {
        vi dist(n, OO);
        dist[src] = 0;

        for (int i(0); i < n - 1; ++i)
        {
            // 2 inner loops just iterate on edges relax all to nodes
            for (int j(0); j < sz(edge_list); ++j)
            {
                Edge &ne(edge_list[j]); // neighbour
                if (dist[ne.to] > dist[ne.from] + ne.weight)
                    dist[ne.to] = dist[ne.from] + ne.weight;
            }
        }
        return dist;
    }
    void TEST()
    {
        vector<Edge> edge_list{
            {0, 1, 1},
            {1, 2, 99},
            {2, 3, 5},
            {1, 4, 1},
            {4, 2, 3},
            {4, 5, 6},
            {5, 3, 7}};
        int src(0), dist(6);
        vector<int> shortest_path = Bellman_Ford(edge_list, dist, src);

        for (int i(0); i < sz(shortest_path); ++i)
            cout << i << ' ' << shortest_path[i] << edl;
    }
};

int main()
{
    Algorithm algo;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    return (0);
}