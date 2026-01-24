set(PROJECT_NAME ChuckNorrisJokes)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json) #in output log when "conan install . --output-folder=build" --profile=conanProfileDebug --profile:b=conanProfileDebug (Release)   or in library page on conan site
target_link_libraries(${PROJECT_NAME} raylib cpr::cpr) #or target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json cpr::cpr)