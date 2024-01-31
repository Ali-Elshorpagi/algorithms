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
    pair<int, bool> MST(const vector<vector<Edge>> &adjList, int n, vector<Edge> &edges, int src = 0) // O(E * log(V))
    {
        vi distance(n, OO), visited(n, 0);
        distance[src] = 0;
        int mstCost(0);

        priority_queue<Edge> Pqueue;   // small to large
        Pqueue.push(Edge(-1, src, 0)); // dummy

        while (!Pqueue.empty())
        {
            // Get node with the minimum distance
            Edge minEdge(Pqueue.top());
            int minIdx(minEdge.to);
            Pqueue.pop();

            if (visited[minIdx]) // visited
                continue;

            mstCost += minEdge.weight;
            if (minEdge.from != -1)
                edges.push_back(minEdge);

            fc(edge, adjList[minIdx]) // relax
            {
                int to(edge.to), weight(edge.weight);

                if (distance[to] > weight)
                {
                    distance[to] = weight;
                    Pqueue.push({minIdx, to, distance[to]});
                }
            }
            visited[minIdx] = 1;
        }

        if (sz(edges) == n - 1) // tree
            return {mstCost, true};
        return {0, false};
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
            adjList[from].push_back({from, to, weight});
            adjList[to].push_back({to, from, weight});
        }
        return V;
    }
    void TEST()
    {
        vector<vector<Edge>> adjList;
        int n(ReadGraph(adjList));

        vector<Edge> edges;
        pair<int, bool> ans = MST(adjList, n, edges);

        if (ans.second)
        {
            cout << ans.first << edl;
            fc(edge, edges) { cout << edge.from << ' ' << edge.to << ' ' << edge.weight << edl; }
        }
        else
            cout << "No MST" << edl;
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

            !output
            14
            0 1 2
            1 2 4
            2 5 3
            2 3 4
            3 4 1
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
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;

    return (0);
}