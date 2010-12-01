all:
	cd src; make
	cd unit-tests; make
	cd unit-tests; ./run.sh

docs: force_look
	cd docs; doxygen generic_containers.config

clean:
	cd src; make clean
	cd unit-tests; make clean

force_look:
	true
