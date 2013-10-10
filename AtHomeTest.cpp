
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;



int* Fibonacci(int n) {
  int *arr_fib;

  if(n < 1)
    return NULL;
    
  arr_fib = new int[n];
  arr_fib[0] = 1;
  if(n == 1)
    return arr_fib;
  
  arr_fib[1] = 1;
  if(n == 2)
    return arr_fib;
    
  for (int i = 2; i < n; i++) {
    arr_fib[i] = arr_fib[i-2] + arr_fib[i-1];
  }
  
  return arr_fib;
}

class MyTime{
private:
  int second;
  int millisecond;
public:
  MyTime() {
    second = 0;
    millisecond = 0;
  }
  int getSecond(){
    return second;
  }
  
  int getMillisecond(){
    return millisecond;
  }
  
  void setSecond(int _second){
    if(_second >= 0){
      second = _second;
    }
    else {
      // error message
    }
  }
  
  void setMillisecond(int _ms){
    if(_ms < 1000 && _ms > 0){
      millisecond = _ms;
    }
    else {
      // error message
    }
  }
  
  int checkDifference(MyTime t){
    int myMillisecond = second * 1000 + millisecond;
    int tMillisecond = t.second * 1000 + t.millisecond;
    int result = myMillisecond - tMillisecond;
    
    if (result < 0)
      result *= -1;
      
    return result;
  }   
};

int factorial(int n) {
  if(n < 1)
    return 0;
    
  if(n == 1)
    return 1;
    
  return n * factorial(n-1);
}

int main() {
  //int *a = Fibonacci(10);
  
//  for (int i = 0; i < 10; i++)
      //cout << a[i] << "::";
  /*
  MyTime a, b;
  
  a.setSecond(10);
  a.setMillisecond(10);
  
  b.setSecond(20);
  b.setMillisecond(20);
  
  int d = a.checkDifference(b);
  cout << d << endl;*/
  
  cout <<  factorial(6);
  char c;
  cin >> c;
  return 0;   
}
