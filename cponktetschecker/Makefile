CC=gcc
CFLAGS=-std=c99 -Wall -O0 -static
CLIBS=-lm
PRGNAME=cheguCheck
CFILES=$(shell find . -name '*.c')
HFILES=$(shell find . -name '*.h')
STYLE=astyle --style=1tbs
RUN=valgrind --leak-check=full
DEBUG=gdb --args

ARG1=111010001 # dragon
ARG2=100010111 # reverse dragon
ARG3=110010101 # curly brace left
ARG4=101010011 # curly brace right
ARG5=111101111 # hollow circle
ARG6=111111111 # filled circle
ARG7=100010001 # middle road
ARG8=010000100 # little road left
ARG9=001000010 # little road right
ARG10=111111001 # arrow
ARG11=100111111 # reverse arrow
ARG12=100000001 # nothing

all: build

clean:
	$(STYLE) $(CFILES)
	rm -f *.o
	rm -f $(PRGNAME)

build:
	$(CC) $(CFLAGS) $(CLIBS) -o $(PRGNAME) -Isrc $(CFILES)

debug:
	$(CC) $(CFLAGS) -g $(CLIBS) -o $(PRGNAME) -Isrc $(CFILES)

run_debug:
	$(DEBUG) ./$(PRGNAME) $(ARGS)

run:
	@echo "************  Testing ************"
	@echo "[Testing] Drache"
	./$(PRGNAME) $(ARG1)
	@echo "**********************************"
	@echo "[Testing] Vercherta Drache"
	./$(PRGNAME) $(ARG2)
	@echo "**********************************"
	@echo "[Testing] Linggi Gschweifti Chlammera"
	./$(PRGNAME) $(ARG3)
	@echo "**********************************"
	@echo "[Testing] Rächti Gschweifti Chlammera"
	./$(PRGNAME) $(ARG4)
	@echo "**********************************"
	@echo "[Testing] Chranz"
	./$(PRGNAME) $(ARG5)
	@echo "**********************************"
	@echo "[Testing] Babeli"
	./$(PRGNAME) $(ARG6)
	@echo "**********************************"
	@echo "[Testing] Grossi Strass"
	./$(PRGNAME) $(ARG7)
	@echo "**********************************"
	@echo "[Testing] Chliini Linggi Strass"
	./$(PRGNAME) $(ARG8)
	@echo "**********************************"
	@echo "[Testing] Chliini Rächti Strass"
	./$(PRGNAME) $(ARG9)
	@echo "**********************************"
	@echo "[Testing] Pfüû"
	./$(PRGNAME) $(ARG10)
	@echo "**********************************"
	@echo "[Testing] Vercherta Pfüû"
	./$(PRGNAME) $(ARG11)
	@echo "************  End Testing ************"
	@echo "[Testing] Nüüüt"
	./$(PRGNAME) $(ARG12)
	@echo "************  End Testing ************"

memtest:
	$(RUN) ./$(PRGNAME) $(ARGS)
