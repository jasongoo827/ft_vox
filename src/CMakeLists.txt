# Dependency include
include(${CMAKE_SOURCE_DIR}/cmake/Dependency.cmake)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

add_executable(ft_minecraft ${SRC_FILES} ${HEADER_FILES})

target_include_directories(ft_minecraft PRIVATE
    ${DEP_INCLUDE_DIR}
    $ENV{VULKAN_SDK}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 예시: 외부 라이브러리 연결 (GLFW, Vulkan, glm 등
find_package(Vulkan REQUIRED)
target_link_libraries(ft_minecraft PRIVATE
    Vulkan::Vulkan
    ${DEP_LIB_DIR}/libglfw3.a
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreFoundation"
    "-framework AppKit"
)
add_dependencies(ft_minecraft ${DEP_LIST})
