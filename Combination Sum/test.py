#coding=utf-8
'''
Tags: Array Backtracking

Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

Solution:还是正常的递归，注意递归结束条件，且记得要pop.

'''

import copy

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        clist = []
        csum = 0
        self.bt(candidates, target, csum, clist, 0)
        # self.print_res()
        return self.res

    def __init__(self):
        self.res = []

    def bt(self, candidates, target, csum, clist, prex):
        if csum == target:
            self.res.append(copy.deepcopy(clist))
            return
        for x in candidates:
            if x < prex:
                pass
            elif (csum+x) <= target:
                clist.append(x)
                csum += x
                self.bt(candidates, target, csum, clist, x)
                clist.pop()
                csum -= x

    def print_res(self):
        print self.res

test = Solution()
ll = [2,3,6,7]
target = 1
print test.combinationSum(ll, target)