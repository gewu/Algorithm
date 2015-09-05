class Solution:
    def LeftRotateString(self, s, n):
        r = s[:n]
        k = s[n:]
        return k + r
    
    def LeftRotateString2(self, s, n):
        l = list(s)
        ll = l[:n]
        ll.reverse()
        lr = l[n:]
        lr.reverse
        return "".join((ll+lr)[::-1])

if __name__ == "__main__":
    sol = Solution()
    print sol.LeftRotateString2("abcXYZdef", 2)
