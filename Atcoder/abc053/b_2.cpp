#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char t[200000];
  int i,j;
  cin >> t;
  for(i=0;t[i]!='A';i++);
  for(j=strlen(t);t[j]!='Z';j--);
  cout << j-i+1 << endl;
  return 0;
}
