//
// Created by Tony on 2021/8/9.
//
// [10].正则表达式匹配
// 给你一个字符串s和一个字符规律p，请你来实现一个支持 '.'和'*'的正则表达式匹配。
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。
//
//
//示例 1：
//
//输入：s = "aa" p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
//示例 2:
//
//输入：s = "aa" p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//示例3：
//
//输入：s = "ab" p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
//示例 4：
//
//输入：s = "aab" p = "c*a*b"
//输出：true
//解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
//示例 5：
//
//输入：s = "mississippi" p = "mis*is*p*."
//输出：false
//
//
//提示：
//
//0 <= s.length<= 20
//0 <= p.length<= 30
//s可能为空，且只包含从a-z的小写字母。
//p可能为空，且只包含从a-z的小写字母，以及字符.和*。
//保证每次出现字符* 时，前面都匹配到有效的字符
//
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    [[maybe_unused]] static bool isMatch(string s, string p) {
        int m = (int) s.size();
        int n = (int) p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

//int main(int argc, char *argv[]) {
//    string s1 = "aab";
//    string p1 = "ab*a*c*a";
//    Solution::isMatch(s1, p1);
//    cout << boolalpha << Solution::isMatch(s1, p1) << endl;
//    // cout << Solution::isMatch(s1, p1) << endl;
//}