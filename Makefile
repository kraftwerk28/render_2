all: bin/main.o bin/file_parser.o bin/sfml_visualizer.o bin/util.o bin/util.o bin/test_util.o
	g++ -o bin/render2 \
	bin/main.o \
	bin/util.o \
	bin/sfml_visualizer.o \
	bin/file_parser.o \
	bin/test_util.o \
	-lsfml-system -lsfml-window -lsfml-graphics -lpthread -lX11

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o

bin/util.o: src/util.cpp
	g++ -c src/util.cpp -o bin/util.o

bin/sfml_visualizer.o: src/sfml_visualizer.cpp
	g++ -c src/sfml_visualizer.cpp -o bin/sfml_visualizer.o

bin/file_parser.o: src/file_parser.cpp
	g++ -c src/file_parser.cpp -o bin/file_parser.o

# tests
bin/test_util.o: tests/util_test.cpp
	g++ -c tests/util_test.cpp -o bin/test_util.o


clean:
	rm -r bin/*.o bin/render2