file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "../include/*.h")

add_executable(ft_minecraft ${SRC_FILES} ${HEADER_FILES})

target_include_directories(ft_minecraft PRIVATE ../include)
target_include_directories(ft_minecraft PRIVATE $ENV{VULKAN_SDK}/include)

# 예시: 외부 라이브러리 연결 (GLFW, Vulkan, glm 등)
find_package(Vulkan REQUIRED)

target_link_libraries(ft_minecraft PRIVATE Vulkan::Vulkan)

