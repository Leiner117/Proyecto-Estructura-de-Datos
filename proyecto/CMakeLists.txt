cmake_minimum_required(VERSION 3.23)
project(proyecto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(proyecto)

add_executable(proyecto
        proyecto/Ephemerality.cpp
        proyecto/Ephemerality.h
        proyecto/main.cpp
        proyecto/People.cpp
        proyecto/People.h
        proyecto/Place.cpp
        proyecto/Place.h
        proyecto/Rain.cpp
        proyecto/Rain.h
        proyecto/Region.cpp
        proyecto/Region.h
        proyecto/TimeRegis.cpp
        proyecto/TimeRegis.h
        Ephemerality.cpp
        Ephemerality.h
        main.cpp
        People.cpp
        People.h
        Place.cpp
        Place.h
        Rain.cpp
        Rain.h
        Region.cpp
        Region.h
        TimeRegis.cpp
        TimeRegis.h)
