#include <iostream>
#include <vector>

using namespace std ;
//最长公共子序列
int substr(string & str1, string &str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>>dp(len1,vector<int>(len2,0));
    for (int i = 0; i < len1; i++)
    {
        dp[i][0] = str1[i]==str1[0]?1:0;
    }
    for (int j = 0; j <= len2; j++)
    {
        dp[0][j] = str1[0]==str2[j]?1:0;
    }

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = dp[i - 1][j - 1]+1;
            }
        }
    }
    int longest = 0;
    int longest_index = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (longest < dp[i][j])
            {
                longest = dp[i][j];
                longest_index = i;
            }
        }
    }
    return 1 ;
}

int LongestPalindromicSubstring(string & a)
{
    int len = a.length();
    vector<vector<int>>dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
    }
    int max_len = 1;
    int start_index = 0;
    for (int i= len - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] == a[j])
            {
                if (j - i == 1)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    if (j - i > 1)
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                if (max_len < dp[i][j])
                {
                    max_len =  dp[i][j];
                    start_index = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << "max len is " << max_len << endl;
    cout << "star index is" << start_index << endl;
    return max_len;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

