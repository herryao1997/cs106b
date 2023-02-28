#include "palindrome.h"
#include <locale>
#include "testing/SimpleTest.h"

bool isPalindrome(const string& word){
    if(word.length() == 0 || word.length() == 1)
        return true;
    char begin = tolower(word.at(0));
    char end = tolower(word.at(word.length() - 1));
    if(begin == end)
        return isPalindrome(word.substr(1, (word.length() - 2)));
    return false;
}

//****************************Test Case********************

void isPalindromeTest(const string& word){
    for(int i = 0; i < 1000000; i++)
        isPalindrome(word);
}

STUDENT_TEST("Normal test"){
    EXPECT_EQUAL(isPalindrome("MADAM"), true);
    EXPECT_EQUAL(isPalindrome("LEVEl"), true);
    EXPECT_EQUAL(isPalindrome("MADAM"), isPalindrome("LEVEl"));
}


STUDENT_TEST("reverse test"){
    EXPECT_EQUAL(isPalindrome("MADA"), false);
    EXPECT_EQUAL(isPalindrome("false"), false);
    EXPECT_EQUAL(isPalindrome("MADA"), isPalindrome("LEVEt"));
}

STUDENT_TEST("edge test"){
    EXPECT_EQUAL(isPalindrome(""), true);
    EXPECT_EQUAL(isPalindrome("L"), true);
}

STUDENT_TEST("stress test"){
    string word = "a";
    for(int i = 0; i < 16; i+=3){
        TIME_OPERATION(word.length(), isPalindromeTest(word));
        word.append(word);
    }
}
