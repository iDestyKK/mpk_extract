#ifndef __MPAK_HELPER_HPP__
#define __MPAK_HELPER_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <vector>
#include <set>
#include <string>

#include "util.hpp"

using namespace std;

typedef unsigned char byte;

class MPAK {
	public:
		struct DATA {
			uint32_t offset;
			uint32_t size;
			uint32_t unknown;

			const char *name;
			size_t name_len;
		};

		MPAK();
		~MPAK();

		bool open(const char *);
		void process();
		void dump(const string = "");

	private:
		//Files
		uint32_t count;
		vector<DATA> files;
		set<string> directories;

		//File Buffer
		long size;
		byte* buffer;

		//Debug Function to dump hex
		void debug_hex_dump(byte *, size_t);
};

#endif