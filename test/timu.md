<div class="notranslate"><p>给定一个字符串<code>S</code>，通过将字符串<code>S</code>中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。</p>

<pre><strong>示例:</strong>
<strong>输入:</strong> S = "a1b2"
<strong>输出:</strong> ["a1b2", "a1B2", "A1b2", "A1B2"]

<strong>输入:</strong> S = "3z4"
<strong>输出:</strong> ["3z4", "3Z4"]

<strong>输入:</strong> S = "12345"
<strong>输出:</strong> ["12345"]
</pre>

<p><strong>注意：</strong></p>

<ul>
	<li><code>S</code>&nbsp;的长度不超过<code>12</code>。</li>
	<li><code>S</code>&nbsp;仅由数字和字母组成。</li>
</ul>
</div>

<div class="notranslate"><p>给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。</p>

<p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>

<p><strong>示例:</strong>&nbsp;<br>
给定如下二叉树，以及目标和 <code>sum = 22</code>，</p>

<pre>              <strong>5</strong>
             / \
            <strong>4 </strong>  8
           /   / \
          <strong>11 </strong> 13  4
         /  \      \
        7    <strong>2</strong>      1
</pre>

<p>返回 <code>true</code>, 因为存在目标和为 22 的根节点到叶子节点的路径 <code>5-&gt;4-&gt;11-&gt;2</code>。</p>
</div>


<div class="description__2b0C"><div class="content__1Y2H"><div class="notranslate"><p>给定一个单链表&nbsp;<em>L</em>：<em>L</em><sub>0</sub>→<em>L</em><sub>1</sub>→…→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>n ，</sub><br>
将其重新排列后变为： <em>L</em><sub>0</sub>→<em>L</em><sub><em>n</em></sub>→<em>L</em><sub>1</sub>→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>2</sub>→<em>L</em><sub><em>n</em>-2</sub>→…</p>

<p>你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>给定链表 1-&gt;2-&gt;3-&gt;4, 重新排列为 1-&gt;4-&gt;2-&gt;3.</pre>

<p><strong>示例 2:</strong></p>

<pre>给定链表 1-&gt;2-&gt;3-&gt;4-&gt;5, 重新排列为 1-&gt;5-&gt;2-&gt;4-&gt;3.</pre>
</div></div></div>
