/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include "testing/SimpleTest.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include <fstream>
#include <cctype>
#include <string>
#include "vector.h"
using namespace std;

/* This function is intended to return a string which
 * contains only the letter characters from the original
 * (all non-letter characters are removed)
 *
 * WARNING: The provided code is buggy!
 *
 * Use unit tests to identify which inputs to this function
 * are incorrectly handled. Then, remove this comment and
 * replace it with a description of the bug you fixed.
 */
string removeNonLetters(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

string capital(string s){
    string result = "";
    for (int i = 0; i < s.length(); i++){
        result.push_back(toupper(s[i]));
    }

    return result;
}

string decoding(const string& name){
    string zero = "AEIOUHWY";
    string one = "BFPV";
    string two = "CGJKQSXZ";
    string three = "DT";
    string four = "L";
    string five = "MN";
    string six = "R";
    string code = "";
    for(int i = 0; i < name.length(); i++){
        if (zero.find(name[i]) != string::npos)
            code += '0';
        else if (one.find(name[i]) != string::npos)
            code += '1';
        else if (two.find(name[i]) != string::npos)
            code += '2';
        else if (three.find(name[i]) != string::npos)
            code += '3';
        else if (four.find(name[i]) != string::npos)
            code += '4';
        else if (five.find(name[i]) != string::npos)
            code += '5';
        else if (six.find(name[i]) != string::npos)
            code += '6';
    }

    return code;
}

string uniq(string code){
    string uniq = charToString(code[0]);
    char temp = code[0];
    for(int i = 1; i < code.length(); i++){
        if (temp == code[i])
            continue;
        uniq.push_back(code[i]);
        temp = code[i];
    }

    return uniq;
}

string letter1(string uniq, string capital_name){
    string result = charToString(capital_name[0]);
    for(int i = 1; i < uniq.length(); i++){
        result.push_back(uniq[i]);
    }

    return result;
}

string nonZero(string uniq){
    string non0 = "";
    for(int i = 0; i < uniq.length(); i++){
        if (uniq[i] == '0')
            continue;
        non0.push_back(uniq[i]);
    }

    return non0;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string Result(string non0){
    string result = non0;
    int length = non0.length();
    if (length > 4){
        for(int i = 0; i < length - 4; i++){
            result.pop_back();
        }
        return result;
    }

    else if (length < 4){
        for(int i = 0; i < 4 - length; i++){
            result.push_back('0');
        }
        return result;
    }

    return result;
}

string soundex(string s) {
    /* TODO: Fill in this function. */
    string letter_all = removeNonLetters(s);
    string cap = capital(letter_all);
    string code = decoding(cap);
    string result = uniq(code);
    result = letter1(result, cap);
    result = nonZero(result);
    result = Result(result);


    return result;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // The proivded code opens the file with the given name
    // and then reads the lines of that file into a vector.
    ifstream in;
    Vector<string> databaseNames;

    if (openFile(in, filepath)) {
        readEntireFile(in, databaseNames);
    }
    cout << "Read file " << filepath << ", "
         << databaseNames.size() << " names found." << endl;

    // The names in the database are now stored in the provided
    // vector named databaseNames
    string input;
    vector<string> result;
    /* TODO: Fill in the remainder of this function. */
    while(true){
        cout << "please enter the name: ";
        input = getLine();
        if (input == "q" || input == "Q")
            break;
        string code = soundex(input);
        for(auto ite: databaseNames){
            if(soundex(ite) == code)
                result.push_back(ite);
        }
        cout << "match from database: {";
        for(auto ite: result){
            if(ite == result.back()){
                cout << ite << "}";
                break;
            }
            cout << ite << " ,";
        }
    }
}


/* * * * * * Test Cases * * * * * */


PROVIDED_TEST("Test removing puntuation, digits, and spaces") {
    soundex("0Curie");
    string s = "O'Hara";
    string result = removeNonLetters(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = removeNonLetters(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = removeNonLetters(s);
    EXPECT_EQUAL(result, "tldr");
}


PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
    EXPECT_EQUAL(soundex("YAOCHENGXI"), soundex("Yegnashankaran"));
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}

// TODO: add your test cases here

STUDENT_TEST("Expose the error in code"){
    string s = "1ASD";
    string result = removeNonLetters(s);
    EXPECT_EQUAL(result, string("ASD"));
    soundexSearch("res/surnames.txt");
}
