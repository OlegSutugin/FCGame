set(PROJECT_NAME FightClubGame)


set(SOURCES FightClub.cpp )
set(DLL_GAME_SOURCES Game/Character.cpp Game/Weapon.cpp)              #выделяем в динамическую библиотеку
set(DLL_GAME_INCLUDES Game/Character.h Game/Weapon.h)                 #выделяем в динамическую библиотеку


#sources
source_group("Source files/Game" FILES "Game/Weapon.cpp" "Game/Character.cpp")
source_group("Header files/Game" FILES "Game/Weapon.h" "Game/Character.h")


#targets
add_executable(${PROJECT_NAME} ${SOURCES})
add_library(${PROJECT_NAME}Lib SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES}) #adding dynamic library
add_executable(${PROJECT_NAME}TestRunner Tests/main.cpp)     #placeholder for autotests

target_compile_definitions(${PROJECT_NAME}Lib PRIVATE _EXPORTING)       #for DLL export in header files
target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)


#link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib) #linking source code to dynamic library 
target_link_libraries(${PROJECT_NAME}Lib PRIVATE MathLib) #linking dynamic library code to static library 
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE MathLib) #linking tests code to static library 
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE ${PROJECT_NAME}Lib) #linking tests code to dynamic library 
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE gtest::gtest)


#includes in IDE
#This is looks like a copy paste lets do a cycle
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
#target_include_directories(${PROJECT_NAME}TestRunner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
#target_include_directories(${PROJECT_NAME}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
#this is now a cycle
set(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}TestRunner ${PROJECT_NAME}Lib)
foreach(target IN LISTS TARGETS)
    target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()


#to combine few projects in one folder
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}Lib PROPERTIES FOLDER ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}TestRunner PROPERTIES FOLDER ${PROJECT_NAME})