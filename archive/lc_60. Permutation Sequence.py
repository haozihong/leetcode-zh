class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        A = list("123456789"[:n])
        k -= 1
        for i in range(n-1, 0, -1):
            p = math.factorial(i)
            t, k = k // p, k % p
            A.append(A.pop(t))
        A.append(A.pop(0))
        return "".join(A)