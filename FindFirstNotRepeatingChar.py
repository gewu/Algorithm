class Solution:
    def FirstNotRepeatingChar(self, s):
        if len(s) == 0:
            return -1
        d = {}
        for _ in s:
            if _ not in d:
                d[_] = 1
            else:
                d[_] += 1

        for i in range(0, len(s)):
            if d[s[i]] == 1:
                return i
if __name__ == "__main__":
    s = "abcdacd"
    f = Solution()
    print f.FirstNotRepeatingChar(s)
                
