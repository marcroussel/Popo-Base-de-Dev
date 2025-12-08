#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using dictionary = std::multimap<std::string, std::string>;

// Function to sort the letters of a given word
// in an alphabetic order, regardless of the whitespaces
std::string normalize(std::string const & word) {
    
    // Building the normalized word
    std::string normalized_word = word;

    // Removing every instance of whitespace
    normalized_word.erase(std::remove(normalized_word.begin(), normalized_word.end(), ' '), normalized_word.end());
   
    // ---- Converting every character to its lower case ---- // 
    std::transform(normalized_word.begin(), normalized_word.end(), normalized_word.begin(), ::tolower);
    
    // ---- Sorting characters of the word ---- //
    std::sort(normalized_word.begin(), normalized_word.end());

    return normalized_word;
}

// Function to know if two given words are anagram or not
bool are_anagrams(std::string const & w1, std::string const & w2) {
    std::cout << normalize(w1) << std::endl;
    std::cout << normalize(w2) << std::endl;
    return (normalize(w1) == normalize(w2));
}

// Function to load the dictionary of all words into a vector of string
std::vector<std::string> load() {

    // Initializing the words vector
    std::vector<std::string> words_to_return;

    // Building a new file input stream to open the file 'words.txt'
    std::ifstream file("words.txt");

    // To store the current word read
    std::string current_word;
    
    // Reading every word of the file
    while (std::getline(file, current_word)) {
        words_to_return.push_back(current_word);
    }

    return words_to_return;
}

// Function to convert a whole vector of words into a dictionary
// with their normalized words as their keys
dictionary convert(std::vector<std::string> const & vec) {
    dictionary dict_to_return;

    for (int i = 0; i < (int)vec.size(); i++) {
        std::string current_word = vec[i];
        std::string current_word_normalized = normalize(current_word);
        dict_to_return.insert(std::pair<std::string, std::string>(current_word_normalized, current_word));
    }

    return dict_to_return;
}

std::vector<std::string> anagrams(dictionary const & dict, std::string const & word) {

     std::vector<std::string> result;
    // Fetching every anagram of the normalized verion of the word in params
    auto anagram_range = dict.equal_range(normalize(word));

    for(auto it= anagram_range.first;it!=anagram_range.second;it++)
    {
        result.push_back(it->second);
    }
    return result;
}

int main(int, char **) {
    std::cout << "----- Testing normalize function ----- \n";
    std::cout << normalize("T a c o s C h i  c k e    n    ") << "\n";

    std::cout << "\n----- Testing are_anagrams -----\n";

    std::string word1 = "Listen";
    std::string word2 = "Silent";
    std::string word3 = "Silence";

    if(are_anagrams(word1, word2)) {
        std::cout << "Listen and Silent are anagrams \n";
    }
    if(!(are_anagrams(word1, word3))) {
        std::cout << "Listen and Silence are not anagrams \n";
    }

    std::cout << "\n----- Testing load -----\n";

    std::vector<std::string> dico = load();
    int size = dico.size();
    std::cout << "dico size : " << size << std::endl;
    std::cout << "dico's last word' : " << dico[size - 1] << std::endl; 

    std::cout << "\n----- Testing dictionary conversion -----\n";
    dictionary dico_with_keys = convert(dico);

    std::vector<std::string> test_words = { "anagram", "parrot", "abba", "insert", "silent" };
    for (int i = 0; i < (int)test_words.size(); i++) {
        std::cout << "Anagrams of " << test_words[i] << " : \n";

        // Fetching evey anagram of the word
        std::vector<std::string> anagram_list = anagrams(dico_with_keys, test_words[i]);
        for (int j = 0; j < (int)anagram_list.size(); j++) {
            std::cout << "Anagrams of " << anagram_list[j] << " \n";
        }

        std::cout << "\n";
    }
    

    return 0;
}

// PART 3 
/* 
We'll use std::multimap instead of std::map, for one normalized word (which will be our key), you can have
many different anagrams (that are our values). It will be more convinient to use multimap, that allows us 
to use multiple values for the same key.
*/