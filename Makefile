all: util.o test_util.o sfml_visualizer.o file_parser.o
	g++ main.cpp \
	bin/util.o \
	bin/sfml_visualizer.o \
	bin/file_parser.o \
	bin/test_util.o \
	-o bin/render2 \
	-lsfml-system -lsfml-window -lsfml-graphics

# main
util.o: src/util.cpp
	g++ -c src/util.cpp -o bin/util.o

sfml_visualizer.o: src/sfml_visualizer.cpp
	g++ -c src/sfml_visualizer.cpp -o bin/sfml_visualizer.o

file_parser.o: src/file_parser.cpp
	g++ -c src/file_parser.cpp -o bin/file_parser.o

# tests
test_util.o: tests/util_test.cpp
	g++ -c tests/util_test.cpp -o bin/test_util.o


clean:
	rm -r bin/*.o bin/render2