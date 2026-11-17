class Solution:
    def isValid(self, s: str) -> bool:
        li: list[str] = []
        sum:int = 0
        for i in range(0,len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                li.append(s[i])
            elif s[i] == ')' or s[i] == '}' or s[i] == ']':
                if len(li) == 0:
                    return False
                if s[i] == ')' :
                    if li[-1] != '(' : return False
                    li.pop()
                elif s[i] == '}':
                    if li[-1] != '{' : return False
                    li.pop()
                elif s[i] == ']':
                    if li[-1] != '[' : return False
                    li.pop()

        return len(li) == 0