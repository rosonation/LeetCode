/*=======================================
* @FileName: [3].无重复字符的最长子串.js
* @Description: 
* @Author: TonyLaw
* @Date: 2021-09-09 01:40:32 Thursday
* @Copyright:  © 2021 TonyLaw. All Rights Reserved.
=========================================*/
/*=======================================
                (题目难度：中等)
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

=========================================*/
/**
 * @param {string} 
 * @return {number}
 */
const { max } = require("lodash");

var lengthOfLongestSubstring = function(s) {
    // 哈希集合，记录每个字符是否出现过
    const occ = new Set();
    const n = s.length;
    // 右指针， 初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    let rk = -1,
        ans = 0;
    for (let i = 0; i < n; ++i) {
        if (i !== 0) {
            // 左指针向右移动一位，删除一个字符
            occ.delete(s.charAt(i - 1));
        }
        while (rk + 1 < n && !occ.has(s.charAt(rk + 1))) {
            // 不断向右移动右指针，直到有遇到重复的元素
            occ.add(s.charAt(rk + 1));
            ++rk;
        }
        // 左指针（i）到 右指针 （rk） 是最长的无重复字符子串
        ans = Math.max(ans, rk - i + 1);
    }
    return ans;
};

let s1 = "hello";
let result = lengthOfLongestSubstring(s1);
console.log(result);