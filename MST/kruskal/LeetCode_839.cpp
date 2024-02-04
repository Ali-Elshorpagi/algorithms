#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

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
    bool is_similar(vs &strs, int i, int j)
    {
        int cnt(0);
        int len(sz(strs[i]));
        fr(k, 0, len)
        {
            if (strs[i][k] != strs[j][k])
                ++cnt;
            if (cnt > 2)
                return false;
        }
        return true;
    }
    int numSimilarGroups(vs &strs)
    {
        int n(unique(all(strs)) - strs.begin()); // ignore the identical words
        UnionFind uf(n);

        fr(i, 0, n)
        {
            fr(j, i + 1, n)
            {
                if (is_similar(strs, i, j))
                    uf.union_sets(i, j); // from, to
            }
        }

        return uf.forests;
    }
    void TEST()
    {
        vs strs{"tars", "rats", "arts", "star"};
        cout << numSimilarGroups(strs) << edl; // 2
        strs = {"omv", "ovm"};
        cout << numSimilarGroups(strs) << edl; // 1
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