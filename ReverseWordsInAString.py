class Solution:
    def reverseWords(self, s):
        wordlist = s.split(" ")
        wordstr = ""
        for word in reversed(wordlist):
            wordstr = "%s %s" % (wordstr, word)
        print wordstr
        return wordstr.strp()

if __name__ == "__main__":
    solution = Solution()
    wordstr = solution.reverseWords("the sky is blue");
