// Author: yi.wang.2005@gmail.com (Yi Wang)
//
// An example Reducer class.

#include "hadoop_streaming_mapreduce.h"

#include <stdlib.h>
#include <sstream>

using namespace std;

using hadoop_streaming_mapreduce::Mapper;
using hadoop_streaming_mapreduce::ReduceInputIterator;
using hadoop_streaming_mapreduce::Reducer;

class WordCountReducer : public Reducer {
 public:
  virtual void Reduce(ReduceInputIterator* inputs) {
    int sum = 0;
    for (; !inputs->Done(); inputs->Next()) {
      sum += atoi(inputs->value().c_str());
    }
    stringstream ss;
    ss << sum;
    Output(inputs->key(), ss.str());
  }
};

int main(int argc, char* argv) {
  WordCountReducer reducer;
  ReduceWorker(&cin, &reducer);
  return 0;
}
