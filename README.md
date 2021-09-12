## Build instruction

cd sdk-demo
mkdir build
cd build
conan install .. --build=missing
cmake ..
make
