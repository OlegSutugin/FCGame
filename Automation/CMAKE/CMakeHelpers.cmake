


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