#general information
 
cmake_minimum_required(VERSION 3.31)
set(PROJECT_NAME FightClubGame)
project(${PROJECT_NAME} VERSION 1.0.0)
message("--- Project files generation for ${PROJECT_NAME} ---")

#Common options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #executable file in that directory
message("Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}) #making startup project in IDE delete all artifactws before that
set_property(GLOBAL PROPERTY USE_FOLDERS On)   #making all cmake projects in one folder in IDE if OFF (==FALSE)
set(CMAKE_SUPPRESS_REGENERATION  TRUE)  #deleting ZERO_CHECK project in IDE

#cpp options
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FA")


#app options
set(SOURCES 
Source/FightClub.cpp 
Source/Game/Character.cpp 
Source/Utils/Math.cpp 
Source/Game/Weapon.cpp)
set(INCLUDES 
Source/Game/Character.h 
Source/Utils/Math.h 
Source/Game/Weapon.h)

source_group("Source files/Utils" FILES "Source/Utils/Math.cpp") #for IDE
source_group("Header files/Utils" FILES "Source/Utils/Math.h")
source_group("Source files/Game" FILES "Source/Utils/Weapon.cpp" "Source/Utils/Character.cpp")
source_group("Header files/Game" FILES "Source/Utils/Weapon.h" "Source/Utils/Character.h")


add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

#includes in IDE
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)


message("Using ${CMAKE_CXX_COMPILER_ID} compiler")

if(WIN32)
    message("Running on Windows")
elseif(LINUX)
    message("Running on Linux")
endif()

if(MSVC)
    message("Compiler  ${MSVC_VERSION} version and ${MSVC_TOOLSET_VERSION} toolset version")
    target_compile_options(${PROJECT_NAME} PRIVATE /FAc)
endif()

message("Configuration types = ${CMAKE_CONFIGURATION_TYPES}")
#message("Compiler Flags: ${CMAKE_CXX_FLAGS}")
#message("Compiler debug Flags: ${CMAKE_CXX_FLAGS_DEBUG}")
#message("Compiler release Flags: ${CMAKE_CXX_FLAGS_RELEASE}")
#${VAR}
#MSVC_VERSION