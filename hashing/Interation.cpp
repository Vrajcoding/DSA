#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
void destination(unordered_map<string ,string> tickets){
    unordered_set<string> to;
    string start = "";
    for(auto ticket : tickets) { // to value
       to.insert(ticket.second);
    }

    for(auto ticket : tickets){
        if(to.find(ticket.first) == to.end()){ // find to value
            start = ticket.first;
        }
    }
    cout << start << "->";
    while(tickets.count(start)) {
        cout << tickets[start] << "->";
        start = tickets[start];
    }
    cout << endl;
}
int main()
{
  unordered_map<string, string> tickets;
  tickets["Chennai"] = "Benguluru";
  tickets["Mumbai"] = "Delhi";
  tickets["Goa"] = "Chennai";
  tickets["Delhi"] = "Goa";
  destination(tickets);
    return 0;
}