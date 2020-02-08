#include <iostream>
#include <vector>
using namespace std ;
/*
<div class="description__2b0C"><div class="content__1Y2H"><div class="notranslate"><p>给定一个非负整数数组，你最初位于数组的第一个位置。</p>

<p>数组中的每个元素代表你在该位置可以跳跃的最大长度。</p>

<p>你的目标是使用最少的跳跃次数到达数组的最后一个位置。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [2,3,1,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 跳到最后一个位置的最小跳跃数是 <code>2</code>。
&nbsp;    从下标为 0 跳到下标为 1 的位置，跳&nbsp;<code>1</code>&nbsp;步，然后跳&nbsp;<code>3</code>&nbsp;步到达数组的最后一个位置。
</pre>

<p><strong>说明:</strong></p>

<p>假设你总是可以到达数组的最后一个位置。</p>
</div></div></div>*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size() ;
        if(len == 0) {
            return 0 ;
        }
        int newReach = 0 ;//记录从现在区域出发到达的最远位置
        int ans = 0 ; //记录次数
        int cur = 0 ; //记录现在区域的最远位置
        for(int i=0; i<len; i++) {
            if(i>cur) { //超过现在区域的最远位置
                ans++ ; //记录次数
                cur = newReach ; //记录现在区域的最远位置
            } 
            newReach = max(newReach, i+nums[i]) ; //每次都更新从此区域出发的最远到达位置
        }
        return ans;
    }
};

int main() {
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a < 0) break ;
        ls.push_back(a) ;
    }
    cout << ss.jump(ls) << endl ;
    return 0;
}

