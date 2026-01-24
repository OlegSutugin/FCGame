#general information 
cmake_minimum_required(VERSION 3.31)
set(PROJECT_NAME CMakeLearning)
project(${PROJECT_NAME} VERSION 1.0.0)
message("--- Project files generation for ${PROJECT_NAME} ---")


#Common options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #executable file in that directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #libraries to that directory too
set(STARTUP_PROJECT_NAME FightClubGame)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${STARTUP_PROJECT_NAME}) #making startup project in IDE delete all artifactws before that
set_property(GLOBAL PROPERTY USE_FOLDERS On)   #making all cmake projects in one folder in IDE if OFF (==FALSE)
set(CMAKE_SUPPRESS_REGENERATION  TRUE)  #deleting ZERO_CHECK project in IDE


#cpp options
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FA")


#source_group("Source files/Utils" FILES "Source/Utils/Math.cpp") #for IDE  #not needed because it's a lib now
#source_group("Header files/Utils" FILES "Source/Utils/Math.h")



#conan libraries find
find_package(nlohmann_json REQUIRED) #in output log when "conan install . --output-folder=build" or in library page on conan site
find_package(GTest REQUIRED)
find_package(cpr)
find_package(raylib)


include_directories(Source)

#option(SKIP_GAME_OPTION "Skip game" OFF) #this can use in GUI - thats just for educational purpose
#if(SKIP_GAME_OPTION)
#    message("Skip game is On")
#endif()


#target_link_libraries ChuckNorrisJokes now in inner cmakelists
#target_link_libraries tetris now in inner cmakelists
add_subdirectory(Source/RaylibTetris) #inner cmakelists
add_subdirectory(Source/ChuckNorrisJokes) #inner cmakelists
add_subdirectory(Source/Utils) #inner cmakelists
add_subdirectory(Source/FightClubGame) #inner cmakelists

include(${CMAKE_CURRENT_SOURCE_DIR}/Automation/CMAKE/CMakeHelpers.cmake)
system_info()

