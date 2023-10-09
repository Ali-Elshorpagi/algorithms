#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
public:
    Solution() { Sukuna; }
    int lengthOfLIS(vi &nums)
    {
        vi seq;
        seq.push_back(nums[0]);
        fr(i, 1, sz(nums))
        {
            if (seq.back() < nums[i])
                seq.push_back(nums[i]);
            else
            {
                int idx(lower_bound(all(seq), nums[i]) - seq.begin());
                seq[idx] = nums[i];
            }
        }
        return sz(seq);
    }
    void TEST()
    {
        vi nums{10, 9, 2, 5, 3, 7, 101, 18};
        cout << lengthOfLIS(nums) << edl; // 4
        nums = {0, 1, 0, 3, 2, 3};
        cout << lengthOfLIS(nums) << edl; // 4
        nums = {7, 7, 7, 7, 7, 7, 7};
        cout << lengthOfLIS(nums) << edl; // 1
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