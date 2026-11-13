cmake_minimum_required(VERSION 3.10) 
project( fmc1_cryptography )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set(SOURCES
    main.cpp
    fmc.cpp
    key.cpp
)

add_executable( fmc1_rsa ${SOURCES} )
