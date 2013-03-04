polyran
=====

Overview
--------

Robustly fit a N-th order polynomial to a 1D signal, using RANSAC.

Requirements
------------

- Boost library (version 1.49 and higher), download from http://www.boost.org
- Eigen3, download from http://eigen.tuxfamily.org

Compilation
-----------

To compile, set the 'BOOST_ROOT' environment variable to the path where you installed
Boost, e.g., /software/boost/, using

``` bash
export BOOST_ROOT=/software/boost/
```

This should help cmake to do its job. Assuming that you checked
out the code under /tmp/polyran, create a 'Build' directory, run 
'cmake' and then 'make' to compile the code.

``` bash
$ cd /tmp/polyran
$ mkdir Build
$ cd Build
$ cmake ..
$ make
```

Testing
-------
To test the code, go to the test directory and run (assuming you built under 'Build')

``` bash
$ ../Build/src/fit x.bin y.bin
```
which will estimate a 2-nd degree polynomial to the data in (x.bin, y.bin)
and evaluate this polynomial at the positions in x.bin.
