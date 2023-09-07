#include <iostream>
#include <chrono>

#define MAX 9999
using namespace std;
double A[MAX][MAX], x[MAX], y[MAX];
int i,j;

int main(){

   for (i = 0; i < MAX; i++){
    for (j = 0; j < MAX; j++){
      A[i][j] = 0;
    }
    x[i] = 0;
  }
  
  std::chrono::seconds s (1);             // 1 second
  std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds> (s);
  
  auto start = chrono::steady_clock::now();
  for (i = 0; i < MAX; i++){
    for (j = 0; j < MAX; j++)
      y[i] += A[i][j] * x[j];

  }
  auto end = chrono::steady_clock::now();
  ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start); 

  std::cout << "ns: " << ns.count() << std::endl;

  start = chrono::steady_clock::now();
  for (j = 0; j < MAX; j++){
    for(i = 0; i < MAX; i++)
     y[i] += A[i][j] * x[j];
  }

   end = chrono::steady_clock::now();
   ns = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

   std::cout << "ns: " << ns.count() << std::endl;

}
