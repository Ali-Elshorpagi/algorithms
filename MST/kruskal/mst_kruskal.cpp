#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define edl '\n'

class UnionFind
{
    vi parent, rank;
    int forests;

    void link(int x, int y)
    {
        if (rank[x] > rank[y])
            swap(x, y);

        parent[x] = y;
        if (rank[x] == rank[y]) // equal ranks case
            ++rank[y];
    }

public:
    UnionFind(int n)
    {
        // each node is a connected component
        parent = vi(n), rank = vi(n);

        forests = n;
        for (int i(0); i < n; ++i)
            // better than -1, for the find_set_recursive()
            parent[i] = i, rank[i] = 1;
    }

    int find_set_recursive(int x)
    {
        if (x == parent[x]) // reached the top parent
            return x;
        return parent[x] = find_set_recursive(parent[x]);
    }

    int find_set_iterative(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }

    bool union_sets(int x, int y)
    {
        x = find_set_iterative(x), y = find_set_iterative(y);

        if (x != y)
            link(x, y), --forests;

        return x != y; // Are they in different CCs?
    }
};

class Algorithm
{
    struct Edge
    {
        int from, to, weight;
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
        bool operator<(const Edge &edge) const
        {
            return weight < edge.weight;
        }
    };

public:
    Algorithm() { __elshorpagi__; }
    int MST_Kruskal(vector<Edge> &edgeList, int n) // O(E * log(V))
    {
        UnionFind uf(n);
        vector<Edge> edges; // Save MST edges
        int mstCost(0);

        // u can use priority_queue to sort and pop edges, but this is more easier
        sort(all(edgeList));

        for (auto &edge : edgeList)
        {
            if (uf.union_sets(edge.from, edge.to))
            {
                // If added, then part of tree
                mstCost += edge.weight;
                edges.push_back(edge);
            }
        }
        // if size of edges != n-1, then no full MST
        return mstCost;
    }
    void TEST()
    {
        int V, E; // nodes and edges;
        cin >> V >> E;
        vector<Edge> edgeList;
        for (int i(0); i < E; ++i)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            // one direction is enough for Kruskal, cuz we look at the connectivity
            edgeList.push_back({from, to, weight});
        }
        cout << edl << MST_Kruskal(edgeList, V) << edl; // 14

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
        */
    }
};

int main()
{
    Algorithm algo;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    cout << edl << "DONE" << edl;

    return (0);
}