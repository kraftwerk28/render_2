all: util.o test_util.o
	g++ main.cpp bin/test_util.o bin/util.o -o bin/render2

util.o: src/util.cpp
	g++ -c src/util.cpp -o bin/util.o

test_util.o: tests/util_test.cpp
	g++ -c tests/util_test.cpp -o bin/test_util.o

clean:
	rm -r bin/*.o bin/render2