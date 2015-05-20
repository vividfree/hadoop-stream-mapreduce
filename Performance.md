# Introduction #

The following experiment shows that hadoop-stream-mapreduce is about 30% slower than native Hadoop Java mode.

# Experiment #

I setup a single node Hadoop cluster on my MacBook Pro following the steps explained by

http://www.michael-noll.com/wiki/Running_Hadoop_On_Ubuntu_Linux_%28Single-Node_Cluster%29

I downloaded three ebooks as suggested in above essay as the testing data.
Then I ran the standard Hadoop example, WordCount, for two times using native Hadoop; and then ran the word\_count\_mapper/reducer delivered with hadoop-stream-mapreduce for two times.

Two runs of WordCount cost 44sec and 37sec respectively, whereas two runs of hadoop-stream-mapreduce cost 56sec and 48sec.