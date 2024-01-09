#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    const int OO = 1e9;

    struct Edge
    {
        int from, to, weight;
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    };

public:
    Solution() { Sukuna; }
    vi bellman_ford(vector<Edge> &edge_list, int n, int src)
    {
        vi dist(n, OO);
        dist[src] = 0;

        fr(e, 0, n - 1)
        {
            bool any_updates(false);
            for (auto &edge : edge_list)
            {
                if (dist[edge.to] > dist[edge.from] + edge.weight)
                {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                    any_updates = true;
                }
            }
            if (!any_updates)
                break;
        }
        return dist;
    }
    int networkDelayTime(vvi &times, int n, int k)
    {
        vector<Edge> edge_list;

        fc(time, times) { edge_list.push_back(Edge(time[0] - 1, time[1] - 1, time[2])); }

        vi sp = bellman_ford(edge_list, n, k - 1);

        int mx(*max_element(all(sp)));

        return mx >= OO ? -1 : mx;
    }
    void TEST()
    {
        vvi times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
        int n(4), k(2);
        cout << networkDelayTime(times, n, k) << edl; // 2
        times = {{1, 2, 1}}, n = 2, k = 1;
        cout << networkDelayTime(times, n, k) << edl; // 1
        times = {{1, 2, 1}}, n = 2, k = 2;
        cout << networkDelayTime(times, n, k) << edl; // -1
    }
};

int main()
{
    Solution sol;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;

    return (0);
}