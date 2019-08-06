CC     = g++
CFLAGS = --std=c++98

all: mpk_extract

mpk_extract: main.cpp mpak.cpp util.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) mpk_extract
