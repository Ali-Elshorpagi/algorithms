#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Best-Case Time     O(1)
 * Worst-Case Time    O(log N)
 * Worst-Case Space   O(1), but in recursive implementation will be O(log N)
 */

class Algorithm
{
public:
    int Binary_Search(vi &arr, int value)
    {
        int left(0), right(sz(arr) - 1);
        while (left <= right)
        {
            // we can use ==> mid = left + (right - left + 1) / 2; it's depends on problem
            int mid(left + ((right - left) >> 1));
            if (arr[mid] == value)
                return mid;
            else if (arr[mid] > value)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    int Binary_Search_Recursive(vi &arr, int left, int right, int value)
    {
        if (right >= left)
        {
            int mid(left + ((right - left) >> 1));
            if (arr[mid] == value)
                return mid;
            if (arr[mid] > value)
                return Binary_Search_Recursive(arr, left, mid - 1, value);
            return Binary_Search_Recursive(arr, mid + 1, right, value);
        }
        return -1;
    }

    /*---------------- Binary Search on Real Numbers ----------------*/
    // the problem :
    // Assume we have a function : f(X) = 4X^7 + 3X^5 - 1000;
    // Find the value of X such that f(X) = 0;
    // It is guaranteed there is a solution for X in the range [0, 3];

    double possible(double x) // this function can be changed depending on the problem;
    {
        return 4 * pow(x, 7) + 3 * pow(x, 5) - 1000;
    }

    // The EPS value can be changed depending on the problem;
    double Binary_Search_Real_Numbers_0(double EPS = 1e-9)
    {
        double left(0), right(3); // the range that was given in the problem or u deduced it;
        while (right - left > EPS)
        {
            double mid(left + (right - left) / 2);
            if (possible(mid) < 0.0)
                left = mid;
            else
                right = mid;
        }
        return left;
    }

    double Binary_Search_Real_Numbers_1(double EPS = 1e-9)
    {
        double left(EPS), right(3);
        // while (fabs(right - left) > EPS) // 2nd way
        for (int iter(0); iter < 100; ++iter) // 3rd way
        {
            double mid(sqrt(left * right));
            if (possible(mid) < 0.0)
                left = mid;
            else
                right = mid;
        }
        return (left + right) / 2.0;
    }
    void TEST()
    {
        int n, target;
        cin >> n >> target;
        vi arr(n);
        for (auto &it : arr)
            cin >> it;
        cout << Binary_Search(arr, target) << edl;
        cout << Binary_Search_Recursive(arr, 0, n - 1, target) << edl;
    }
};

int main()
{
    Algorithm algo;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    cout << edl << "DONE" << edl;

    return (0);
}