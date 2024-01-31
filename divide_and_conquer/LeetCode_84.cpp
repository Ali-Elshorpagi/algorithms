#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{

public:
    Solution() { __elshorpagi__; }
    int max_mid_area(vi &heights, int start, int end, int mid)
    {
        int i(mid), j(mid + 1);
        int max_area(0), height(min(heights[i], heights[j]));
        while (i >= start && j <= end)
        {
            height = min({height, heights[i], heights[j]});
            int width(j - i + 1),
                current_area(width * height);
            max_area = max(max_area, current_area);
            if (i == start)
                ++j;
            else if (j == end)
                --i;
            else
            {
                if (heights[i - 1] > heights[j + 1])
                    --i;
                else
                    ++j;
            }
        }
        return max_area;
    }
    int max_area(vi &heights, int start, int end)
    {
        if (start == end)
            return heights[start];
        int mid(start + ((end - start) >> 1));
        // max area from left half
        int area(max_area(heights, start, mid));
        // max area from right half
        area = max(area, max_area(heights, mid + 1, end));
        // max area across the middle
        area = max(area, max_mid_area(heights, start, end, mid));
        return area;
    }
    int largestRectangleArea(vi &heights)
    {
        if (!sz(heights))
            return 0;
        return max_area(heights, 0, sz(heights) - 1);
    }
    void TEST()
    {
        vi heights{2, 1, 5, 6, 2, 3};
        cout << largestRectangleArea(heights) << edl; // 10
        heights = {2, 4};
        cout << largestRectangleArea(heights) << edl; // 4
        heights = {9, 0};
        cout << largestRectangleArea(heights) << edl; // 9
        heights = {6, 6};
        cout << largestRectangleArea(heights) << edl; // 12
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