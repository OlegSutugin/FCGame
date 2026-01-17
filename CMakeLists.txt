#general information 
cmake_minimum_required(VERSION 3.31)
set(PROJECT_NAME FightClubGame)
project(${PROJECT_NAME} VERSION 1.0.0)
message("--- Project files generation for ${PROJECT_NAME} ---")


#Common options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #executable file in that directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #libraries to that directory too
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}) #making startup project in IDE delete all artifactws before that
set_property(GLOBAL PROPERTY USE_FOLDERS On)   #making all cmake projects in one folder in IDE if OFF (==FALSE)
set(CMAKE_SUPPRESS_REGENERATION  TRUE)  #deleting ZERO_CHECK project in IDE


#cpp options
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FA")


#sources
set(SOURCES Source/FightClub.cpp )
set(MATH_SOURCES Source/Utils/Math.cpp)           #выделяем в статическую библиотеку
set(MATH_INCLUDES Source/Utils/Math.h)          #выделяем в статическую библиотеку
set(DLL_GAME_SOURCES Source/Game/Character.cpp Source/Game/Weapon.cpp)              #выделяем в динамическую библиотеку
set(DLL_GAME_INCLUDES Source/Game/Character.h Source/Game/Weapon.h)                 #выделяем в динамическую библиотеку


#source_group("Source files/Utils" FILES "Source/Utils/Math.cpp") #for IDE  #not needed because it's a lib now
#source_group("Header files/Utils" FILES "Source/Utils/Math.h")
source_group("Source files/Game" FILES "Source/Utils/Weapon.cpp" "Source/Utils/Character.cpp")
source_group("Header files/Game" FILES "Source/Utils/Weapon.h" "Source/Utils/Character.h")


#targets
add_executable(${PROJECT_NAME} ${SOURCES})
add_library(MathLib STATIC ${MATH_SOURCES} ${MATH_INCLUDES}) #adding static library
add_library(${PROJECT_NAME}Lib SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES}) #adding dynamic library
add_executable(${PROJECT_NAME}TestRunner Source/Tests/main.cpp)     #placeholder for autotests

target_compile_definitions(${PROJECT_NAME}Lib PRIVATE _EXPORTING)       #for DLL export in header files
target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib) #linking source code to dynamic library 
target_link_libraries(${PROJECT_NAME}Lib PRIVATE MathLib) #linking dynamic library code to static library 
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE MathLib) #linking tests code to static library 
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE ${PROJECT_NAME}Lib) #linking tests code to dynamic library 


#includes in IDE
#This is looks like a copy paste lets do a cycle
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
#target_include_directories(${PROJECT_NAME}TestRunner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
#target_include_directories(${PROJECT_NAME}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
#this is now a cycle
set(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}TestRunner ${PROJECT_NAME}Lib)
foreach(target IN LISTS TARGETS)
    target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
endforeach()


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