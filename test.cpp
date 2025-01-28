#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include "functions_to_implement.h"
#include "catch.hpp"

// Split String

TEST_CASE("Empty Strings return empty vector", "[split]") {
    REQUIRE( Split("", "").size() == 1 );
}

TEST_CASE("Empty separator returns single length vector.", "[split]") {
    std::string str = "hello";
    std::vector<std::string> result = Split(str, "");
    REQUIRE( result.size() == 1 );
    REQUIRE( result.front() == str );
}


TEST_CASE("Separates by single character correctly", "[split]") {
    std::string str = "hello,my,name,is,reda";
    std::vector<std::string> result = Split(str, ",");
    std::vector<std::string> expected = {"hello","my","name","is","reda"};
    REQUIRE( result.size() == 5 );
    REQUIRE( result == expected );
}

TEST_CASE("Separates by single character with trailing separator", "[split]") {
    std::string str = "hello,my,name,is,reda,";
    std::vector<std::string> result = Split(str, ",");
    std::vector<std::string> expected = {"hello","my","name","is","reda"};
    REQUIRE( result.size() == 5 );
    REQUIRE( result == expected );
}

TEST_CASE("Separates by multiple characters correctly", "[split]") {
    std::string str = "hello,my,mame,is,reda";
    std::vector<std::string> result = Split(str, ",m");
    std::vector<std::string> expected = {"hello","y","ame,is,reda"};
    REQUIRE( result.size() == 3 );
    REQUIRE( result == expected );
}

TEST_CASE("Separates by multiple characters with trailing separator", "[split]") {
    std::string str = "hello,my,mame,is,reda,m";
    std::vector<std::string> result = Split(str, ",m");
    std::vector<std::string> expected = {"hello","y","ame,is,reda"};
    REQUIRE( result.size() == 3 );
    REQUIRE( result == expected );
}

// Remove All Substrings

TEST_CASE("Removing all empty strings from empty string returns empty", "[RemoveAllSubstrings]") {
    REQUIRE( RemoveAllSubstrings("", "") == "" );
}

TEST_CASE("Removing all nonexistent single character substrings returns original string", "[RemoveAllSubstrings]") {
    REQUIRE( RemoveAllSubstrings("hello", "w") == "hello" );
}

TEST_CASE("Removing all nonexistent multiple character substrings returns original string", "[RemoveAllSubstrings]") {
    REQUIRE( RemoveAllSubstrings("hello", "li") == "hello" );
}

TEST_CASE("Removing all substrings of single character removes all instances of single character", "[RemoveAllSubstrings]") {
    REQUIRE( RemoveAllSubstrings("hello", "l") == "heo" );
}

TEST_CASE("Removing all substrings of multiple characters removes all instances of multiple characters", "[RemoveAllSubstrings]") {
    REQUIRE( RemoveAllSubstrings("helloll", "ll") == "heo" );
}

// Remove First Substring

TEST_CASE("Removing first empty string from empty string returns empty", "[RemoveFirstSubstring]") {
    REQUIRE( RemoveFirstSubstring("", "") == "" );
}

TEST_CASE("Removing first empty string returns original string", "[RemoveFirstSubstring]") {
    REQUIRE( RemoveFirstSubstring("a", "") == "a" );
}

TEST_CASE("Removing first nonexistent single character substring returns original string", "[RemoveFirstSubstring]") {
    REQUIRE( RemoveFirstSubstring("hello", "w") == "hello" );
}

TEST_CASE("Removing first nonexistent multiple character substring returns original string", "[RemoveFirstSubstring]") {
    REQUIRE( RemoveFirstSubstring("hello", "li") == "hello" );
}

TEST_CASE("Removing first substring of single character removes single character", "[RemoveFirstSubstring]") {
    REQUIRE( RemoveFirstSubstring("hello", "l") == "helo" );
}

TEST_CASE("Removing first substring of multiple characters removes multiple character", "[RemoveFirstSubstring]") {
    REQUIRE( RemoveFirstSubstring("hello", "ll") == "heo" );
}