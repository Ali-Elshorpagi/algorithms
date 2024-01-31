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
    const int OO = 1e9 * 2;

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
    Solution() { __elshorpagi__; }
    int MST(const vector<vector<Edge>> &adjList, int n, int src = 0) // O(E * log(V))
    {
        vi distance(n, OO), visited(n, 0);
        distance[src] = 0;
        int mstCost(0);

        priority_queue<Edge> Pqueue; // small to large
        Pqueue.push(Edge(src, 0));

        while (!Pqueue.empty())
        {
            // Get node with the minimum distance
            Edge minEdge(Pqueue.top());
            int minIdx(minEdge.to);
            Pqueue.pop();

            if (visited[minIdx]) // visited
                continue;

            mstCost += minEdge.weight;

            fc(edge, adjList[minIdx]) // relax
            {
                int to(edge.to), weight(edge.weight);

                if (distance[to] > weight)
                {
                    distance[to] = weight;
                    Pqueue.push({to, distance[to]});
                }
            }
            visited[minIdx] = 1;
        }
        return mstCost;
    }
    int minCostConnectPoints(vvi &points)
    {
        int n(sz(points));
        vector<vector<Edge>> adjList(n);

        fr(i, 0, n)
        {
            fr(j, i, n)
            {
                int cost(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                adjList[i].push_back({j, cost});
                adjList[j].push_back({i, cost});
            }
        }

        int mstCost(MST(adjList, n));
        return mstCost;
    }
    int ReadGraph(vector<vector<Edge>> &adjList)
    {
        int V, E; // nodes and edges;
        cin >> V >> E;

        adjList = vector<vector<Edge>>(V);

        fr(i, 0, E)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            adjList[from].push_back({to, weight});
            adjList[to].push_back({from, weight});
        }
        return V;
    }
    void TEST()
    {
        vvi points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
        cout << edl << edl << "Min Cost Connect Points Testing:" << edl << minCostConnectPoints(points) << edl; // 20
        points = {{3, 12}, {-2, 5}, {-4, 1}};
        cout << minCostConnectPoints(points) << edl; // 18
    }
    void TestGraph()
    {
        vector<vector<Edge>> adjList;
        int n(ReadGraph(adjList));

        int mstCost(MST(adjList, n));

        cout << mstCost << edl; // 14

        /*
            !input
            6 7
            0 5 6
            0 1 2
            1 2 4
            2 3 4
            2 5 3
            3 4 1
            5 4 4
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