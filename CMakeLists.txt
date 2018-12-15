cmake_minimum_required(VERSION 3.6)
project(RoadFighter)
add_executable(run main.cpp )


# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp roadfighter/Entity.cpp roadfighter/Entity.h roadfighter/World.cpp roadfighter/World.h roadfighter/PlayerCar.cpp roadfighter/PlayerCar.h roadfighter/EntityFactory.cpp roadfighter/EntityFactory.h roadfighterSFML/SFMLPlayerCar.cpp roadfighterSFML/SFMLPlayerCar.h roadfighterSFML/SFMLFactory.cpp roadfighterSFML/SFMLFactory.h Singleton/Random.cpp Singleton/Random.h Singleton/Transformation.cpp Singleton/Transformation.h Game.cpp Game.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(plotter_sfml ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(plotter_sfml ${SFML_LIBRARIES})

INSTALL(TARGETS plotter_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)