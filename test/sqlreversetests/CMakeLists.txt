file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(sqlreversetests ${SRCS})

TARGET_LINK_LIBRARIES(sqlreversetests
    libsqlreverse
    gtest
)

add_test(NAME sqlreversetests
COMMAND sqlreversetests)
