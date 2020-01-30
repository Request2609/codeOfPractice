#include <iostream>
#include <unordered_map>
/*
 *<div class="notranslate"><p>给定字符串 <code>S</code> 和单词字典 <code>words</code>, 求&nbsp;<code>words[i]</code>&nbsp;中是&nbsp;<code>S</code>&nbsp;的子序列的单词个数。</p>

<pre><strong>示例:</strong>
<strong>输入:</strong> 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
<strong>输出:</strong> 3
<strong>解释:</strong> 有三个是&nbsp;S 的子序列的单词: "a", "acd", "ace"。
</pre>

<p><strong>注意:</strong></p>

<ul>
<li>所有在<code>words</code>和&nbsp;<code>S</code>&nbsp;里的单词都只由小写字母组成。</li>
<li><code>S</code> 的长度在&nbsp;<code>[1, 50000]</code>。</li>
<li><code>words</code>&nbsp;的长度在&nbsp;<code>[1, 5000]</code>。</li>
<li><code>words[i]</code>的长度在<code>[1, 50]</code>。</li>
</ul>
</div>
 * */
#include <vector>
using namespace std ;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int>counts(26,0) ;
        unordered_map<string, int>M ;
        int slen = S.size() ;
        int wpos = 0 , spos = 0 , wlen=0, res= 0 ;
        for(auto i :S) {
            counts[i-'a']++ ;
        }
        for(auto i:words) {
            M[i]++ ;
        }
        for(auto i:M) {
            string cur(i.first) ;
            wlen = cur.size() ;
            spos = 0 ;
            wpos =0 ;
            for(;wpos<wlen&&spos<slen;){
                if(counts[cur[wpos]-'a'] == 0) break ;
                if(cur[wpos] == S[spos])wpos++ ;
                spos++ ;
            }
            if(wpos ==wlen) res+=M[cur] ;
        }
        return res ;
    }
};
int main()
{
    Solution ss ;
    string sss ;
    cin >> sss ;
    vector<string>ls ;
    while(1) {
        string a ;
        cin >> a ;
        if(a == "-1") {
            break ;
        }
        ls.push_back(a) ;
    }
    cout << ss.numMatchingSubseq(sss, ls) << endl ;
    return 0;
}

