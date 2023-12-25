import sys
import re


def main():
    try:
        readability()
    except EOFError:
        print("Exiting...")
        sys.exit(0)
    except KeyboardInterrupt:
        print("Exiting...")
        sys.exit(0)


def readability():
    text = input("Text: ")
    words = get_words(text)
    letters = get_letters(text)
    sentences = get_sentences(text)

    # print(f"words: {words}")
    # print(f"letters: {letters}")
    # print(f"sentences: {sentences}")

    l = get_average_number_of_letters(letters, words)
    s = get_average_number_of_sentences(sentences, words)

    # print(f"l {l}")
    # print(f"s {s}")

    grade = calculate_grade(l,s)

    output_text = ""
    if grade > 16:
        output_text = "Grade 16+"
    elif grade < 1:
        output_text = "Before Grade 1"
    else:
        output_text = "Grade " + str(grade)

    print(f"{output_text}")


def get_words(text: str):
    # translation_table = str.maketrans({
    #     ".": "",
    #     "!": "",
    #     "?": "",
    #     ";": "",
    #     ",": ""
    # })

    # words = text.translate(translation_table).split(" ")
    words = text.split()
    return len(words)


def get_letters(text: str):
    # filtered_text = "".join(char for char in text if char.isalnum())
    
    # return len(filtered_text)
    return sum(c.isalpha() for c in ''.join(text.split()))


def get_sentences(text: str):
    # sentences = re.split(r'[.!?;]', text)
    # return len(sentences[:-1])
    return text.count('.') + text.count('!') + text.count('?')


def get_average_number_of_letters(letters, words):
    return (letters / words) * 100


def get_average_number_of_sentences(sentences, words):
    return (sentences / words) * 100


def calculate_grade(l: int, s: int):
    index = (0.0588 * l) - (0.296 * s) - 15.8

    return round(index)


if __name__ == "__main__":
    main()


# def coleman_liau_index(text):
#     words = text.split()
#     num_letters = sum(c.isalpha() for c in ''.join(words))
#     num_sentences = text.count('.') + text.count('!') + text.count('?')

#     # Calculate L and S per 100 words
#     L = (num_letters / len(words)) * 100
#     S = (num_sentences / len(words)) * 100

#     # Calculate Coleman-Liau index
#     CLI = 0.0588 * L - 0.296 * S - 15.8
#     return CLI

# # Example usage
# text_example = "This is a sample sentence. It has some words."
# result = coleman_liau_index(text_example)
# print(f"Coleman-Liau Index: {result}")


# testing
# One fish. Two fish. Red fish. Blue fish.