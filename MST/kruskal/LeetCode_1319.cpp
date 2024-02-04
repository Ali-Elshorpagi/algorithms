#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class UnionFind
{
    vi parent, rank;

    void link(int x, int y)
    {
        if (rank[x] > rank[y])
            swap(x, y);

        parent[x] = y;
        if (rank[x] == rank[y]) // equal ranks case
            ++rank[y];
    }

public:
    int forests{};
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

class Solution
{
    struct Edge
    {
        int from, to, weight = 0;
        Edge(int from, int to, int weight = 0) : from(from), to(to), weight(weight) {}
        bool operator<(const Edge &edge) const
        {
            return weight < edge.weight;
        }
    };

public:
    Solution() { __elshorpagi__; }
    int makeConnected(int n, vvi &connections)
    {
        if (sz(connections) < n - 1) // we must have n-1 edges for a tree
            return -1;

        vector<Edge> edgeList;
        fc(c, connections) { edgeList.push_back({c[0], c[1]}); }

        UnionFind uf(n);
        fc(edge, edgeList) { uf.union_sets(edge.from, edge.to); }

        return uf.forests - 1;
    }
    void TEST()
    {
        int n(4);
        vvi connections{{0, 1}, {0, 2}, {1, 2}};
        cout << makeConnected(n, connections) << edl; // 1
        n = 6, connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
        cout << makeConnected(n, connections) << edl; // 2
        connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
        cout << makeConnected(n, connections) << edl; // -1
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