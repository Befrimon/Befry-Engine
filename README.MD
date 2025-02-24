# Befry Engine
*Open-source C++ framework for text-based games*

Befry Engine is ~~cross-platform~~ framework for building text-based games on C++. It works on Linux and ~~Windows~~ (in-dev)

## Installation
**Requirements:**
* C++17 compatible compiler
* Cmake 3.14 or higher

Clone the repo from GitHub:
```
git clone https://github.com/Befrimon/Befry-Engine.git
```
Build library with make
```
cd Befry-Engine
sudo make install
```
## How to use
**Simple example**
```C++
#include <befry_engine/scene.h>

int main() {
    befry::Scene scn({80, 40});  // Create scene with size 80x40
    
    return 0;
}
```
**Build your game**
```
g++ <game>.cpp -o <game> -lbefry_engine
```