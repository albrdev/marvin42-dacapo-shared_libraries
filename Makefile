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

DIR_INC		:= inc
DIR_SRC		:= src

SRCS_C		:= $(wildcard $(DIR_SRC)/*.c)
SRCS_CPP	:= $(wildcard $(DIR_SRC)/*.cpp)
OBJS_C		:= $(patsubst $(DIR_SRC)/%.c,%.o,$(SRCS_C))
OBJS_CPP	:= $(patsubst $(DIR_SRC)/%.cpp,%.o,$(SRCS_CPP))

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
generic.o: $(DIR_SRC)/generic.cpp $(DIR_INC)/generic.hpp
	$(CPP) -I$(DIR_INC) -c $<

custom_packets.o: $(DIR_SRC)/custom_packets.c $(DIR_INC)/custom_packets.h $(DIR_INC)/packet.h
	$(C) -I$(DIR_INC) -c $<

packet.o: $(DIR_SRC)/packet.c $(DIR_INC)/packet.h
	$(C) -I$(DIR_INC) -c $<

crc.o: $(DIR_SRC)/crc.c $(DIR_INC)/crc.h
	$(C) -I$(DIR_INC) -c $<
