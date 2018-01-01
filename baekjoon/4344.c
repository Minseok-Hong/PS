#include <iostream>
using namespace std;
 
int main() {
 long double num, sum = 0, cnt = 0, average;
 int k;
 cin >> num;
 long double Per;
 for (int i = 0; i < num; i++)
 {
  cin >> k;
  int *caseNum = new int[k];
  for (int j = 0; j < k; j++)
  {
   cin >> caseNum[j];
   sum += caseNum[j];
  }
  average = sum / k; 
  for (int t = 0; t < k; t++)
  {
   if (caseNum[t] > average)
   {
    cnt++;
    continue;
   }
  }
  delete[]caseNum;
  Per = (cnt / k) * 100;
  cout << fixed;
  cout.precision(3);
  cout << Per << "%" << '\n'; 
  sum = 0;
  cnt = 0;
  average = 0;
 }
}
