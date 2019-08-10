cmake_minimum_required(VERSION 3.6)
project(RoadFighter)
#add_executable(run main.cpp )


# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp roadfighter/Entity.cpp roadfighter/Entity.h roadfighter/World.cpp roadfighter/World.h roadfighter/PlayerCar.cpp roadfighter/PlayerCar.h roadfighter/EntityFactory.cpp roadfighter/EntityFactory.h roadfighterSFML/PlayerCar.cpp roadfighterSFML/PlayerCar.h roadfighterSFML/SFMLFactory.cpp roadfighterSFML/SFMLFactory.h Singleton/Random.cpp Singleton/Random.h Singleton/Transformation.cpp Singleton/Transformation.h Game.cpp Game.h roadfighter/Background.cpp roadfighter/Background.h roadfighterSFML/Background.cpp roadfighterSFML/Background.h roadfighter/PassingCar.cpp roadfighter/PassingCar.h roadfighterSFML/PassingCar.cpp roadfighterSFML/PassingCar.h Utils/Utils.h roadfighter/Bullet.cpp roadfighter/Bullet.h roadfighterSFML/Bullet.cpp roadfighterSFML/Bullet.h Observer/Observer.cpp Observer/Observer.h Observer/ObserverScore.cpp Observer/ObserverScore.h Observer/Subject.cpp Observer/Subject.h Menu.cpp Menu.h roadfighter/Rock.cpp roadfighter/Rock.h roadfighterSFML/Rock.cpp roadfighterSFML/Rock.h roadfighter/MovingCar.cpp roadfighter/MovingCar.h roadfighterSFML/MovingCar.cpp roadfighterSFML/MovingCar.h Observer/ObserverBackgroundEnd.cpp Observer/ObserverBackgroundEnd.h Observer/ObserverStartRace.cpp Observer/ObserverStartRace.h roadfighter/AIRacer.cpp roadfighter/AIRacer.h roadfighterSFML/AIRacer.cpp roadfighterSFML/AIRacer.h roadfighter/Boss.cpp roadfighter/Boss.h roadfighterSFML/Boss.cpp roadfighterSFML/Boss.h Exception_class/GameError.cpp Exception_class/GameError.h Exception_class/SpriteLoadError.cpp Exception_class/SpriteLoadError.h Exception_class/FontLoadError.cpp Exception_class/FontLoadError.h Exception_class/JSONParseError.cpp Exception_class/JSONParseError.h Exception_class/FileError.cpp Exception_class/FileError.h Exception_class/ScoreError.cpp Exception_class/ScoreError.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(roadfighter_sfml ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(roadfighter_sfml ${SFML_LIBRARIES})

#INSTALL(TARGETS plotter_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)