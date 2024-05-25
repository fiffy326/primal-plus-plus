PROGRAM := primal++
VERSION := 1.0.3

MANPAGE := $(PROGRAM).1

# Install paths
PREFIX    := /usr/local
MANPREFIX := $(PREFIX)/share/man

BUILD_DIR := ./build
SRC_DIRS  := ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS  := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Flags
override MAKEFLAGS   += -j$(shell nproc) -l$(shell nproc)
override CPPFLAGS    += $(INC_FLAGS) -MMD -MP
override COMMONFLAGS += -pipe -march=native -pedantic -Wall -Werror -Wextra -O3
override CXXFLAGS    += $(COMMONFLAGS) -std=c++23
override CFLAGS      += $(COMMONFLAGS) -std=c17
override LDFLAGS     += 

# Tools
CC  := gcc
CXX := g++

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clang:
	$(MAKE) CC=clang CXX=clang++

clang-static:
	$(MAKE) CC=clang CXX=clang++ LDFLAGS=-static

gcc:
	$(MAKE) CC=gcc CXX=g++

gcc-static:
	$(MAKE) CC=gcc CXX=g++ LDFLAGS=-static

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(PROGRAM)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp -f $(PROGRAM) $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < ./man/man1/$(MANPAGE) > $(DESTDIR)$(MANPREFIX)/man1/$(MANPAGE)
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/$(MANPAGE)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(PROGRAM) \
		$(DESTDIR)$(MANPREFIX)/man1/$(MANPAGE)

run: all
	./$(PROGRAM)

benchmark: all
	@if command -v hyperfine > /dev/null 2>&1; then \
		hyperfine --warmup 5 './$(PROGRAM) -c 10000000'; \
	else \
		echo >&2 "Error: Hyperfine is required to run benchmarks"; \
	fi

.PHONY: all clean run benchmark install uninstall clang clang-static gcc gcc-static

-include $(DEPS)
