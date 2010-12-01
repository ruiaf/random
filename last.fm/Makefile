all:
	cd src; make
	cd unit-tests; make
	cd unit-tests; ./run.sh
	cd docs; doxygen generic_containers.config


clean:
	cd src; make clean
	cd unit-tests; make clean
