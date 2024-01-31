#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
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

        //* to make the priority queue sort from small to large
        bool operator<(const Edge &edge) const
        {
            return weight > edge.weight;
        }
    };

public:
    Solution() { __elshorpagi__; }
    vi Dijkstra(const vector<vector<Edge>> &adjList, int n, int src, vi &prev) // O(E * log(V))
    {
        vi distance(n, OO);
        distance[src] = 0;
        prev = vi(n, -1);
        priority_queue<Edge> Pqueue; // small to large
        Pqueue.push(Edge(-1, src, 0));

        while (!Pqueue.empty())
        {
            // Get node with the minimum distance
            Edge minEdge(Pqueue.top());
            int minIdx(minEdge.to);
            Pqueue.pop();

            // This edge can't make more relaxations
            if (minEdge.weight > distance[minIdx])
                continue;

            prev[minEdge.to] = minEdge.from;
            // Relax with the outgoing edges of the min node
            fc(edge, adjList[minIdx])
            {
                int from(edge.from), to(edge.to), weight(edge.weight);

                if (distance[to] > distance[minIdx] + weight)
                {
                    distance[to] = distance[minIdx] + weight;
                    Pqueue.push({from, to, distance[to]}); // Add new edges
                }
            }
        }
        return distance;
    }
    vi buildPath(const vi &prev, int target)
    {
        vi path;
        // start from last node and move toward the source
        for (int i(target); i > -1 && sz(path) <= sz(prev); i = prev[i])
            path.push_back(i);

        reverse(all(path)); // now path is reversed [target to src]. reverse it
        return path;
    }
    int networkDelayTime(vvi &times, int n, int k)
    {
        vector<vector<Edge>> adjList(n);

        fr(i, 0, sz(times))
        {
            int from(times[i][0] - 1), to(times[i][1] - 1), cost(times[i][2]);
            adjList[from].push_back({from, to, cost});
        }

        vi prev;
        vi sp = Dijkstra(adjList, n, k - 1, prev);
        int mx(*max_element(all(sp)));

        return mx >= OO ? -1 : mx;
    }

    void TEST()
    {
        vvi times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
        int n(4), k(2);
        cout << edl << edl << "Network Delay Time Testing:" << edl << networkDelayTime(times, n, k) << edl; // 2
        times = {{1, 2, 1}}, n = 2, k = 1;
        cout << networkDelayTime(times, n, k) << edl; // 1
        times = {{1, 2, 1}}, n = 2, k = 2;
        cout << networkDelayTime(times, n, k) << edl; // -1
    }
    int ReadGraph(vector<vector<Edge>> &adjList)
    {
        int v, e; // nodes and edges;
        cin >> v >> e;
        adjList = vector<vector<Edge>>(v);

        fr(i, 0, e)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            adjList[from].push_back({from, to, weight});
        }
        return v;
    }
    void TestGraph()
    {
        vector<vector<Edge>> adjList;
        int n(ReadGraph(adjList)), src(1);

        vi prev;
        vi sp = Dijkstra(adjList, n, src, prev);

        cout << edl << edl << "Shortest Path from - to " << edl;
        fr(i, 0, sz(sp)) { cout << i << ' ' << sp[i] << edl; }

        int target(5);
        vi path = buildPath(prev, target);
        cout << edl << edl << "Path from " << src << " to " << target << edl;
        fc(v, path) { cout << v << ' '; } // 1 3 6 5

        /*
            !input
            7 12
            0 1 2
            0 3 1
            1 4 10
            1 3 3
            2 0 4
            2 5 5
            3 4 2
            3 6 4
            3 2 2
            3 5 8
            4 6 6
            6 5 1
         */
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
        cout << "Case #" << tc + 1 << edl, sol.TestGraph(), sol.TEST();
    cout << edl << "DONE" << edl;

    return (0);
}