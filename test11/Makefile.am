####### kdevelop will overwrite this part!!! (begin)##########
EXTRA_DIST = ../test/driver.h peg11.cpp peg11.h Makefile.am
####### kdevelop will overwrite this part!!! (end)############
AUTOMAKE_OPTIONS = foreign
noinst_PROGRAMS = test11

# set the include path found by configure
AM_CPPFLAGS = $(all_includes)
# the library search path.
LDFLAGS = $(all_libraries)
test11_LDFLAGS = $(LDFLAGS)

test11_SOURCES = peg11.cpp
test11_LDADD = $(LDADD)
test11_DEPENDENCIES = ../test/driver.h peg11.h
