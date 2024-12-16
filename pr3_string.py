def longest_word(sentence):
    words = sentence.split()
    longest = max(words, key=len)
    return longest

def char_frequency(sentence, char):
    return sentence.count(char)

def is_palindrome(sentence):
    cleaned_sentence = sentence.replace(" ", "").lower()  # Removing spaces and converting to lower case
    return cleaned_sentence == cleaned_sentence[::-1]

def first_substring_index(sentence, substring):
    try:
        return sentence.index(substring)
    except ValueError:
        return -1  # If substring is not found

def word_occurrences(sentence):
    words = sentence.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count

# Example usage:
sentence = "madam arora teaches malayalam in the school"
char = 'a'
substring = 'madam'

print(f"Longest word: {longest_word(sentence)}")
print(f"Frequency of '{char}': {char_frequency(sentence, char)}")
print(f"Is palindrome: {is_palindrome(sentence)}")
print(f"First occurrence of substring '{substring}': {first_substring_index(sentence, substring)}")
print(f"Word occurrences: {word_occurrences(sentence)}")
