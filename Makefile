all: \
bin/main.o \
bin/util.o \
bin/ray_tracer.o \
bin/bsp_tree.o \
bin/file_parser.o \
bin/sfml_visualizer.o \
bin/test_util.o
	g++ -o bin/render2 \
	bin/main.o \
	bin/util.o \
	bin/ray_tracer.o \
	bin/file_parser.o \
	bin/sfml_visualizer.o \
	bin/test_util.o \
	bin/bsp_tree.o \
	-lsfml-system -lsfml-window -lsfml-graphics -lpthread

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o

bin/util.o: src/util.cpp
	g++ -c src/util.cpp -o bin/util.o

bin/sfml_visualizer.o: src/sfml_visualizer.cpp
	g++ -c src/sfml_visualizer.cpp -o bin/sfml_visualizer.o

bin/file_parser.o: src/file_parser.cpp
	g++ -c src/file_parser.cpp -o bin/file_parser.o

bin/bsp_tree.o: src/bsp_tree.cpp
	g++ -c src/bsp_tree.cpp -o bin/bsp_tree.o

bin/ray_tracer.o: src/ray_tracer.cpp
	g++ -c src/ray_tracer.cpp -o bin/ray_tracer.o

# tests
bin/test_util.o: tests/util_test.cpp
	g++ -c tests/util_test.cpp -o bin/test_util.o


clean:
	rm -r bin/*.o