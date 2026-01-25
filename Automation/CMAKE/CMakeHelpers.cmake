


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