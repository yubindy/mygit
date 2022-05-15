num1="b"
num2="m"
if test $1 = $num1
then
    mkdir build && cd ./build
    cmake ..
    make
    #rm -f ./
    #mv ./$2 ../
    #cd ../
    #rm -rf ./build
else
    touch CMakeLists.txt
    echo "project(examples CXX) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -O2\")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -pthread")
link_libraries(-pthread)
SET(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS} -g)
set( CMAKE_BUILD_TYPE "Debug" )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)  #确定引入文件的工作目录
find_package(spdlog REQUIRED)

add_executable(example example.cpp) 
target_link_libraries(example PRIVATE spdlog::spdlog)" >> CMakeLists.txt
fi