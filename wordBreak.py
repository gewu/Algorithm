class Solution(object):
    def wordBreak(self, s, wordDict):
        ret = [0]*(len(s)+1)
        ret[0] = True
        for i in range(1, len(s)+1):
            for j in range(i-1, -1, -1):
                if (ret[j] and wordDict.get(s[j:i], None) == 1):
                    ret[i] = True
                    break;

        return ret[len(s)]

if __name__ == "__main__":
    s = "ab"
    wordDict = {"a":1, "b":1}
    sol = Solution()
    print sol.wordBreak(s, wordDict)


