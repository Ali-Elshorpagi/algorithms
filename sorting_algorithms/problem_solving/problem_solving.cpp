#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef vector<int> vi;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
public:
    int eliminateMaximum(vi &dist, vi &speed) // O(N * log(N)) time, O(N) space
    {
        // link : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
        // code : leetcode 1921
        int len(sz(dist));
        vector<double> arr(len);
        fr(i, 0, len)
            arr[i] = ceil((double)dist[i] / speed[i]);
        sort(all(arr));
        int cnt(0);
        fr(i, 0, len)
        {
            if (i >= arr[i]) // i here equal time
                break;
            ++cnt;
        }
        return cnt;
    }
};

int main()
{
    return (0);
}
