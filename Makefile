CC_C		:= gcc
CC_CPP		:= g++
CC_FLAGS	:= -pedantic -Wall -Wextra -Wconversion -fsyntax-only
CC_LIBS		:= -lm

C_FLAGS		:= -std=c99
C			:= $(CC_C) $(CC_FLAGS) $(C_FLAGS)

CPP_FLAGS	:= -std=c++11
CPP			:= $(CC_CPP) $(CC_FLAGS) $(CPP_FLAGS)

FLAGS_DBG	:= -g -Wno-unused-parameter
FLAGS_RLS	:= -DNDEBUG

CMD_PRINT	:= @printf

SRCS_C		:= $(wildcard *.c)
SRCS_CPP	:= $(wildcard *.cpp)
OBJS_C		:= $(patsubst %.c,%.o,$(SRCS_C))
OBJS_CPP	:= $(patsubst %.cpp,%.o,$(SRCS_CPP))

TRGS		:= $(OBJS_C) $(OBJS_CPP)

.PHONY: all
all: debug

.PHONY: release
release: CC_FLAGS += $(FLAGS_RLS)
release: $(TRGS)

.PHONY: debug
debug: CC_FLAGS += $(FLAGS_DBG)
debug: $(TRGS)

.PHONY: test
test:
	$(CMD_PRINT) "\n"

# Units
generic.o: generic.cpp generic.hpp
	$(CPP) -c $<

custom_packets.o: custom_packets.c custom_packets.h
	$(C) -c $<

packet.o: packet.c packet.h
	$(C) -c $<

crc.o: crc.c crc.h
	$(C) -c $<
