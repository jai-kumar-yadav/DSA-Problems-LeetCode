class Solution:
    def isValid(self, s: str) -> bool:
        # Map closing brackets to their corresponding opening brackets
        bracket_map = {')': '(', '}': '{', ']': '['}
        stack = []
        
        for char in s:
            # If it's a closing bracket
            if char in bracket_map:
                # Pop the top element if stack is not empty, else use a dummy value
                top_element = stack.pop() if stack else '#'
                
                # If the mapped opening bracket doesn't match the top element
                if bracket_map[char] != top_element:
                    return False
            else:
                # It's an opening bracket, push it to the stack
                stack.append(char)
        
        # If the stack is empty, all brackets were matched correctly
        return not stack
