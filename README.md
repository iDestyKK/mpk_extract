# MPK Extract

## Synopsis
MPK (MPAK) is a simple package container that holds files. It offers no
compression, and is fairly simple to read in a Hex Editor without figuring
out what all of the values are.

## Usage
```
./mpk_extract mpk_file [directory]
```

If `directory` isn't specified, it will try to make a directory named
`extract` and dump the files there.

## Compilation
### Windows (Method 1)
1. Make a new project
2. Drag all files in
3. Add `_CRT_SECURE_NO_WARNINGS` to your **Preprocessor Definitions**.
4. Compile!

### Windows (Method 2)
1. Go into the `bin` directory. I'm a nice person, so I compiled it for you.

### Linux/Mac OS/etc
1. Run `make`. Simple.

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
