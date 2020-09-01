cmake_minimum_required(VERSION 2.6)

project(MazeSolver)

include_directories(
	contrib/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/lib
)

add_executable(MazeSolver

	src/main.cpp
	
	src/AStarAlgorithm.cpp
	src/AStarAlgorithm.h
	
	src/DijkstraAlgorithm.cpp
	src/DijkstraAlgorithm.h

	src/GeneticAlgorithm.cpp
	src/GeneticAlgorithm.h
)

target_link_libraries(MazeSolver SDL2)

add_custom_command(TARGET MazeSolver
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	"${PROJECT_SOURCE_DIR}/contrib/lib/SDL2.dll"
	$<TARGET_FILE_DIR:MazeSolver>
)
