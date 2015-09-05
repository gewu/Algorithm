class Solution:
    def ReverseSentence(self, s):
        if s == "":
            return ""
        l = s.split()
        l.reverse()
        return " ".join(l)

if __name__ == "__main__":
    sol = Solution()
    print sol.ReverseSentence(" ")
