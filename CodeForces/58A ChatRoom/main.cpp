// Problem: Codeforces 58A - Chatroom
// Link: https://codeforces.com/problemset/problem/58/A
// Topics: Strings, Two Pointers, Greedy
// Time Complexity: O(N) where N is input string length
// Space Complexity: O(1)

#include <iostream>
#include <string>
using namespace std;

int main(){
    string word = "hello";
    char c;
    int i = 0;
    while(cin >> c){
        if (i > word.size()) continue;
        if (tolower(c) == word[i]) i++;
    }
    if (i == (word.size())) cout << "YES" << endl;
    else cout << "NO" << endl;
}