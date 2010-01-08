// Author: yi.wang.2005@gmail.com (Yi Wang)

#include "string_split.h"

// NOTE(lar): we have to implement our own interator because
// insert_iterator<set<string> > does not instantiate without
// errors, perhaps since string != std::string.
// This is not a fully functional iterator, but is
// sufficient for SplitStringToIteratorUsing().
template <typename T>
struct simple_insert_iterator {
  T* t_;
  simple_insert_iterator(T* t) : t_(t) { }

  simple_insert_iterator<T>& operator=(const typename T::value_type& value) {
    t_->insert(value);
    return *this;
  }

  simple_insert_iterator<T>& operator*()     { return *this; }
  simple_insert_iterator<T>& operator++()    { return *this; }
  simple_insert_iterator<T>& operator++(int) { return *this; }
};

// If we know how much to allocate for a vector of strings, we can
// allocate the vector<string> only once and directly to the right size.
// This saves in between 33-66 % of memory space needed for the result,
// and runs faster in the microbenchmarks.
//
// The reserve is only implemented for the single character delim.
//
// The implementation for counting is cut-and-pasted from
// SplitStringToIteratorUsing. I could have written my own counting iterator,
// and use the existing template function, but probably this is more clear
// and more sure to get optimized to reasonable code.
static int CalculateReserveForVector(const string& full, const char* delim) {
  int count = 0;
  if (delim[0] != '\0' && delim[1] == '\0') {
    // Optimize the common case where delim is a single character.
    char c = delim[0];
    const char* p = full.data();
    const char* end = p + full.size();
    while (p != end) {
      if (*p == c) {  // This could be optimized with hasless(v,1) trick.
        ++p;
      } else {
        while (++p != end && *p != c) {
          // Skip to the next occurence of the delimiter.
        }
        ++count;
      }
    }
  }
  return count;
}

// ----------------------------------------------------------------------
// SplitStringUsing()
// SplitStringToHashsetUsing()
// SplitStringToSetUsing()
// SplitStringToHashmapUsing()
//    Split a string using a character delimiter. Append the components
//    to 'result'.
//
// Note: For multi-character delimiters, this routine will split on *ANY* of
// the characters in the string, not the entire string as a single delimiter.
// ----------------------------------------------------------------------
template <typename StringType, typename ITR>
static inline
void SplitStringToIteratorUsing(const StringType& full,
                                const char* delim,
                                ITR& result) {
  // Optimize the common case where delim is a single character.
  if (delim[0] != '\0' && delim[1] == '\0') {
    char c = delim[0];
    const char* p = full.data();
    const char* end = p + full.size();
    while (p != end) {
      if (*p == c) {
        ++p;
      } else {
        const char* start = p;
        while (++p != end && *p != c) {
          // Skip to the next occurence of the delimiter.
        }
        *result++ = StringType(start, p - start);
      }
    }
    return;
  }

  string::size_type begin_index, end_index;
  begin_index = full.find_first_not_of(delim);
  while (begin_index != string::npos) {
    end_index = full.find_first_of(delim, begin_index);
    if (end_index == string::npos) {
      *result++ = full.substr(begin_index);
      return;
    }
    *result++ = full.substr(begin_index, (end_index - begin_index));
    begin_index = full.find_first_not_of(delim, end_index);
  }
}

void SplitStringUsing(const string& full,
                      const char* delim,
                      vector<string>* result) {
  result->reserve(CalculateReserveForVector(full, delim));
  back_insert_iterator< vector<string> > it(*result);
  SplitStringToIteratorUsing(full, delim, it);
}

void SplitStringToSetUsing(const string& full, const char* delim,
                           set<string>* result) {
  simple_insert_iterator<set<string> > it(result);
  SplitStringToIteratorUsing(full, delim, it);
}
