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

int findUnsortedSubarray_0(vi &nums) // O(N * log(N)) time, O(N) space
{
    int x(0), y(0), len(sz(nums));
    vi arr = nums;
    sort(all(arr));
    if (arr == nums)
        return 0;
    fr(i, 0, len)
    {
        if (nums[i] != arr[i])
        {
            x = i;
            break;
        }
    }
    fl(j, len - 1, -1)
    {
        if (nums[j] != arr[j])
        {
            y = j;
            break;
        }
    }
    return (y - x) + 1;
}

//(int nums[])
int findUnsortedSubarray_1(vi &nums) // O(N) time, O(1) space
{
    // nums{1, 2, 3, 4};
    int flag1(0), flag2(0), left(0), right(sz(nums) - 1), len(sz(nums));
    // int flag1(0), flag2(0), left(0), right(4), len(5);
    while (left != right && (!flag1 || !flag2))
    {
        if (nums[left] <= nums[left + 1] && !flag1)
            ++left;
        else
            flag1 = 1;

        if (nums[right] > nums[right - 1] && !flag2)
            --right;
        else
            flag2 = 1;
        if (left >= right)
            break;
    }
    return (flag1 && flag2 ? (right - left) + 1 : 0);
}

void Solve()
{
    // vi arr{2, 6, 4, 8, 10, 9, 15}; // 5
    // vi arr{1, 2, 3, 4}; // 0
    vi arr{1, 3, 2, 4, 5}; // 2
    // vi arr{1, 3, 2, 2, 2}; // 4
    int ans(findUnsortedSubarray_1(arr));
    cout << ans << edl;
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