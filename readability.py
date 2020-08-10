from cs50 import get_string

text = get_string("Text: ")

words = len(text.split(" "))

sentences = 0
letters = 0

for char in text:
    if char == "." or char == "!" or char == "?":
        sentences += 1
    elif char.isalpha():
        letters += 1


L = (letters / words) * 100
S = (sentences / words) * 100

index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
