# Simple Constraint Solver
## Steps to Clone and Build


### Install Dependencies
You will need to install the following dependencies and CMake will need to be able to locate them (ie. they need to be listed on your PATH):

    1. SDL2
    2. SDL2_image
    3. Boost (make sure to build the optional dependencies)

### Build and Run
From the root directory of the project, run the following commands:

```
mkdir build
cd build
cmake ..
cmake --build .
```

If these steps are successful, a Visual Studio solution will be generated in ```build```. You can open this project with Visual Studio and then run the ```scs-2d-demo``` project. If you encounter an error telling you that you're missing DLLs, you will have to copy those DLLs to your EXE's directory.
