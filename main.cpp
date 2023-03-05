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

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int mn = INT_MAX, sum = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (k && nums[i] < 0)
            k -= 1, nums[i] *= -1;
        sum += nums[i]; // sum updated array
        mn = min(mn, nums[i]);
    }
    if (k % 2) // Odd K: flip another number: the min
        sum -= 2 * mn;
    return sum;
}

void Solve()
{
    // vi arr{4, 2, 3};
    // int k(1); // 5
    // vi arr{3, -1, 0, 2};
    // int k(3); // 6
    vi arr{2, -3, -1, 5, -4};
    int k(2); // 13
    // vi arr{-2, 9, 9, 8, 4};
    // int k(5); // 32
    int sum(largestSumAfterKNegations(arr, k));
    cout << sum << edl;
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("test/input.txt", "r", stdin);
    freopen("test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return (0);
}