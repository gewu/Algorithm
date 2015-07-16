#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#--------------------------------------------------------------
#
# IntelUniq
#               -- Intelligence shall be unique 
#
# RotateArray.py: #TODO DESC HERE
#
#--------------------------------------------------------------
#
# Date:     2015-07-16
#
# Author:   gewu@baidu.com
#
#

#--------------------------------------------------------------
# Globl Constants & Functions
#--------------------------------------------------------------

#--------------------------------------------------------------
# Classes
#--------------------------------------------------------------
class Solution:
    def rotate(self, nums, k):
        n = len(nums)
        idx = 0
        distance = 0
        cur = nums[0]
        for x in range(n):
            next = (idx+k)%n
            temp = nums[next]
            nums[next] = cur
            idx = next
            cur = temp

            distance = (distance+k)%n
            if distance == 0:
                idx = (idx+1)%n
                cur = nums[idx]

if __name__ == "__main__":

    l = [1,2,3,4,5,6,7]
    s = Solution()
    s.rotate(l,3)
    print l
