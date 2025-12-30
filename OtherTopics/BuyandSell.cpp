// Leetcode 121
#include<iostream>
#include<climits>
using namespace std;
void BuyAndsell(int *prices, int n) {
   int buyStock[2000];
   buyStock[0] = INT_MAX;
   int bestPrice = 0;
   for(int i = 1;i < n;i++) {
      buyStock[i] = min(buyStock[i-1], prices[i-1]);
   }

   for(int i = 1;i < n;i++) {
      int sellingPrice = prices[i] - buyStock[i];
      bestPrice = max(sellingPrice, bestPrice);
   }
   
   cout << "Best selling price is :" << bestPrice << endl;
}

int main() {
   int prices[] = {7,1,5,2,3};
   int n = sizeof(prices) / sizeof(int);

   BuyAndsell(prices, n);

    return 0;
}