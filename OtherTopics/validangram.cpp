#include<iostream>
#include<string>
using namespace std;

bool isAngram(string s1,string s2) {
   if(s1.length() != s2.length()) {
    return false;
   }

   int count[36] = {0};
   for(int i = 0;s1[i] != '\0';i++) {
       count[s1[i] - 'a']++;
   }

   for(int i = 0;s2[i] != '\0';i++) {
    int idx = s2[i] - 'a';
     if(count[idx] == 0) {
        return false;
     }
     count[idx]--;
   }

   return true;
}

int main() {
   string s1 = "apna";
   string s2 = "vraj";

   isAngram(s1,s2);

    return 0;
}