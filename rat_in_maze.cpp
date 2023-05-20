#include <iostream>

#include <vector>
using namespace std;

class Solution
{
    void rat(vector<vector<int>> &m, int n, string output, int x, int y, vector<string> &ans)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(output);
            return;
        }

        // up
        if (x - 1 >= 0 && (m[x - 1][y] == 1))
        {
            output.push_back('U');
            m[x][y] = 0;
            rat(m, n, output, x - 1, y, ans);
            m[x][y] = 1;
            output.pop_back();
        }
        // down
        if (x + 1 < n && (m[x + 1][y] == 1))
        {
            output.push_back('D');
            m[x][y] = 0;
            rat(m, n, output, x + 1, y, ans);
            m[x][y] = 1;
            output.pop_back();
        }
        // left
        if (y - 1 >= 0 && (m[x][y - 1] == 1))
        {
            output.push_back('L');
            m[x][y] = 0;
            rat(m, n, output, x, y - 1, ans);
            m[x][y] = 1;
            output.pop_back();
        }
        // right
        if (y + 1 < n && (m[x][y + 1] == 1))
        {
            output.push_back('R');
            m[x][y] = 0;
            rat(m, n, output, x, y + 1, ans);
            m[x][y] = 1;
            output.pop_back();
        }
        return;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        string output = "";
        rat(m, n, output, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
