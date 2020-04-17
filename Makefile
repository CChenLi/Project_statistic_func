CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES= stattest

COMMON_OBJECT_FILES = stats.o

all: ${BINARIES}

tests: ${BINARIES}
	./stattest

stattest: stattest.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
