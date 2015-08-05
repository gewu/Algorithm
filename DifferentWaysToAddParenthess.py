class Solution:
    def diffWaysToCompute(self, input):
        ans = []
        for i in range(len(input)):
            c = input[i]
            if c in "+-*":
                a = self.diffWaysToCompute(input[:i])
                b = self.diffWaysToCompute(input[i+1:])
                for m in a:
                    for n in b:
                        if c == '+':
                            ans.append(m+n)
                        elif c == '-':
                            ans.append(m-n)
                        elif c == '*':
                            ans.append(m*n)
        if not ans:
            ans.append(int(input))

        return ans

if __name__ == "__main__":
    input = "2*3-4*5"
    s = Solution()
    print s.diffWaysToCompute(input)
   

