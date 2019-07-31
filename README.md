# MPK Extract

## Synopsis
MPK (MPAK) is a simple package container that holds files. It offers no
compression, and is fairly simple to read in a Hex Editor without figuring
out what all of the values are.

## File Format
MPKs are split into 4 "sections":

* Header
* Offsets
* File Names
* File Data

\[0x0000 - 0x000F\] Header (16 bytes):
```
Byte[4] - Always "MPAK"
Byte[4] - Unknown
Byte[4] - Number of files
Byte[4] - Unknown
```

\[0x0010-??\] Offsets (12 bytes \* File Number):
```
For each file:
  struct {
    uint32_t offset
    uint32_t size
    uint32_t unknown
  }
```

\[??-??\] File Names (Variable size. Determined by length of all file names):
```
For each file:
  Byte[?] - File Name (Null-Terminated String ending with "0x00")
```

\[??-END\] File Data (Variable size. Start is determined by address at 0x0010):
```
For each file:
  Byte[?] - File Data (Raw bytes. Offset and size are determined by struct in "Offsets")
```

## What works
This program was only tested on the PS2 USA release of "Spy Hunter". If there
is a game out there that also uses MPK and this tool doesn't extract it, contact
me. I'll be glad to improve on this.
