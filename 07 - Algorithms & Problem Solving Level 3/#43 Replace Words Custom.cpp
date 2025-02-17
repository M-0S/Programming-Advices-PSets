// #43 Replace Words Custom
// https://programmingadvices.com/courses/1869980/lectures/42840213/comments/25851959

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitString(string text, string delim = " ")
{
	string sWord; // define a string variable & delimiter
	vector<string> tokens;
	short pos;

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos); // store the word
		if (sWord != "") tokens.push_back(sWord);
		text.erase(0, pos + delim.length()); // erase() until positon and move to next word.
	}
	if (text != "") tokens.push_back(text); // include last word of the string.
	return tokens;
}

string LowerString(string word)
{
	string word2 = "";
	for (char c : word)
		word2 += tolower(c);
	return word2;
}

string ReplaceStringWords(string text, string oldWord, string newWord, bool matchCase = true)
{
	vector<string> words = SplitString(text);
	vector<string>::iterator iter;
	text.clear();
	for (string& word : words)
	{
		if (matchCase)
			text += (word == oldWord ? newWord : word) + " ";
		else
			text += (LowerString(word) == LowerString(oldWord) ? newWord : word) + " ";
	}
	return text.substr(0, text.length() - 1); //remove last space.
}

/* Instructor solution:
string ReplaceWordInStringUsingBuiltInFunction(string S1, string
	StringToReplace, string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),
			sRepalceTo);
		pos = S1.find(StringToReplace);//find next
	}
	return S1;
}
*/

int main()
{
	string text, oldWord, newWord;
	cout << "Please Enter Your String:\n";
	getline(cin, text);
	cout << "\nWord To Replace: ";
	cin >> oldWord;
	cout << "Replace To     : ";
	cin >> newWord;
	text = ReplaceStringWords(text, oldWord, newWord);
	cout << "\nReplace with match case:\n" << text << endl;
	text = ReplaceStringWords(text, oldWord, newWord, false);
	cout << "\nReplace withiout match case:\n" << text << endl;
	return 0;
}
