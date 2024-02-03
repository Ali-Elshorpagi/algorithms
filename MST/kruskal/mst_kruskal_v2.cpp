#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

class UnionFind
{
    vi parent, cc_size;
    int forests;

    void link(int x, int y)
    {
        if (cc_size[x] > cc_size[y])
            swap(x, y);

        parent[x] = y;
        cc_size[y] += cc_size[x]; // add child's size to its parent
    }

public:
    UnionFind(int n)
    {
        parent = vi(n), cc_size = vi(n);

        forests = n;
        for (int i(0); i < n; ++i)
            parent[i] = i, cc_size[i] = 1; // each node is a CC by itself
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

    vvi connected_components()
    {
        int n(sz(parent) - 1);
        vvi list(n);
        for (int node(0); node <= n; ++node)
        {
            int parent_(find_set_iterative(node));
            list[parent_].push_back(node);
        }

        // copy non-empty CCs
        vvi actual_cc;
        for (auto &cc : list)
            if (sz(cc))
                actual_cc.push_back(cc);

        return actual_cc;
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
        UnionFind uf(6);
        uf.union_sets(0, 1);
        uf.union_sets(2, 3);
        uf.union_sets(4, 5);
        uf.union_sets(4, 3);
        uf.union_sets(1, 2);

        vvi ans = uf.connected_components();
        cout << edl;
        for (auto &cc : ans)
        {
            for (auto &node : cc)
                cout << node << ' '; // 0 1 2 3 4 5
            cout << edl;
        }
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
    cout << edl << "DONE" << edl;

    return (0);
}