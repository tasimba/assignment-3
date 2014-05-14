CC=g++ -std=c++11
CFLAGS=-c
LIBS=-lboost_program_options
SOURCES=driver.cpp cmdline_parser.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=assignment3

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) $(LIBS) -o $@
	

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)

run:
	@./exe
