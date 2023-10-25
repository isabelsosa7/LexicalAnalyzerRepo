// comment
#include <iostream>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string &str, const string &sub) {
  if (sub.length() == 0)
    return 0;
  int count = 0;
  for (int offset = str.find(sub); offset != string::npos;
       offset = str.find(sub, offset + sub.length())) {
    ++count;
  }
  return count;
}

int countWords(string s) {
  int wCount = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      wCount++;
    }
  }
  return wCount;
}

int countSentences(string s) {
  int sCount = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      sCount++;
    }
  }
  return sCount;
}

int averageWordCount(string s) { return countWords(s) / countSentences(s); }

int countUniqueWords(string str) {
  string uWords[countWords(str)];
  int index = 0;
  string newString = str;
  int space = 1;
  string word;
  bool unique;
  for (int i = 0; i < countWords(str) - 1; i++) {
    unique = true;
    space = newString.find(' ');
    word = newString.substr(0, space);
    newString = newString.substr(space + 1, str.length() - space - 1);
    for (int i = 0; i < countWords(str); i++) {
      if (uWords[i] == word)
        unique = false;
    }
    if (unique) {
      uWords[index] = word;
      index++;
    }
  }
  return index - 1;
}

int findLexicalDensity(string s) {
  float u = countUniqueWords(s);
  float w = countWords(s);
  if ((u/w*100)>=int(u/w*100)+0.5){
  return int(u/w*100+1);
  }
  else
    return int(u/w*100);
}
int main() {

  string source =
      ("I was born in Lousiana down on the ol bayou raised on shrimps and "
       "catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma "
       "and pa. Crossed that ol red river and this is what I saw. I saw miles "
       "and miles of Texas 1000 stars up in the sky. I saw miles and miles of "
       "Texas gonna live here till I die.");

  cout << "substring count: " << countSubstring(source, "is") << '\n';
  cout << "word count: " << countWords(source) << '\n';
  cout << "Unique word count: " << countUniqueWords(source) << '\n';
  cout << "sentences count: " << countSentences(source) << '\n';
  cout << "average words per sentence: " << averageWordCount(source) << '\n';
  cout << "Lexical density: " << findLexicalDensity(source) << "%\n";

  return 0;
}
