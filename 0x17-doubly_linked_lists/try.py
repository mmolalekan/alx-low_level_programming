def is_palindrome(number):
    # Convert the number to a string and check if it's equal to its reverse
    return str(number) == str(number)[::-1]

largest_palindrome = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

print("The largest palindrome made from the product of two 3-digit numbers is:", largest_palindrome)

