lib_LIBRARIES = libhadoop_streaming_mapreduce.a libstring_split.a

libstring_split_a_SOURCES = string_split.h string_split.cc

libhadoop_streaming_mapreduce_a_SOURCES = hadoop_streaming_mapreduce.h hadoop_streaming_mapreduce.cc check_log.h check_log.cc


bin_PROGRAMS = word_count_mapper word_count_reducer

word_count_mapper_SOURCES = word_count_mapper.cc
word_count_mapper_LDADD = libhadoop_streaming_mapreduce.a libstring_split.a

word_count_reducer_SOURCES = word_count_reducer.cc
word_count_reducer_LDADD = libhadoop_streaming_mapreduce.a

include_HEADERS = hadoop_streaming_mapreduce.h string_split.h check_log.h
