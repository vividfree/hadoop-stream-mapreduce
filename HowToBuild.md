Thanks to Gay Jean-Christophe for details in this page.

You can checkout and build using the following commands:
  1. `svn checkout http://hadoop-stream-mapreduce.googlecode.com/svn/trunk/ local-mapreduce-hadoop-stream`
  1. `cd local-mapreduce-hadoop-stream`
  1. `autoreconf --install`
  1. `./configure`
  1. `make`
  1. `make install`

If you want more control over the process, here is an equivalent sequence:
  1. `svn checkout http://hadoop-stream-mapreduce.googlecode.com/svn/trunk/ local-mapreduce-hadoop-stream`
  1. `cd local-mapreduce-hadoop-stream`
  1. `autoheader`
  1. `aclocal`
  1. `autoconf`
  1. `touch ./NEWS ./README ./AUTHORS ./ChangeLog`
  1. `automake --add-missing`
  1. `./configure`
  1. `make`
  1. `make install`