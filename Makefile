VERSION := 1.0.3

PROGRAM := primal
MANPAGE := $(PROGRAM).1

PREFIX := /usr/local
MANPREFIX := $(PREFIX)/share/man

BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LDFLAGS := 
CPPFLAGS := $(INC_FLAGS) -MMD -MP
CXXFLAGS := -pipe -march=native -std=c++23 -pedantic -Wall -Werror -Wextra -Ofast
CFLAGS := -pipe -march=native -std=c17 -pedantic -Wall -Werror -Wextra -Ofast

CC := clang
CXX := clang++

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
	make CC=clang CXX=clang++

clang-static:
	make CC=clang CXX=clang++ LDFLAGS=-static

gcc:
	make CC=gcc CXX=g++

gcc-static:
	make CC=gcc CXX=g++ LDFLAGS=-static

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(PROGRAM)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(PROGRAM) $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < ./man/man1/$(MANPAGE) > $(DESTDIR)$(MANPREFIX)/man1/$(MANPAGE)
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/$(MANPAGE)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(PROGRAM) \
		$(DESTDIR)$(MANPREFIX)/man1/$(MANPAGE)

run:
	$(PROGRAM)

.PHONY: all clean run install uninstall clang clang-static gcc gcc-static

-include $(DEPS)
