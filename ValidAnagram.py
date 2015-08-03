class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        s = list(s)
        t = list(t)
        s.sort();
        t.sort();
        for i in range(len(s)):
            if s[i] != t[i]:
                return False

        return True

if __name__ == "__main__":
    s = "anagram"
    t = "nagaram"

    sn = Solution()
    print sn.isAnagram(s, t)


