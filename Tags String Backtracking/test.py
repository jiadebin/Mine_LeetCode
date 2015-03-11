#!/usr/bin/env python
# -*- coding: utf-8 -*-


'''
Tags: String Backtracking

Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Solution:递归，首先递归求得前n-1个数字的结果，然后与最后一个字符串组合,组合的过程就是双层循环,注意字符的顺序

'''

import copy

class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if len(digits) == 0:
            return [""]
        numMap = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}     #key使用字符，而不是直接用数字，因为从digits中取出每个元素是字符，这样可以不用转换为数字了
        pre = digits[:-1]   #取前n-1个数字子串
        preRes = self.letterCombinations(pre)
        # print preRes

        lastC = digits[-1]  #处理最后一个数字字符
        lastStr = numMap[lastC]
        res = []
        for a in lastStr:
            for b in preRes:
                c = b+a     #注意a、b的顺序有先后
                res.append(c)
        return res


test = Solution()

digits = "23"
print test.letterCombinations(digits)

