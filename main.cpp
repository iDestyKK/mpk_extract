/*
 * MPK/MPAK Extractor
 *
 * Description:
 *     Extracts MPK/MPAK files.
 *
 *     This was only tested on "AUDIO.MPK" from a PS2 copy of "Spy Hunter".
 *     Let me know if there are other files out there like this that can't
 *     be extracted via this.
 *
 * Author:
 *     Clara Nguyen (@iDestyKK)
 */

#include <stdio.h>

//Magic stuff
#include "mpak.hpp"

using namespace std;

int main(int argc, char **argv) {
	//Argument Check
	if (argc < 2 || argc > 3) {
		fprintf(stderr, "Usage: %s file.mpk [directory]\n", argv[0]);
		return 1;
	}

	MPAK pak;

	//Open up the MPAK file
	if (!pak.open(argv[1])) {
		fprintf(stderr, "[FATAL] Not a valid MPK/MPAK file!\n");
		return 2;
	}

	//Now then...
	pak.process();

	if (argc == 2)
		pak.dump("extract");
	else
		pak.dump(string(argv[2]));
}