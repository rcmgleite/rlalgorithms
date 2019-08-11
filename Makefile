.DEFAULT_GOAL := test

mkdir_build:
	mkdir -p build

run_cmake: configure
	cd build && cmake .. && cd -

build_tests: 
	cd build && $(MAKE) unit_tests && cd -

run_tests:
	./build/unit_tests

run_tests_valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./build/unit_tests

configure:
	git submodule init && git submodule update

test: mkdir_build run_cmake build_tests run_tests

test_valgrind: mkdir_build run_cmake build_tests run_tests_valgrind

clean:
	$(RM) -r build

.PHONY: mkdir_build run_cmake build_tests run_tests run_tests_valgrind test test_valgrind clean
