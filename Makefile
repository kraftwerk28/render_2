all: bin/main.o bin/file_parser.o bin/sfml_visualizer.o bin/util.o bin/util.o bin/test_util.o
	g++ -o bin/render2 \
	bin/main.o \
	bin/util.o \
	bin/sfml_visualizer.o \
	bin/file_parser.o \
	bin/test_util.o \
	-lsfml-system -lsfml-window -lsfml-graphics -lpthread -lX11

bin/main.o: main.cc
	g++ -c main.cc -o bin/main.o

bin/util.o: src/util.cc
	g++ -c src/util.cc -o bin/util.o

bin/sfml_visualizer.o: src/sfml_visualizer.cc
	g++ -c src/sfml_visualizer.cc -o bin/sfml_visualizer.o

bin/file_parser.o: src/file_parser.cc
	g++ -c src/file_parser.cc -o bin/file_parser.o

# tests
bin/test_util.o: tests/util_test.cc
	g++ -c tests/util_test.cc -o bin/test_util.o


clean:
	rm -r bin/*.o bin/render2