install:
	cmake -S . -B build
	cmake --build build
	cp -rf include/* /usr/include
	cp build/libbefry_engine.a /usr/lib/

uninstall:
	rm -rf /usr/include/befry_engine
	rm /usr/lib/libbefry_engine.a

clean:
	rm -rf build