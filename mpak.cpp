#include "mpak.hpp"

MPAK::MPAK() {
	buffer = NULL;
	size = 0;
	count = 0;
}

MPAK::~MPAK() {
	//Just so I don't have to deal with it myself...
	if (buffer != NULL)
		free(buffer);
}

bool MPAK::open(const char *fname) {
	FILE *fp;

	//Read
	fp = fopen(fname, "rb");

	uint32_t header_chk = 0;

	//Header Check
	fread(&header_chk, sizeof(uint32_t), 1, fp);

	if (header_chk != 0x4B41504D) {
		//Header Check failed. Close and get out.
		fclose(fp);
		return false;
	}

	//Get the file size
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	//Read the buffer in
	buffer = (byte*) malloc(sizeof(byte) * size);
	fread(buffer, sizeof(byte), size, fp);

	//We are done here
	fclose(fp);

	return true;
}

void MPAK::process() {
	//0x08 has the number of files
	count = *reinterpret_cast<uint32_t*>(&buffer[0x08]);
	files.resize(count);
	uint32_t pos;

	//Skip to the files...
	for (int i = 0; i < count; i++) {
		/*
		 * Each file is distinguished with 12 bytes:
		 *   - Offset
		 *   - Size
		 *   - Unknown
		 *
		 * So we can just memcpy it in. Easy.
		 */

		memcpy(&files[i].offset, &buffer[0x10 + (0x0C * i)], 0x0C);
	}

	//Set the position to the names
	pos = 0x10 + (0x0C * count);

	debug_hex_dump(&buffer[pos], 32);

	//Read strings
	for (int i = 0; i < count; i++) {
		//Get the name and length.
		//We can cheat and just use the buffer itself.
		files[i].name     =        (const char *) &buffer[pos];
		files[i].name_len = strlen((const char *) &buffer[pos]);

		pos += files[i].name_len + 1;
	}
}

/*
 * debug_hex_dump
 *
 * Debug function to dump hex at a certain spot (just to see where
 * we are at).
 */

void MPAK::debug_hex_dump(byte* b, size_t s) {
	for (int i = 0; i < s; i++) {
		printf(
			"%02x%c",
			b[i],
			((i + 1) % 16 == 0 || i == s - 1)
				? '\n'
				: ' '
		);
	}
}