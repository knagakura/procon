#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, mean;
  cin >> N;
  mean = 0;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i)
  {
  	cin >> a.at(i);
  	mean += a.at(i);
  	//cout << mean << endl;
  }
  mean /= N;
  //cout << mean << endl;

  for (int i = 0; i < N; ++i){
  	cout << abs(a.at(i) - mean) << endl;
  }
}
