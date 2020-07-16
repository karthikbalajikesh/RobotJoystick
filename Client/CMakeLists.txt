cmake_minimum_required(VERSION 3.5.1)

#####################################
project(JoyStickClient)

###### Libraries #####################
# 1. Threads - Boost Asio dependency
find_package(Threads REQUIRED)

# 2. Boost Asio(System) amd Serial
set(BOOSTPATH "/home/karthik/Downloads/boost_1_73_0/stage/lib/cmake")
set(BOOST_INCLUDE_DIR "/home/karthik/Downloads/boost_1_73_0")
set(BOOST_LIBRARY_DIR "/home/karthik/Downloads/boost_1_73_0/stage/lib")
set(CMAKE_PREFIX_PATH "${BOOSTPATH};${CMAKE_PREFIX_PATH}")
find_package(Boost 1.73 REQUIRED system serialization)



###### Compiler Settings #############
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE "Debug")
include_directories(include)
include_directories(${BOOST_INCLUDE_DIR})
link_directories(${BOOST_LIBRARY_DIR})

###### Create all sources ###########
FILE(GLOB SOURCES "src/*.cpp")

###### Link Libraries ###############
set(LIBS "${CMAKE_THREAD_LIBS_INIT}")
set(SERIAL "/home/karthik/Downloads/boost_1_73_0/stage/lib/libboost_serialization.so")
set(LIBS ${BOOST_LIBRARIES};${LIBS})
set(LIBS ${SERIAL};${LIBS})

###### Create Library ################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../lib")
add_library(ClientJoystick SHARED ${SOURCES})
target_link_libraries(ClientJoystick ${LIBS})

####### add Custom Libraries ##########
FILE(GLOB CUSTOMLIBS "lib/*.so")


####### Add Test File ################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")
add_executable(${PROJECT_NAME} "test/joystickClient.cpp")
target_link_libraries(${PROJECT_NAME} ${LIBS} ${CUSTOMLIBS})
