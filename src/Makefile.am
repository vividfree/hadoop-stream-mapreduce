bin_PROGRAMS = word_count_mapper word_count_reducer
word_count_mapper_SOURCES = word_count_mapper.cc string_split.h string_split.cc check_log.h check_log.cc hadoop_streaming_mapreduce.h hadoop_streaming_mapreduce.cc
word_count_reducer_SOURCES = word_count_reducer.cc check_log.h check_log.cc hadoop_streaming_mapreduce.h hadoop_streaming_mapreduce.cc
lib_LIBRARIES = libhadoop_streaming_mapreduce.a libstring_split.a
libhadoop_streaming_mapreduce_a_SOURCES = check_log.h check_log.cc hadoop_streaming_mapreduce.h hadoop_streaming_mapreduce.cc
libstring_split_a_SOURCES = string_split.h string_split.cc
include_HEADERS = hadoop_streaming_mapreduce.h string_split.h
