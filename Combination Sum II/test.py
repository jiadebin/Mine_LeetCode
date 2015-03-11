#!/usr/bin/env python
# -*- coding: utf-8 -*-


'''
Tags: Array Backtracking

Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]


'''

import copy

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):      #大神版，DP法，快了约3倍
        candidates.sort()
        print candidates
        table = [None] + [set() for i in range(target)]
        print table
        for i in candidates:
            if i > target:
                break
            for j in range(target - i, 0, -1):
                print 'i=%d, j=%d' % (i, j)
                print table
                table[i + j] |= {elt + (i,) for elt in table[j]}    #set()的取并集操作,和为i+j的成员更新，即和为j的成员都加上一个i, table的元素是set，set里面存储的是一个list，list的每个元素是tuple类型
                print table
            table[i].add((i,))      #和为i的成员有它本身
            print table
        return map(list, table[target])     #将set的每一个元素(是tuple)构造成list，map函数的返回值是一个list，此处list的每个元素就是table[8]这个set的每个元素,由于每个元素都变成list了，故此处返回一个二维嵌套list

    def combinationSum(self, candidates, target):
        self.sortList = sorted(candidates)
        clist = []
        csum = 0
        prex = 0
        self.bt(target, csum, clist, prex)
        # self.print_res()
        return self.res

    def __init__(self):
        self.res = []
        self.sortList = []

    def bt(self, target, csum, clist, prex):
        if csum == target:
            if not clist in self.res:
                self.res.append(copy.deepcopy(clist))
            return
        for x in self.sortList[prex:]:
            prex += 1
            if (csum+x) <= target:
                clist.append(x)
                csum += x
                self.bt(target, csum, clist, prex)
                clist.pop()
                csum -= x


def add(x):
    return x+1
test = Solution()
ll = [10,1,2,7,6,1,5]
#l2 = list(set(ll))     #list去重
a = set()
a.add((1,2))

print a
print map(list, a)

target = 8
# print test.combinationSum2(ll, target)

#for x in ll[1:]:
#    print x
