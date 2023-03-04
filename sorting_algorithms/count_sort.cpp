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

/*
 * # Complexities
 *
 * Best-Case Time      O(N)
 * Worst-Case Time     O(N + K), where K is the size of frequency array
 * Worst-Case Space    O(K)
 */

void count_sort_0(vi &arr)
{
    int len(sz(arr)), idx(0);
    int max_val(*max_element(all(arr))); // O(N)

    vi freq(max_val + 1);
    for (auto &it : arr)
        ++freq[it];

    for (int i(0); i <= max_val; ++i)
        if (freq[i])
            fr(j, 0, freq[i]) arr[idx++] = i;
}

void count_sort_1(vi &arr) // work with negative numbers, but with min trick
{
    int mn(*min_element(all(arr))), idx(0);
    vi freq(50001 - mn); // -50000 <= arr[i] <= 50000
    fc(it, arr)++ freq[it - mn];
    fr(i, 0, 50001 - mn)
    {
        if (freq[i])
            fr(j, 0, freq[i]) arr[idx++] = i + mn;
    }
}

vi count_sort_2(vi &nums) // work with negative numbers, but with max trick
{
    int mx(*max_element(all(nums))), idx(0);
    vi freq(50001 + mx); // -50000 <= arr[i] <= 50000;
    fc(it, nums)++ freq[it + 50000];
    fr(i, 0, 50001 + mx)
    {
        if (freq[i])
            fr(j, 0, freq[i]) nums[idx++] = i - 50000;
    }
    return nums;
}

void Solve()
{
    vi arr{5, -2, -3, 1};
    count_sort_1(arr);
    fc(it, arr) cout << it << ' ';
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
    return (0);
}