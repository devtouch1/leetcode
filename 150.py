class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t=='+' and len(stack)>=2:
                b = stack.pop()
                a = stack.pop()
                stack.append(a+b)
            elif t=='-' and len(stack)>=2:
                b = stack.pop()
                a = stack.pop()
                stack.append(a-b)
            elif t=='/' and len(stack)>=2:
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a/b))
            elif t=='*' and len(stack)>=2:
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a*b))
            else:
                stack.append(int(t))
            
        return stack[-1]
        