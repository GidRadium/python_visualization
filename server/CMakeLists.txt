include(FetchContent)

include(FetchContent)

FetchContent_Declare(asio
  GIT_REPOSITORY git@github.com:chriskohlhoff/asio.git
  GIT_TAG master
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  )

FetchContent_GetProperties(asio)
if(NOT asio_POPULATED)
  FetchContent_Populate(asio)
endif()

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
find_package(Threads)
target_link_libraries(asio INTERFACE Threads::Threads)

add_executable(server server.cpp)

target_link_libraries(server asio)
