#ifndef __UTIL_HPP__
#define __UTIL_HPP__

/* 
 * Slightly stolen from: https://github.com/iDestyKK/handy/blob/dev/c/c/file.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <unistd.h> */
#include <sys/stat.h>

//Include OS-specific stuff
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#include <Windows.h>
#else
	//lol watch this
	#include <string>
#endif

using namespace std;

namespace util {
	//From HandyC/C++
	size_t file_size(char*);

	//New (and cool) stuff
	bool directory_create(const char *);
}

#endif
