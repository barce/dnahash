# Makefile

all : mdriver driver genperms

mdriver : mdriver.o primer.o hash.o strings.o message.o
	g++ -o mdriver mdriver.o primer.o hash.o strings.o message.o

driver : driver.o primer.o hash.o strings.o
	g++ -o driver driver.o primer.o hash.o strings.o

genperms : genperms.o strings.o
	g++ -o genperms genperms.o strings.o

mdriver.o : mdriver.cc
	g++ -c mdriver.cc

driver.o : driver.cc
	g++ -c driver.cc

message.o : message.cc
	g++ -c message.cc

primer.o : primer.cc
	g++ -c primer.cc

hash.o : hash.cc
	g++ -c hash.cc

genperms.o : genperms.cc
	g++ -O2 -c genperms.cc

strings.o : strings.cc
	g++ -c strings.cc

clean:
	rm -f *.o *.a
	rm -f mdriver driver genperms

dist-files =	dnahash/INSTALL dnahash/Makefile dnahash/README \
	dnahash/LICENSE \
	dnahash/driver.cc dnahash/genperms.cc dnahash/hash.cc dnahash/hash.h \
	dnahash/mdriver.cc dnahash/message.cc dnahash/message.h \
	dnahash/primer.cc dnahash/primer.h dnahash/strings.cc \
	dnahash/strings.h dnahash/4dna

dist:
	(cd ..;tar cvf dnahash.tar $(dist-files) )

