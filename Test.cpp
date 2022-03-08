/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include <iostream>
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

string min(int w, int h, char ch1, char ch2){
	string mat = ariel::mat(w, h, ch1, ch2);
	string rev_mat = ariel::mat(w, h, ch2, ch1);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (mat[i * w + j] == rev_mat[i * w + j] && mat[i * w + j] != '\n') {
				return "";
			}
		}
	}
	return mat;
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces(" @@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	/* Add more test here */
}

TEST_CASE("Good input") {
	CHECK(nospaces(min(9, 7, '@', '-')) == nospaces(" @@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	/* Add more test here */
}

TEST_CASE("good input 2") {
	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));
	/* Add more test here */
}

TEST_CASE("good input 2") {
	CHECK(nospaces(mat(1, 1, '@', '-')) != "");
	/* Add more test here */
}

TEST_CASE("good input 3") {
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces(" @@@@@@@@@@@@@\n"
													  "@-----------@\n"
													  "@-@@@@@@@@@-@\n"
													  "@-----------@\n"
													  "@@@@@@@@@@@@@"));
	/* Add more test here */
}

TEST_CASE("Bad input7") {
	CHECK_THROWS(mat(5, 10, '$', '%'));
	/* Add more test here */
	CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
}

TEST_CASE("Bad input 2") {
	CHECK_THROWS(mat(8, 2, '@', '-'));
	/* Add more test here */
	CHECK_THROWS(mat(2, 8, '@', '-'));
	/* Add more test here */
}

TEST_CASE("Bad input 4") {
	CHECK_THROWS(mat(0, 0, '@', '-'));
	/* Add more test here */
}
TEST_CASE("Bad input 5") {
	CHECK_THROWS(mat(1, 0, '@', '-'));
	CHECK_THROWS(mat(0, 1, '@', '-'));
	/* Add more test here */
	/* Add more test here */
}

/* Add more test cases here */
TEST_CASE("good input 3") {
	CHECK(nospaces(mat(13, 5, '@', '@')) == nospaces(" @@@@@@@@@@@@@\n"
													  "@@@@@@@@@@@@@\n"
													  "@@@@@@@@@@@@@\n"
													  "@@@@@@@@@@@@@\n"
													  "@@@@@@@@@@@@@"));
	/* Add more test here */
}
TEST_CASE("no space delte"){
	CHECK(nospaces(mat(5, 5, '\n', '@')) == nospaces(" \n"
													  "@@@\n"
													  "@@\n"
													  "@@@\n"
													  ""));
}

TEST_CASE("no space delte"){
	CHECK(nospaces(mat(5, 5, '\n', ' ')) == nospaces(""));
}

TEST_CASE("no space delte"){
	CHECK(nospaces(mat(3, 3, '1', ' ')) == nospaces("111\n11\n111"));
}

TEST_CASE("no space delte"){

	CHECK(nospaces(mat(5, 5, 64, 65)) == nospaces("@@@ @@@AA A@@A  @A@@AAA@ @@@@@"));
}

TEST_CASE("no space delte"){

	CHECK(nospaces(mat(5, 1, 'a', 'b')) == nospaces("aaaaa"));
}

TEST_CASE("no space delte"){

	CHECK(nospaces(mat(1, 5, 'a', 'b')) == nospaces("aaaaa"));
}

TEST_CASE("no space delte"){

	CHECK(nospaces(mat(3, 3, 'a', 'a')) == nospaces("aaaaaaaaa"));
}
// add test to check if input will raise an error (bad input) odd numbers
TEST_CASE("Bad input 6") {
	CHECK_NOTHROW(mat(5, 5, '@', '-'));
	/* Add more test here */
}
