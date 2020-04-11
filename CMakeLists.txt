cmake_minimum_required(VERSION 3.7)

project(GameKit)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source")
set(DEPS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies")

file(GLOB_RECURSE SRC
    "${SRC_DIR}/*.cpp"
)

file(GLOB_RECURSE INC
	"${SRC_DIR}/*.hpp"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2")

add_library(${CMAKE_PROJECT_NAME} STATIC ${SRC} ${INC})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Source")

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -DDEBUG_ENABLED -DDEBUG_COLOR)

if(NOT MSVC)
	target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors)
	target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wno-variadic-macros)
endif()

if(MSVC)
	set(CMAKE_CXX_STANDARD 17)
else()
	target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -std=c++17)
endif()

# TinyXML2
target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/tinyxml2")

# GLM
target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/glm")

# SDL
target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/SDL")
set(SDL_DIR "${DEPS_DIR}/SDL")
add_subdirectory("${SDL_DIR}")
target_link_libraries(${PROJECT_NAME} "SDL" "${SDL_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${SDL_DIR}/include")

#target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/SDL_Image")
set(SDL_Image_DIR "${DEPS_DIR}/SDL_Image")
#add_subdirectory("${SDL_Image_DIR}")
#target_link_libraries(${PROJECT_NAME} "SDL_Image" "${SDL_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${SDL_Image_DIR}")

#target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/SDL_Mixer")
set(SDL_Mixer_DIR "${DEPS_DIR}/SDL_Mixer")
#add_subdirectory("${SDL_Mixer_DIR}")
#target_link_libraries(${PROJECT_NAME} "SDL_Mixer" "${SDL_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${SDL_Mixer_DIR}/include")

#target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/SDL_TTF")
set(SDL_TTF_DIR "${DEPS_DIR}/SDL_TTF")
#add_subdirectory("${SDL_TTF_DIR}")
#target_link_libraries(${PROJECT_NAME} "SDL_TTF" "${SDL_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${SDL_TTF_DIR}")

# GLAD
set(GLAD_DIR "${DEPS_DIR}/GLAD")
add_subdirectory("${GLAD_DIR}")
target_link_libraries(${PROJECT_NAME} "GLAD" "${GLAD_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS_DIR}/GLAD/include")

message(STATUS "This is the BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is the SOURCE dir " ${PROJECT_SOURCE_DIR})
