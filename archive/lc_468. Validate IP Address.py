class Solution:
    def validIPAddress(self, IP: str) -> str:
        def check_ip4(IP):
            DECCHAR = frozenset("0123456789")
            nums = IP.split('.')
            if len(nums) != 4: return False
            for n in nums:
                if ((not 0<len(n)<=3) or
                    (n != '0' and n[0] == '0') or
                    any(map(lambda c: c not in DECCHAR, n)) or
                    (not 0<=int(n)<=255)): return False
            return True
        def check_ip6(IP):
            HEXCHAR = frozenset("0123456789abcdefABCDEF")
            nums = IP.split(':')
            if len(nums) != 8: return False
            for n in nums:
                if ((not 0<len(n)<=4) or
                    any(map(lambda c: c not in HEXCHAR, n))): return False
            return True
        if IP.find('.') >= 0:
            if check_ip4(IP): return "IPv4"
        elif check_ip6(IP):
            return "IPv6"
        return "Neither"