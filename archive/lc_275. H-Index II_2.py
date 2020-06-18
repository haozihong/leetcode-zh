class Temp:
    def __init__(self, a):
        self.a, self.l = a, len(a)

    def __getitem__(self, i):
        return self.a[i] - (self.l - i)

    def __len__(self):
        return self.l
    
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        i = bisect.bisect_left(Temp(citations), 0)
        return len(citations) - i