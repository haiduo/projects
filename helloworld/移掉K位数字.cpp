#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{

public:
    string removeKdigits(string num, int k)
    {
        string res;
        int n = num.size(), m = n - k;
        for (char c : num)
        {
            while (k && res.size() && res.back() > c)
            {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(m);
        //去除前导0， 如10200，k = 1
        while (!res.empty() && res[0] == '0')
        {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};

int main()
{
    int k;
    string str;
    getline(cin, str);
    cin >> k;
    Solution s;
    cout << s.removeKdigits(str, k) << endl;
    system("pause");
    return 0;
}