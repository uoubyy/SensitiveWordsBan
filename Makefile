main:main.cpp WordFilter.o WordTree.o WordNode.o
	g++ -o main main.cpp WordFilter.o WordTree.o WordNode.o
WordNode.o:WordNode.cpp
	g++ -c -o WordNode.o WordNode.cpp
WordTree.o:WordTree.cpp
	g++ -c -o WordTree.o WordTree.cpp
WordFilter.o:WordFilter.cpp
	g++ -c -o WordFilter.o WordFilter.cpp
clean:
	rm -f main *.o
