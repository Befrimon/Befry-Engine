install:
	cmake -S . -B build
	cmake --build build
	mkdir -p /usr/include/befry_engine
	cp include/*.h /usr/include/befry_engine/
	cp build/libbefry_engine.a /usr/lib/

uninstall:
	rm -rf /usr/include/befry_engine
	rm /usr/lib/libbefry_engine.a

clean:
	rm -rf build