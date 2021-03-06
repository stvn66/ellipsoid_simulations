DIRINC=include/
DIRSRC=src/
DIRLIB=lib/
DIRTESTS=test/

DIRINC_PTEROS=$(DIRINC)SasPteros/

SYSINSTALLDIR=/usr/local/sasmol_cpp/

#boost on MAC
#DIRINC_BOOST=/usr/local/include/
#DIRLIB_BOOST=/usr/local/lib/

#boost on Entropy
#DIRINC_BOOST=/share/apps/local/boost_1_55_0/
#DIRLIB_BOOST=/share/apps/local/boost_1_55_0/libs/

# boost on Linux
DIRINC_BOOST=/usr/local/lib/
DIRLIB_BOOST=/usr/local/lib/

# need g++ >=4.8
#CC=/share/apps/local/bin/g++
CC=g++
CCFLAGS=-std=c++11 -c -fPIC -w -g -I$(DIRINC) -I$(DIRINC_PTEROS)
LDFLAGS=-std=c++11 -g -w -I$(DIRINC) -I$(DIRINC_BOOST) -I$(DIRINC_PTEROS)
#CCFLAGS=-c -fPIC -w -g -I$(DIRINC) -I$(DIRINC_PTEROS) -stdlib=libstdc++ -stdlib=libc++ -std=c++11
#LDFLAGS=-g -w -I$(DIRINC) -I$(DIRINC_BOOST) -I$(DIRINC_PTEROS) -stdlib=libstdc++ -stdlib=libc++ -std=c++11

SRC=dcdio.cpp sasmol.cpp sasmath.cpp sasop.cpp sascalc.cpp sasio.cpp sassubset.cpp util.cpp
LIB=sasmol
HEADERS=$(addprefix $(DIRINC),$(SRC:.cpp=.h))
SOURCES=$(addprefix $(DIRSRC),$(SRC))
OBJECTS=$(addprefix $(DIRLIB),$(SRC:.cpp=.o))
LIBRARY=$(DIRLIB)lib$(LIB).a

PTEROS_SRC=saspteros.cpp saspteros_parser.cpp
PTEROS_LIB=saspteros
PTEROS_DIRINC=include/SasPteros/
PTEROS_DIRSRC=src/SasPteros/
PTEROS_DIRLIB=$(DIRLIB)
PTEROS_HEADERS=$(addprefix $(PTEROS_DIRINC),$(PTEROS_SRC:.cpp=.h))
PTEROS_SOURCES=$(addprefix $(PTEROS_DIRSRC),$(PTEROS_SRC))
PTEROS_OBJECTS=$(addprefix $(PTEROS_DIRLIB),$(PTEROS_SRC:.cpp=.o))

#all: $(DIRTESTS)test.out $(DIRTESTS)test_pteros.out
all: $(LIBRARY)

$(DIRTESTS)test.out: $(DIRTESTS)test.cpp $(LIBRARY)
	$(CC) $< $(LDFLAGS) -L$(DIRLIB_BOOST) -L$(DIRLIB) -l$(LIB) -lboost_regex-mt -o $@

$(DIRTESTS)test_pteros.out: $(DIRTESTS)test_pteros.cpp $(LIBRARY)
	$(CC) $< $(LDFLAGS) -L$(DIRLIB_BOOST) -L$(DIRLIB) -lboost_regex-mt -l$(LIB) -o $@

$(LIBRARY): $(OBJECTS) $(PTEROS_OBJECTS)
	$(AR) rv  $@ $^

$(OBJECTS): $(DIRLIB)%.o: $(DIRSRC)%.cpp $(DIRINC)%.h
	$(CC) $(CCFLAGS) -I$(DIRINC_BOOST) $< -o $@

$(PTEROS_OBJECTS): $(PTEROS_DIRLIB)%.o: $(PTEROS_DIRSRC)%.cpp $(PTEROS_DIRINC)%.h
	$(CC) $(CCFLAGS) -I$(DIRINC_BOOST) $< -o $@

install: all
	mkdir -p $(SYSINSTALLDIR)
	cp -rf $(DIRINC) $(SYSINSTALLDIR)
	cp -rf $(DIRLIB) $(SYSINSTALLDIR)
	chmod -R o=g $(SYSINSTALLDIR)

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	rm -f $(PTEROS_OBJECTS)
	rm -f $(LIBRARY)
	rm -f $(DIRTESTS)test.out $(DIRTESTS)test_pteros.out
	rm -rf $(SYSINSTALLDIR)
