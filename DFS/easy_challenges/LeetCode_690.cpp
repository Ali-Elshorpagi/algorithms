#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

typedef vector<int> vi;

struct Employee
{
    int id, importance;
    vi subordinates;
    Employee(int d, int imp, vi sub) : id(d), importance(imp), subordinates(sub) {}
};

// link : https://leetcode.com/problems/employee-importance/
// code : leetcode 690

class Solution // O(N) time, O(N) space
{
    unordered_map<int, Employee *> emps;

public:
    Solution() { Mesh_Ali; }
    void dfs(unordered_map<int, Employee *> &emps, int id, int &sum)
    {
        sum += emps[id]->importance;
        fc(it, emps[id]->subordinates) dfs(emps, it, sum);
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        fc(it, employees) emps[it->id] = it;
        int sum(0);
        dfs(emps, id, sum);
        return sum;
    }
    void TEST() {}
};

int main()
{
    Solution sol;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}