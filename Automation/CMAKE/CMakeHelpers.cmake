


macro(system_info)
    message("======== System info ======== ")
    message("Using ${CMAKE_CXX_COMPILER_ID} compiler")
    if(WIN32)
        message("Running on Windows")
    elseif(LINUX)
        message("Running on Linux")
    endif()

    if(MSVC)
        message("Compiler  ${MSVC_VERSION} version and ${MSVC_TOOLSET_VERSION} toolset version")
        #target_compile_options(${PROJECT_NAME} PRIVATE /FAc)
    endif()

    message("Configuration types = ${CMAKE_CONFIGURATION_TYPES}")
    #message("Compiler Flags: ${CMAKE_CXX_FLAGS}")
    #message("Compiler debug Flags: ${CMAKE_CXX_FLAGS_DEBUG}")
    #message("Compiler release Flags: ${CMAKE_CXX_FLAGS_RELEASE}")
    #${VAR}
    #MSVC_VERSION
    message("====================================== ")
endmacro()


#pch
function(setup_precompiled_headers TARGET PCH_SOURCE PCH_HEADER SOURCE_FILES)
    if(WIN32)
        target_sources(${TARGET} PRIVATE ${PCH_HEADER} ${PCH_SOURCE}) #for precompile headers
        set_source_files_properties(${PCH_SOURCE} PROPERTIES COMPILE_FLAGS "/Yc${PCH_HEADER}")

        foreach(SOURCE_FILE ${SOURCE_FILES})
            if(${SOURCE_FILE} MATCHES "\\.cpp$")
                set_source_files_properties(${SOURCE_FILE} PROPERTIES COMPILE_FLAGS "/Yu${PCH_HEADER}")
            endif()
        endforeach()

        target_compile_options(${TARGET} PRIVATE "/FI${PCH_HEADER}")
    endif()
endfunction()

#conan settings
macro(setup_conan)
set(CMAKE_CONAN_PATH "${CMAKE_BINARY_DIR}/conan_provider.cmake")
    if(NOT EXISTS ${CMAKE_CONAN_PATH})
        message(STATUS "Downloading conan.cmake from  https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/refs/heads/develop2/conan_provider.cmake" ${CMAKE_CONAN_PATH})
    endif()

    set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${CMAKE_CONAN_PATH})

    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        message(STATUS "Setup release profiles")
        set(CONAN_HOST_PROFILE "${CMAKE_CURRENT_SOURCE_DIR}/conanProfileRelease")
        set(CONAN_BUILD_PROFILE "${CMAKE_CURRENT_SOURCE_DIR}/conanProfileRelease")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Setup debug profiles")
        set(CONAN_HOST_PROFILE "${CMAKE_CURRENT_SOURCE_DIR}/conanProfileDebug")
        set(CONAN_BUILD_PROFILE "${CMAKE_CURRENT_SOURCE_DIR}/conanProfileDebug")
    else()
        message(WARNING "No bild type was specified")
    endif()
endmacro()