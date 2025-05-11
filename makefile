CXX = g++
CXXFLAGS = -Wall

driver: driver.cpp TextEditor.o Document.o Line.o
        $(CXX) $(CXXFLAGS) driver.cpp TextEditor.o Document.o Line.o -o driver

TextEditor.o: TextEditor.h TextEditor.cpp Document.o Line.o
        $(CXX) $(CXXFLAGS) -c TextEditor.cpp

Document.o: Document.h Document.cpp Line.o
        $(CXX) $(CXXFLAGS) -c Document.cpp

Line.o: Line.h Line.cpp
        $(CXX) $(CXXFLAGS) -c Line.cpp

val:
        valgrind ./driver

run:
        ./driver

clean:
        rm *~
