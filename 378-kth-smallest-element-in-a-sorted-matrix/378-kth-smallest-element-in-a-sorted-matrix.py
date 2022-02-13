class Solution:  # 184 ms, faster than 69.45%
        def kthSmallest(self, matrix, k):
                m, n = len(matrix), len(matrix[0])  
                maxHeap = []
                for r in range(0,m):
                    for c in range(0,n):
                        heappush(maxHeap,-matrix[r][c])
                        if len(maxHeap) > k:
                            heappop(maxHeap)
                return -heappop(maxHeap)