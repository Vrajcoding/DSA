#include<iostream>
#include<queue>
#include<string>

using namespace std;
void FirstNonRepeat(string s){

    int freq[26] = {0};
    queue<char> q;

    for(int i = 0;i < s.size();i++) {
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }

        if(q.empty()) {
         cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }

    }
}
int main() {

    string str = "aabccxb";
    FirstNonRepeat(str);
    return 0;
}