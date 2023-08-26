

// 解法四：动态规划
// 这道题同样适合用动规来做。我们这样来定义状态f(i)：

// 当字符串s的子串[0, i] 能够被拆分，则f(i) = true
// 当字符串s的子串[0, i]不能被拆分，则f(i) = false
// 即 f(i) 代表着字符串s的某个前缀，是否能拆分。

// 对于状态转移，这样来考虑：我们枚举所有能进行拆分的位置（分割点），看能否转移过去即可。

// 求f(i)时，我们枚举分割点j ∈ [0, i - 1]，字符串被切割成了两部分：[0, j]，[j + 1, i]。只需要满足 f(j) = true 并且子串 [j + 1, i] 是 wordDict 中的字符串，则 f(i) = true（前半部分能够被拆分，且后半部分是wordDict中的字符串）。若枚举了所有的j都无法找到这样的情况，则f(i) = false。

// 具体的代码实现中：

// 由于f(i)的计算需要依赖于i 之前的状态f，所以我们开的数组大小为 s.length() + 1。

// 并且用 f(1) 来表示字符串s的[0, 0] 能否拆分（长度为1）
// f(2) 表示 [0, 1]能否拆分（长度为2）。

// 这和上面的描述有点不同，主要是为了方便代码实现。

// 还要注意初始化 f(0) = true，可以理解为wordDict中总是有一个空字符串。（下面的代码中，注意看注释，对于理解很重要）


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {   // 遍历背包
            for (int j = 0; j < i; j++) {       // 遍历物品
                string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, char* argv[]) {
	string s = "leetcode";
	vector<string> wordDict = {"leet","code"};
	Solution s2;
	cout<<s2.wordBreak(s,wordDict)<<endl;


	return 0;
}
