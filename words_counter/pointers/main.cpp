
#include <iostream>

void print_words(char** words, size_t word_count);
void swap_words(char** words, size_t pos1, size_t pos2);
char* find_longest_word(char** words, size_t word_count);
char** insertWord(char** words, size_t& word_count, size_t position, const char* new_word);

int main(int argc, char const* argv[]) {
    char sentence[1000];
    std::cin.getline(sentence, 1000);

    size_t word_count = 0;
    for (size_t i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            word_count++;
        }
    }
    word_count++;

    std::cout << "word count: " << word_count << '\n';

    char** words = new char*[word_count];

    size_t currentWordIndex = 0;

    size_t prevIndex = 0;
    size_t currentIndex = 0;

    char currentChar;

    do {
        currentChar = sentence[currentIndex];

        if (currentChar == ' ' || currentChar == '\0') {
            size_t word_len = currentIndex - prevIndex;
            char* word = new char[word_len + 1];

            for (size_t i = 0; i < word_len; i++) {
                *(word + i) = sentence[prevIndex + i];
            }
            word[word_len] = '\0';

            words[currentWordIndex] = word;

            currentWordIndex++;
            prevIndex = currentIndex + 1;
        }

        currentIndex++;
    } while (currentChar != '\0');

    print_words(words, word_count);

    std::cout << "swapping 0 and 1\n\n";

    swap_words(words, 0, 1);

    print_words(words, word_count);

    char* longest_word = find_longest_word(words, word_count);

    std::cout << "Longest word: " << longest_word << '\n';

    std::cout << "Inserting longest word at index 2\n";

    insertWord(words, word_count, 2, longest_word);

    print_words(words, word_count);

    return 0;
}

void print_words(char** words, size_t word_count) {
    for (size_t i = 0; i < word_count; i++) {
        std::cout << "printing word " << i + 1 << '\n';
        char* word = *(words + i);
        std::cout << word << '\n';
    }
}

void swap_words(char** words, size_t pos1, size_t pos2) {
    char* word = *words + pos1;
    words[pos1] = words[pos2];
    words[pos2] = word;
}

char* find_longest_word(char** words, size_t word_count) {
    char* longest_word = words[0];
    for (size_t i = 1; i < word_count; i++) {
        char* currentWord = words[i];
        size_t j = 0;

        do {
            if (currentWord[j] != '\0' && longest_word[j] == '\0') {
                longest_word = currentWord;
                break;
            } else if (currentWord[j] == '\0') {
                break;
            }
            j++;
        } while (true);
    }

    return longest_word;
}

char** insertWord(char** words, size_t& word_count, size_t position, const char* new_word) {
    char** retval = new char*[++word_count];

    std::cout << "copying words till position\n";
    for (size_t i = 0; i < position; i++) {
        retval[i] = words[i];
        std::cout << words[i] << '\n';
    }

    size_t new_word_size = 0;

    for (size_t i = 0; new_word[i] != '\0'; i++) {
        new_word_size++;
    }
    char* new_word_copy = new char[new_word_size + 1];

    for (size_t i = 0; i < new_word_size; i++) {
        new_word_copy[i] = new_word[i];
    }
    new_word_copy[new_word_size + 1] = '\0';

    retval[position] = new_word_copy;

    for (size_t i = position + 1; i < word_count; i++) {
        retval[i] = words[i];
    }

    delete words;
    return retval;
}
