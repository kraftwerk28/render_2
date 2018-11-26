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

bin/main.o: main.cc
	g++ -c main.cc -o bin/main.o

bin/util.o: src/util.cc
	g++ -c src/util.cc -o bin/util.o

bin/sfml_visualizer.o: src/sfml_visualizer.cc
	g++ -c src/sfml_visualizer.cc -o bin/sfml_visualizer.o

bin/file_parser.o: src/file_parser.cc
	g++ -c src/file_parser.cc -o bin/file_parser.o

bin/bsp_tree.o: src/bsp_tree.cc
	g++ -c src/bsp_tree.cc -o bin/bsp_tree.o

bin/ray_tracer.o: src/ray_tracer.cc
	g++ -c src/ray_tracer.cc -o bin/ray_tracer.o

# tests
bin/test_util.o: tests/util_test.cc
	g++ -c tests/util_test.cc -o bin/test_util.o


clean:
	rm -r bin/*.o