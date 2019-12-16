GTEST_DIR = C:\Users\angel\Desktop\UCO\POO\googletest
# Where to find user code.
# USER_DIR = ../samples

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=gnu++11

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = paciente_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: main

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

main: main.o sistema.o paciente.o cita.o tratamiento.o historial.o
	g++ -o main main.o sistema.o paciente.o cita.o tratamiento.o historial.o

main.o: main.cc
	g++ -c -std=gnu++11 main.cc

sistema.o : sistema.cc
	g++ -c -std=gnu++11 sistema.cc

paciente.o: paciente.cc
	g++ -c -std=gnu++11 paciente.cc

cita.o: cita.cc
	g++ -c -std=gnu++11 cita.cc

tratamiento.o: tratamiento.cc
	g++ -c -std=gnu++11 tratamiento.cc

historial.o: historial.cc
	g++ -c -std=gnu++11 historial.cc

paciente_unittest.o: paciente_unittest.cc paciente.cc paciente.h

paciente_unittest: paciente_unittest.o paciente.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

cita_unittest.o: cita_unittest.cc cita.cc cita.h

cita_unittest: cita_unittest.o cita.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
tratamiento_unittest.o: tratamiento_unittest.cc tratamiento.cc tratamiento.h

tratamiento_unittest: tratamiento_unittest.o tratamiento.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

historial_unittest.o: historial_unittest.cc historial.cc historial.h

historial_unittest: historial_unittest.o historial.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@



.PHONY: clean

clean:
	del /Q/S *.o *.bin