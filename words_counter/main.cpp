#include <iostream>
#include <map>
#include <vector>

std::vector<std::string> split(const std::string& input);
std::string to_lower_case(const std::string& input);
std::string remove_punctuation(const std::string& input);
std::map<std::string, int> get_occurences_per_word(const std::vector<std::string>& input);

int main(int argc, char const* argv[]) {
    std::string input = "Hello hello Hello world!\na my thing";

    std::vector<std::string> splitted = split(input);

    std::map<std::string, int> occurrences = get_occurences_per_word(splitted);
    for (auto const& [key, val] : occurrences) {
        std::cout << key << ':' << val << std::endl;
    }

    return 0;
}

std::vector<std::string> split(const std::string& input) {
    std::vector<std::string> retval;

    int prevPos = 0;
    for (size_t i = 0; i < input.size(); i++) {
        if (i == input.size() - 1) {
            retval.push_back(input.substr(prevPos, -1));
            break;
        }

        switch (input[i]) {
            case ' ':
            case '\n':
                retval.push_back(
                    to_lower_case(remove_punctuation(input.substr(prevPos, i - prevPos))));
                prevPos = i + 1;
                break;
            default:
                break;
        }
    }

    return retval;
}

std::string to_lower_case(const std::string& input) {
    std::string retval;

    for (char c : input) {
        retval.push_back(std::tolower(c));
    }

    return retval;
}

std::string remove_punctuation(const std::string& input) {
    std::string retval;

    for (char c : input) {
        if (!std::ispunct(c)) {
            retval.push_back(c);
        }
    }
    return retval;
}

std::map<std::string, int> get_occurences_per_word(const std::vector<std::string>& input) {
    std::map<std::string, int> retval;

    for (std::string word : input) {
        try {
            int& current_count = retval.at(word);
            current_count++;

            std::cout << "updating current count for word: " << word << ": " << current_count
                      << '\n';
        }

        catch (const std::out_of_range& e) {
            std::cout << "inserting new word: " << word << '\n';
            retval.insert({word, 1});
        }
    }
    return retval;
}