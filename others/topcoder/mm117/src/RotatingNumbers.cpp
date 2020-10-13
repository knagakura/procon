// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class RotatingNumbers {
public:
  vector<string> findSolution(int N, int P, vector<int> grid)
  {           
    vector<string> out;
    return out;
  }
};

int main() {
  RotatingNumbers prog;
  int N;
  int P;
  int num;
  vector<int> grid;

  cin >> N;
  cin >> P;
  for (int i=0; i<N*N; i++)
  {
    cin >> num;
    grid.push_back(num);
  }
  
  vector<string> ret = prog.findSolution(N,P,grid);
  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i)
      cout << ret[i] << endl;
  cout.flush();
}