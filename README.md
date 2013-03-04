polyran
=======

Robust polynomial fitting using RANSAC

Requirements:

- Boost ( > 1.49)
- Eigen3

Compilation:

To compile, set the BOOST_ROOT to the path where you installed
Boost, e.g., /software/boost/, using

export BOOST_ROOT=/software/boost/

This should help cmake to do its job. Assuming that you checked
out the code under /tmp/polyran, create a 'Build' directory, run 
cmake and then 'make' to compile the code.

$ cd /tmp/polyran
$ mkdir Build
$ cd Build
$ cmake ..
$ make

See the README file under 'test' for example data and how to 
run polynomial RANSAC fitting.
