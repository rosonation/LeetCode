//
//  2.cpp
//  test
//
//  Created by Tony on 2021/6/15.
//
// 2. 两数相加
/* 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 
 请你将两个数相加，并以相同形式返回一个表示和的链表。

 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

  

 示例 1：


 输入：l1 = [2,4,3], l2 = [5,6,4]
 输出：[7,0,8]
 解释：342 + 465 = 807.
 示例 2：

 输入：l1 = [0], l2 = [0]
 输出：[0]
 示例 3：

 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 输出：[8,9,9,9,0,0,0,1]
  

 提示：

 每个链表中的节点数在范围 [1, 100] 内
 0 <= Node.val <= 9
 题目数据保证列表表示的数字不含前导零

*/
#include "2.addTwoNumbers.hpp"
#include <iostream>
#include <nlist.h>
#include <ListNode>
using namespace::std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        
    }
};

int main(int argc, char *argv[]) {
    Solution so;
    int b[4] = {2, 7, 11, 15};
    vector<int> a(b,b+4);
    int target = 9;
    so.twoSum(a, target);
    printf("Done.\n");
}
