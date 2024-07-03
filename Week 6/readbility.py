def words(text):
    return len(text.split())

def sentences(text):
    return sum(text.count(x) for x in '.!?')

def letters(text):
    return sum(c.isalpha() for c in text)

def grade(text):
    L = (letters(text) / words(text)) * 100
    S = (sentences(text) / words(text)) * 100
    return round(0.0588 * L - 0.296 * S - 15.8)

def main():
    # Ask the user to input some text
    text = input("Enter some text: ")

    # Calculate the grade level for the text
    grade_level = grade(text)

    # Check the grade level and output the appropriate message
    if grade_level >= 16:
        print("Grade 16+")
    elif grade_level < 1:
        print("Before Grade 1")
    else:
        print("Grade level:", round(grade_level))

if __name__ == "__main__":
    main()