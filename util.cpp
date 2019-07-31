#include "util.hpp"

namespace util {
	size_t file_size(char* fname) {
		size_t pos;
		FILE* fp = fopen(fname, "rb");
		fseek(fp, 0, SEEK_END);
		pos = ftell(fp);
		fclose(fp);

		return pos;
	}

	/*
	 * directory_create
	 *
	 * Cross-platform (probably) function to make a directory. Returns TRUE on
	 * success. Returns FALSE if the directory already exists.
	 */

	bool directory_create(const char* name) {
		/*
		 * WINDOWS
		 *
		 * We can rely on the Windows API.
		 */
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			CreateDirectory(name, NULL);
			return (GetLastError() != ERROR_ALREADY_EXISTS);
		#else
			//Assume a POSIX system
			//TODO: Do this??
		#endif
	}
}