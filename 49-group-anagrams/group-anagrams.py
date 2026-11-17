class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        
        d: dict[str,list[str]] = {}

        for s in strs:
            key = "".join(sorted(s))
            if key not in d.keys():
                d[key] = []
            d[key].append(s)

        li: list[list[str]] = []
        for val in d.values():
            li.append(val)
        return li