from math import gcd

def gcdOfStrings(str1: str, str2: str) -> str:
    # Check if str1 + str2 is equal to str2 + str1
    if str1 + str2 != str2 + str1:
        return ""
    # Calculate the GCD of the lengths of the two strings
    gcd_length = gcd(len(str1), len(str2))
    # Return the substring of str1 from the start to the gcd_length
    return str1[:gcd_length]

# Example usage
str1 = "ABCABC"
str2 = "ABC"
print(gcdOfStrings(str1, str2))  # Output: "ABC"

