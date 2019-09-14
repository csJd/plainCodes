#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#
# https://leetcode.com/problems/excel-sheet-column-title/description/
#
# algorithms
# Easy (29.36%)
# Likes:    794
# Dislikes: 154
# Total Accepted:    180.9K
# Total Submissions: 615.5K
# Testcase Example:  '1'
#
# Given a positive integer, return its corresponding column title as appear in
# an Excel sheet.
#
# For example:
#
#
# ⁠   1 -> A
# ⁠   2 -> B
# ⁠   3 -> C
# ⁠   ...
# ⁠   26 -> Z
# ⁠   27 -> AA
# ⁠   28 -> AB
# ⁠   ...
#
#
# Example 1:
#
#
# Input: 1
# Output: "A"
#
#
# Example 2:
#
#
# Input: 28
# Output: "AB"
#
#
# Example 3:
#
#
# Input: 701
# Output: "ZY"
#
#


class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ''
        while n:
            res = chr(ord('A') + (n-1) % 26) + res
            n = (n-1) // 26
        return res


def main():
    solu = Solution()
    print(solu.convertToTitle(701))
    print(solu.convertToTitle(28))
    print(solu.convertToTitle(1))


if __name__ == "__main__":
    main()
