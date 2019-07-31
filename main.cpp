/*
 * Spy Hunter (PS2) MPK/MPAK Extractor
 *
 * Description:
 *     On the PS2 disc, there is a file in the DATA directory named "AUDIO.MPK"
 *     which contains around 144 MB of data. This tool extracts all data from
 *     this file.
 *
 * Author:
 *     Clara Nguyen (@iDestyKK)
 */

//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//C++
#include <vector>
#include <map>

//Magic stuff
#include "mpak.hpp"

using namespace std;

int main(int argc, char **argv) {
	//Argument Check
	if (argc != 2) {
		fprintf(stderr, "Usage: %s file.mpk\n", argv[0]);
		return 1;
	}

	FILE *fp;
	MPAK  pak;

	//Open up the MPAK file
	if (!pak.open(argv[1])) {
		fprintf(stderr, "[FATAL] Not a valid MPK/MPAK file!\n");
		return 2;
	}

	//Now then...
	pak.process();
}