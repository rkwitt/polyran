/*
 * Copyright 2012 Roland Kwitt
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *    http:www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include <fstream>
#include <vector>
#include <iostream>
#include <Eigen/Dense>

#include "io.h"
#include "polyfit.h"

using namespace std;
using namespace Eigen;

logging logger;

int main(int argc, char **argv) 
{
  // Sets the log level to DEBUG
  logger.setLevel(ERROR);

  try 
  {
    // Create (sample, signal) vectors
    std::vector<double> x,y;

    // Read in (sample, signal) = (x,y) values
    IO::readData<double>(argv[1],x);
    IO::readData<double>(argv[2],y);

    // Create options for fitting
    PolyFit<double>::Options options;

    options.polyDeg = 3; // 3-rd degree polynomial
    options.solver = PolyFit<double>::EIGEN_JACOBI_SVD; // SVD solver
    options.maxMPts = 10; // #Pts to use for fitting
    options.maxTrial = 500; // Max. nr. of trials
    options.tolerance = 0.001; // Distance tolerance for inlier

    // Create fitting object
    PolyFit<double>f(x,y,options);

    // Solve using RANSAC 
    f.solveRLS();

    // Output result
    //cout << f << endl;
    
    std::vector<double> r = f.evalPoly(x);
    std::vector<double>::iterator it = r.begin();
    while (it != r.end())
    {
      std::cout << *it << std::endl;
      ++it;
    }
  



  }
  catch (exception &e)
  {
    logger.log(ERROR, "[%s]: Exiting ...\n",
        __func__);
    exit(EXIT_FAILURE);
  }
  return 0;

}
