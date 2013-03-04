/*
 * Copyright 2012 Stefan Huber
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

#ifndef LOGGING_H
#define LOGGING_H

#include <string>

enum loglevel {
	DEBUG,
	INFO,
	GOODNEWS,
	WARNING,
	ERROR,
	SILENCE
};


class logging 
{

	private:

		bool lastrelog;
		loglevel minLevel;
		bool useColor;

		unsigned cntErrors;
		unsigned cntWarnings;

    public:

		// Create a new logging 
		logging();

		// Set new log level 
		void setLevel(loglevel level)	{ minLevel = level; };

		// Use color or not? 
		void setUsecolor(bool useColor)	{ this->useColor = useColor; };

		// Get number of warnings 
		unsigned getNoWarnings() const	{ return cntWarnings; };

		// Get number of errors 
		unsigned getNoErrors() const	{ return cntErrors; };

		// Log a new message in well-known printf manner  
		void log(loglevel level, const char* fmt, ... );

		// Log a new message  
		void log(loglevel level, std::string& str);

		// Like log(), but overwrite the last line
		void relog(loglevel level, const char* fmt, ... );

	private:

		// Check if we print in this level 
		bool doPrint(loglevel level) const;
};
#endif


