
---------------------------------------------- Compiler ----------------------------------------------

export GCC_VERSION=14.2
export UTILS_PATH=/home/andtokm/DiskS/Utils
export GCC_PATH=${UTILS_PATH}/bin/gcc-$GCC_VERSION

export LD_LIBRARY_PATH=${GCC_PATH}/lib64
export CC=gcc-$GCC_VERSION CXX=g++-$GCC_VERSION

# export PATH=${GCC_PATH}/bin:${UTILS_PATH}/cmake/cmake-3.29.5/bin/:${PATH}
export PATH=${GCC_PATH}/bin:${UTILS_PATH}/cmake/cmake-3.30/bin/:${PATH}

---------------------------------------------- Cmake config -----------------------------------------

cmake -DCMAKE_BUILD_TYPE=Release -B./build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc-14.2 -DCMAKE_CXX_COMPILER=g++-14.2 -DCMAKE_CXX_STANDARD=23 -B./build


---------------------------------------------- simdjson ----------------------------------------------

git clone https://github.com/simdjson/simdjson.git