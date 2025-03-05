install:
	cmake -S . -B build
	cmake --build build -j 4
	cp -rf include/* /usr/include
	cp build/libbg_framework.a /usr/lib/

uninstall:
	rm -rf /usr/include/bg_framework
	rm /usr/lib/libbg_framework.a

clean:
	rm -rf build
