#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
        int to, weight;
        Edge(int to, int weight) : to(to), weight(weight) {}

        //* to make the priority queue sort from small to large
        bool operator<(const Edge &edge) const
        {
            return weight > edge.weight;
        }
    };

public:
    Solution() { Sukuna; }
    vi Dijkstra(const vector<vector<Edge>> &adjList, int n, int src) // O(E * log(V))
    {
        vi distance(n, OO), visitied(n, 0);
        distance[src] = 0;

        priority_queue<Edge> Pqueue; // small to large
        Pqueue.push(Edge(src, 0));

        while (!Pqueue.empty())
        {
            // Get node with the minimum distance
            Edge minEdge(Pqueue.top());
            int minIdx(minEdge.to);
            Pqueue.pop();

            // The same node might come several times
            if (visitied[minIdx])
                continue;

            // Relax with the outgoing edges of the min node
            fc(edge, adjList[minIdx])
            {
                int to(edge.to), weight(edge.weight);

                if (distance[to] > distance[minIdx] + weight)
                {
                    distance[to] = distance[minIdx] + weight;
                    Pqueue.push({to, distance[to]}); // Add new edges
                }
            }
            visitied[minIdx] = 1;
        }
        return distance;
    }
    int networkDelayTime(vvi &times, int n, int k)
    {
        vector<vector<Edge>> adjList(n);

        fr(i, 0, sz(times))
        {
            int from(times[i][0] - 1), to(times[i][1] - 1), cost(times[i][2]);
            adjList[from].push_back({to, cost});
        }

        vi sp = Dijkstra(adjList, n, k - 1);
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