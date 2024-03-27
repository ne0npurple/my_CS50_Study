# TODO
import cs50
import math
import sys

def main():
    text = cs50.get_string("Text: ")

    record = get_all_count(text)
    
    grade = get_grade(record)
    
    if grade < 1:
        print("Before Grade 1")
        sys.exit(0)
    if grade >= 16:
        print("Grade 16+")
        sys.exit(0)
    
    print(f"Grade {grade}")
    sys.exit(0)

def get_all_count(text):
    record = {}
    
    words = 1
    sentences = 0
    letters = 0
    for word in text:
        if word.isalpha():
            letters += 1
        if word  == " ":
            words += 1
        if word == '!' or word == '?' or word == '.':
            sentences += 1
    
    record["words"] = words
    record["sentences"] = sentences
    record["letters"] = letters
    
    return record

def get_grade(record):
    L = float(record["letters"]/record["words"]) * 100 
    S = float(record["sentences"]/record["words"]) * 100
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    return grade

main()