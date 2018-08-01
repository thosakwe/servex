set(SERVEX_VERSION_MAJOR 0 CACHE STRING "Servex major version")
set(SERVEX_VERSION_MINOR 0 CACHE STRING "Servex minor version")
set(SERVEX_VERSION_PATCH 0 CACHE STRING "Servex patch version")
set(SERVEX_VERSION_LABEL "dev" CACHE STRING "Servex version label")
set(_SERVEX_VERSION "${SERVEX_VERSION_MAJOR}.${SERVEX_VERSION_MINOR}.${SERVEX_VERSION_PATCH}")

if (NOT ("${SERVEX_VERSION_LABEL}" STREQUAL ""))
    set(_SERVEX_VERSION "${_SERVEX_VERSION}-${SERVEX_VERSION_LABEL}")
endif ()

set(SERVEX_VERSION ${_SERVEX_VERSION})

message(STATUS "Servex version: ${SERVEX_VERSION}")

set(servex_srcs
        Driver.cpp Driver.h
        Handler.cpp Handler.h
        Headers.cpp Headers.h
        HttpDriver.cpp HttpDriver.h
        HttpException.cpp HttpException.h
        Injector.cpp Injector.h
        Request.cpp Request.h
        Response.cpp Response.h
        Server.cpp Server.h
        servex.h)

macro(create_servex_library NAME)
    add_library(${NAME}_shared SHARED ${servex_srcs})
    add_library(${NAME}_static STATIC ${servex_srcs})
    set_target_properties(${NAME}_shared PROPERTIES OUTPUT_NAME ${NAME})
    set_target_properties(${NAME}_static PROPERTIES OUTPUT_NAME ${NAME})
    install(TARGETS ${NAME}_shared ${NAME}_static
            ARCHIVE DESTINATION lib
            LIBRARY DESTINATION lib)
endmacro()

create_servex_library(servex)
create_servex_library("servex-${SERVEX_VERSION_MAJOR}")
create_servex_library("servex-${SERVEX_VERSION_MAJOR}.${SERVEX_VERSION_MINOR}")

if (NOT ("${SERVEX_VERSION_LABEL}" STREQUAL ""))
    create_servex_library("servex-${SERVEX_VERSION_MAJOR}.${SERVEX_VERSION_MINOR}.${SERVEX_VERSION_PATCH}")
    create_servex_library("servex-${SERVEX_VERSION}")
else ()
    create_servex_library("servex-${SERVEX_VERSION}")
endif ()