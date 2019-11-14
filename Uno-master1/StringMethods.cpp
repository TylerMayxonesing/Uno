//
// Created by T Alpha 1 on 11/2/2019.
//

#include "StringMethods.h"

//
// Created by mfbut on 4/8/2019.
//

#include <algorithm>
#include <string>

void lowerInPlace(std::string& string) {
  for (auto& letter : string) {
    letter = tolower(letter);
  }


//  for(int i = 0; i < string.size(); ++i){
//    string.at(i) = tolower(string.at(i));
//  }
//
//
//  for(/*auto*/ std::string::iterator itr = string.begin();
//    itr != string.end(); ++itr){
//    *itr = tolower(*itr);
//  }

}

std::string lower(std::string string) {
  lowerInPlace(string);
  return string;
}

void stripInPlace(std::string& string, const std::string& charsToRemove) {
  lstripInPlace(string, charsToRemove);
  rstripInPlace(string, charsToRemove);
}

void lstripInPlace(std::string& string, const std::string& charsToRemove) {

  auto itr = string.begin();
  for (; itr != string.end(); ++itr) {
    if (!contains(charsToRemove, *itr)) {
      break;
    }
  }
  string.erase(string.begin(), itr);
}

//hi cla
//bjkus

void rstripInPlace(std::string& string, const std::string& charsToRemove) {
  auto itr = string.rbegin();
  for (; itr != string.rend(); ++itr) {
    if (!contains(charsToRemove, *itr)) {
      break;
    }
  }
  string.erase(itr.base(), string.end());
}

bool contains(const std::string& string, char letter) {
  return std::find(string.cbegin(), string.cend(), letter) != string.cend();
  for (const auto& curChar : string) {
    if (curChar == letter) {
      return true;
    }
  }
  return false;
}

std::vector<std::string> split(const std::string& string, const std::string& delimiter) {
  std::vector<std::string> strings;
  std::size_t pos;
  unsigned int substringStart = 0;
  for (pos = string.find(delimiter);
       pos != std::string::npos;
       pos = string.find(delimiter, pos + delimiter.size())) {
    //add the substring to our vector of strings
    strings.emplace_back(string, substringStart, pos - substringStart);
    substringStart = pos + 1;
  }

  if(substringStart < string.size()){
    strings.emplace_back(string, substringStart, string.size() - substringStart);
  }
  return strings;
}
