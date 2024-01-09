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
    void build_path(vi &prev, vi &path, int target)
    {
        int prv(prev[target]);
        if (prv == -1)
        {
            path.push_back(target);
            return;
        }
        build_path(prev, path, prv);
        path.push_back(target);
    }
    bool Bellman_Ford(vector<Edge> &edge_list, int n, int src, vi &sp, vi &prev)
    {
        sp = vi(n, OO);
        prev = vi(n, -1);
        sp[src] = 0;

        for (int it(0); it < n; ++it)
        {
            bool any_updates(false);
            for (auto &edge : edge_list)
            {
                if (sp[edge.to] > sp[edge.from] + edge.weight)
                {
                    sp[edge.to] = sp[edge.from] + edge.weight;
                    prev[edge.to] = edge.from;
                    any_updates = true;
                }
            }
            //? all nodes are expanded and also have their min sp
            if (!any_updates)
                break;

            if (it == n - 1) //! cycle
                return true;
        }
        return false;
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
        //! has a cycle
        // vector<Edge> edge_list{
        //     {0, 1, 1},
        //     {1, 2, 99},
        //     {2, 3, 5},
        //     {1, 4, 1},
        //     {4, 2, 3},
        //     {4, 5, 6},
        //     {5, 3, 7},
        //     {3, 1, -1000}};
        int src(0), n(6);
        vi prev, sp;

        bool has_negative_cycle(Bellman_Ford(edge_list, n, src, sp, prev));

        if (has_negative_cycle)
        {
            cout << "There\'s a Negative Cycle";
            return;
        }
        for (int i(0); i < sz(sp); ++i)
            cout << i << ' ' << sp[i] << edl;

        vi path;
        int target(3);
        build_path(prev, path, target);
        cout << edl << "Path from 0 to " << target << ':' << edl;
        for (auto &it : path)
            cout << it << ' ';
        cout << edl;
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