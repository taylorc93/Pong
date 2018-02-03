# NOTE: This script must be run from the root of the project

mkdir -p build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
make
make install
cd ..