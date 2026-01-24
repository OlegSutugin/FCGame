set(PROJECT_NAME MathLib)

set(MATH_SOURCES Math.cpp)           #выделяем в статическую библиотеку
set(MATH_INCLUDES Math.h)          #выделяем в статическую библиотеку

add_library(${PROJECT_NAME} STATIC ${MATH_SOURCES} ${MATH_INCLUDES}) #adding static library