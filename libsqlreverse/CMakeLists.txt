set(libsqlreverse_SRCS
    reverse.h
    reverse.cpp
	PgListNode.h
    PgListNode.cpp
)

# Declare the library
add_library(libsqlreverse STATIC
    ${libsqlreverse_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libsqlreverse PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)