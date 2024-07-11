def reverse_parentheses(s: str) -> str:
    stack = []
    result = ""
    for char in s:
        if char == '(':
            stack.append(result)
            result = ""
        elif char == ')':
            result = stack.pop() + result[::-1]
        else:
            result += char
    return result

# Example usage

input_str = "(ed(et(oc))el)"
output_str = reverse_parentheses(input_str)
print(output_str)  # Output: "leetcode"
