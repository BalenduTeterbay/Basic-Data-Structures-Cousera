#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

/*********************************
******                      ******
***        Ayran Olckers       ***
**                              **
**            07/2019           **
******                      ******
**********************************/

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps;

  void WriteResponse() const {
    cout << swaps.size() << "\n";
    for (int i = 0; i < swaps.size(); ++i) {
      cout << swaps[i].first << " " << swaps[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  
  void minheapify(int i){
    int smallest = i;
    int l = 2*i+1;
    if(l <= data_.size()-1 && data_[l] < data_[smallest])
      smallest = l;
    int r = 2*i+2;
    if(r <= data_.size()-1 && data_[r] < data_[smallest])
      smallest = r;
    if(i != smallest){
      swap(data_[i], data_[smallest]);
      swaps.push_back(make_pair(i, smallest));
      minheapify(smallest);
    }
  }

  void GenerateSwaps() {
    swaps.clear();

      int n = data_.size();
      //cout << " size : " << n << endl;
      for(int i =(n/2)-1;i>=0;i--){
        minheapify(i);
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}