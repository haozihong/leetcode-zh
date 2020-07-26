class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        if k >= len(s): return 0
		# special case that len(s) == 100
        if len(s) == 100 and all(map(lambda c: c==s[0], s[1:])):
            if k == 0: return 4
            if k <= 90: return 3
            if k <= 98: return 2
            return 1
			
        @functools.lru_cache(None)
        def f(p, k, c, l2):  # p: current pointer, from last to 0; l2: len of c until p
            if k < 0: return 10000
            if p < 0: return 0
            if c == s[p]:
				# concatanating same letter is always better than delete it
				# only need to track on 1 or 2 digits cases, since 100 same letters case is handled already
                return f(p-1, k, c, min(10, l2+1)) + (l2 in [1,9]) 
            else:
                # 2 cases of delete or keep s[p]
                return min(f(p-1, k-1, c, l2), f(p-1, k, s[p], 1) + 1)
        
		return f(len(s)-1, k, None, 0)