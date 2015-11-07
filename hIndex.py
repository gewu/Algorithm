class Solution(object):
    def hIndex(self, citations):
        N = len(citations)
        cnts = [0]*(N+1)
        for c in citations:
            cnts[[c, N][c>N]] += 1
        sums = 0
        print cnts
        for h in range(N, 0, -1):
            if sums + cnts[h] >= h:
                return h
            sums += cnts[h]
        return 0
            

if __name__ == "__main__":
    citations = [3,0,6,1,5]
    s = Solution()
    print s.hIndex(citations)
                


            

