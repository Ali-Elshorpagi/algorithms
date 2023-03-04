#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<char> vc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes printf("YES\n")
#define no printf("NO\n")

vvi minimumAbsDifference(vi &arr) // O(N * log(N))
{
    // link : https://leetcode.com/problems/minimum-absolute-difference/
    // code : leetcode 1200
    sort(all(arr));
    int abs_diff(arr[1] - arr[0]), len(sz(arr));
    fr(i, 1, len)
    {
        if (arr[i] - arr[i - 1] < abs_diff)
            abs_diff = arr[i] - arr[i - 1];
    }
    vvi ans;
    fr(i, 0, len - 1)
    {
        if (arr[i + 1] - arr[i] == abs_diff)
            ans.push_back({arr[i], arr[i + 1]});
    }
    return ans;
}

void Solve()
{
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return 0;
}