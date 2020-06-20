P = [1]
for i in range(2, 10):
    P.append(P[-1] * i)
    
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        A = list("123456789"[:n])
        k -= 1
        for i in range(n-2, -1, -1):
            t, k = k // P[i], k % P[i]
            A.append(A.pop(t))
        A.append(A.pop(0))
        return "".join(A)