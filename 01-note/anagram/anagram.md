# C++ - Anagrams

## Submission Guidelines

This lab must be completed **individually**.
You may search for information online. For this, prefer using [cppreference](https://cppreference.com).
**Any use of artificial intelligence tools or services, even if integrated in your IDE, is strictly prohibited and will result in a grade of 0, with no possibility of appeal.**

Your submission must consist of a single `cpp` file, renamed as `anagram_FIRSTNAME_LASTNAME_CLASSGROUP.cpp`, to be sent to your instructor at the following email address:

**Email:** joel.falcou@lisn.fr

**Warning:** Do **not** modify the signature of the functions already provided.

**Submission deadline:** The assignment must be sent by email **BEFORE** the end of the session. Every 5 minutes of delay will cost **-2 points**. Make sure to verify that the email has been sent correctly before leaving.

Your email subject must be `[CLASSGROUP] TP Anagram LASTNAME FirstName`.

**Warning:** Do not send executable files by email. The university mail service will block them. The late submission penalty will still apply in this case.

## Grading

The total grade is out of **20 points** distributed as follows:

- **16 points** if your code works and is of good quality. For this lab, you are required to test your own functions, which is why no unit tests are provided. Remember to check edge cases if any exist. Among these 16 points, **5 points** are awarded based on code quality (indentation, algorithmic correctness, comments, appropriate variable names...).
- **3 points** for tests written in the `main` function.
- **1 point** for answering the question in Part 3.

## Subject

An **anagram** is a permutation of the letters of a word to obtain a new word. For example, the words *listen* and *silent* have the same letters with the same number of occurrences (one *l*, one *i*, etc.), so they are anagrams of each other.

## Part 1: Anagram Detection

Define a function `std::string normalize(std::string const &)` with the following specification: the returned string must be the same for all anagrams of the word passed as argument; it must be different for two words that are not anagrams. For example, `"eilnst"` is a suitable normal form for *listen* and *silent* (other ways of normalizing are possible).

**Hints:**
- You may use `std::sort`.
- If the input string contains spaces, they should be removed by `normalize`.
- Similarly, `normalize` should convert any uppercase letters to lowercase.

Use this function to define a function `bool are_anagrams(std::string const &, std::string const &)` that takes two strings as arguments and returns `true` if they are anagrams of each other.

Test your function with a few examples in the `main` function and display the results.

## Part 2: Loading Words

Define a function `std::vector<std::string> load()` that reads the provided `words.txt` file and returns a vector of strings containing one word per element. You should preferably use `std::getline(std::istream &, std::string &)` to read from an `std::ifstream`.

Test your function in `main` by displaying the vector's length (number of words read) and the last word. *(Note: the zyzzyva is a tropical weevil.)*

## Part 3: Building a Dictionary

The goal is now to build a dictionary that allows reversing the `normalize` function. In other words, for any string `s`, an expression like `dict[normalize(s)]` should allow retrieving the value `s` among others. You will use the `std::multimap` container.

```cpp
using dictionary = std::multimap<std::string, std::string>;
```

**Question:** Why is `std::map` not suitable in this case? *(Answer as comments at the end of the `.cpp` file)*

Define a function `dictionary convert(std::vector<std::string> const &)` that creates and fills a dictionary using the words passed as argument.

**Note:** `std::multimap::insert` takes a pair formed by the key and the associated value as argument.

## Part 4: Listing Anagrams of a Word

Define a function `std::vector<std::string> anagrams(dictionary const &, std::string const &)` that returns all anagrams of a word (except itself) present in a dictionary:

```cpp
std::vector<std::string> anagrams(dictionary const &, std::string const &);
```

**Note:** The `equal_range` method of `std::multimap` returns a pair of iterators that delimit the range containing all entries in a dictionary with the same key.

Test your function by displaying the anagrams of the following words (or an error message if no anagrams are found):

```cpp
std::vector<std::string> test_words = { "anagram", "parrot", "abba", "insert", "silent" };
```
