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
    vi cur_partition_sum, numbers, visited;
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
    bool backtracking_(int idx) // O(K^N) time
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

            if (backtracking_(idx + 1))
                return true;

            // undo the state
            cur_partition_sum[partition] -= numbers[idx];
            partition_values[partition].pop_back();
        }
        return false;
    }
    bool backtracking__(int parition_idx, int number_idx, int cur_sum) // O(k * 2^N) time
    {
        if (parition_idx == k) // we can also use (partition_idx == k-1)
            return true;

        if (cur_sum == partition_sum)
            return backtracking__(parition_idx + 1, 0, 0);

        if (number_idx >= sz(numbers))
            return false;

        if (!visited[number_idx] && cur_sum + numbers[number_idx] <= partition_sum)
        {
            visited[number_idx] = 1;

            if (backtracking__(parition_idx, number_idx + 1, cur_sum + numbers[number_idx]))
                return true; // pick it

            visited[number_idx] = 0;
        }

        if (backtracking__(parition_idx, number_idx + 1, cur_sum))
            return true; // leave it for this partition

        return false;
    }
    bool canPartitionKSubsets_(vi &nums, int k_) // TLE
    {
        int sum(accumulate(all(nums), 0));
        if (sum % k_ != 0 || sz(nums) < k_)
            return false; // Impossible
        numbers = nums, k = k_, partition_sum = sum / k;
        cur_partition_sum = vi(k, 0), partition_values = vvi(k);
        return backtracking_(0);
    }
    bool canPartitionKSubsets__(vi &nums, int k_) // TLE
    {
        int sum(accumulate(all(nums), 0));
        if (sum % k_ != 0 || sz(nums) < k_)
            return false; // Impossible

        numbers = nums, k = k_, partition_sum = sum / k;
        cur_partition_sum = vi(k, 0), partition_values = vvi(k);
        visited = vi(sz(nums), 0);
        sort(all(numbers), greater<int>());
        return backtracking__(0, 0, 0);
    }
    bool backtracking(int current_sum, int parition_idx, int _k)
    {
        if (_k == 1)
            return true;

        if (current_sum == partition_sum)
            return backtracking(0, 0, _k - 1);

        fr(j, parition_idx, sz(numbers))
        {
            if (visited[j] || current_sum + numbers[j] > partition_sum)
                continue;

            visited[j] = 1; // update the state

            if (backtracking(current_sum + numbers[j], j + 1, _k))
                return true;

            visited[j] = 0; // undo the state

            // optimization
            if (!current_sum)
                break;
        }
        return false;
    }
    bool canPartitionKSubsets(vi &nums, int k_) // ACC
    {
        int sum(accumulate(all(nums), 0));
        if (sum % k_ != 0 || sz(nums) < k_)
            return false; // Impossible

        numbers = nums, k = k_, partition_sum = sum / k;
        visited = vi(sz(nums), 0);
        sort(all(numbers), greater<int>());
        return backtracking(0, 0, k);
    }
    void TEST()
    {
        vi nums{4, 3, 2, 3, 5, 2, 1};
        int _k(4);
        canPartitionKSubsets(nums, _k) ? yes : no; // YES
        // if (canPartitionKSubsets__(nums, _k)) // YES
        //     yes, print_partitions(partition_values);
        // else
        //     no;
        nums = {1, 2, 3, 4}, _k = 3;
        canPartitionKSubsets(nums, _k) ? yes : no; // NO

        // if (canPartitionKSubsets__(nums, _k)) // NO
        //     yes, print_partitions(partition_values);
        // else
        //     no, cout << edl << "There are no partitions .." << edl;
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