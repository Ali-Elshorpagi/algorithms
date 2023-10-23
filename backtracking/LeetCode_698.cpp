#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // accumulate

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
    int k, partition_sum;
    // part of the backtrack state
    vi cur_partition_sum, numbers;
    // For printing purposes
    vvi partition_values;

public:
    Solution() { Sukuna; }
    void print_partitions(vvi &partitions)
    {
        int cnt(1);
        fc(it, partitions)
        {
            cout << "Partition Number " << cnt << edl;
            fc(jt, it) { cout << jt << ' '; }
            cout << edl, ++cnt;
        }
    }
    bool backtracking(int idx) // O(K^N) time
    {
        // if all values are added, then we must have a solution
        if (idx >= sz(numbers))
            return true;
        // BF: try all possible partitions to put this number
        fr(partition, 0, k)
        {
            if (cur_partition_sum[partition] + numbers[idx] > partition_sum)
                continue;

            // update the state
            cur_partition_sum[partition] += numbers[idx];
            partition_values[partition].push_back(numbers[idx]);

            if (backtracking(idx + 1))
                return true;

            // undo the state
            cur_partition_sum[partition] -= numbers[idx];
            partition_values[partition].pop_back();
        }
        return false;
    }
    bool canPartitionKSubsets(vi &nums, int k_) // TLE
    {
        int sum(accumulate(all(nums), 0));
        if (sum % k_ != 0 || sz(nums) < k_)
            return false; // Impossible
        numbers = nums, k = k_, partition_sum = sum / k;
        cur_partition_sum = vi(k, 0), partition_values = vvi(k);
        return backtracking(0);
    }
    void TEST()
    {
        vi nums{4, 3, 2, 3, 5, 2, 1};
        int _k(4);
        if (canPartitionKSubsets(nums, _k)) // YES
            yes, print_partitions(partition_values);
        else
            no;
        nums = {1, 2, 3, 4}, _k = 3;
        if (canPartitionKSubsets(nums, _k)) // NO
            yes, print_partitions(partition_values);
        else
            no, cout << edl << "There are no partitions .." << edl;
    }
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}