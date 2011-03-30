// Author: yi.wang.2005@gmail.com (Yi Wang)
//
// An example Mapper class.

#include "hadoop_streaming_mapreduce.h"

#include <stdlib.h>
#include <vector>

#include "string_split.h"

using namespace std;

using hadoop_streaming_mapreduce::Mapper;
using hadoop_streaming_mapreduce::ReduceInputIterator;
using hadoop_streaming_mapreduce::Reducer;

class WordCountMapper : public Mapper {
 public:
  virtual void Map(const string& key, const string& value) {
    vector<string> tokens;
    SplitStringUsing(value, " ", &tokens);
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i].size() > 0) {
        Output(tokens[i], "1");
      }
    }
  }
};

int main(int argc, char** argv) {
  WordCountMapper mapper;
  MapWorker(&cin, &mapper);
  return 0;
}
