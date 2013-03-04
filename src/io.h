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

#ifndef IO_H
#define IO_H

#include <vector>
#include "logging.h"

extern logging logger;

class IO
{
  public:

    template <typename T>
    static void readData(const char *file, std::vector<T> &data) 
    {
      if (!file)
      {
        logger.log(ERROR, "[%s]: Filename missing\n",
            __func__);
        throw std::exception();
      }
      
      std::ifstream iFile (file, std::ios::in | std::ios::binary);
   
      if (!iFile.is_open()) 
      {
        logger.log(ERROR, "[%s]: Could not open %s\n", 
          __func__, file);
        throw std::exception();
      }
  
      iFile.seekg(0, std::ios::end);
      size_t fileSize = iFile.tellg();
      int N = fileSize/sizeof(T);

      iFile.seekg(0, std::ios::beg);

      data.resize(N);
      for (int i=0;i<N; i++) 
      {
        T val = 0;
        iFile.read((char *)&val,sizeof(T));
        data[i] = val;
      }
      
      logger.log(INFO, "[%s]: Loaded %d elements\n", 
          __func__, N);

      iFile.close();
      if (iFile.fail())
      {
        logger.log(ERROR, "[%s]: Closing %s failed\n",
            __func__,file);
        throw std::exception();
      }

    }
};

#endif
