cmake_minimum_required(VERSION 3.6)

project(AncPoly)
set(AncPoly_VERSION_MAJOR 0)
set(AncPoly_VERSION_MINOR 1)

#configure_file()

find_library(ARGP_LIB argp)
find_path(ARGP_INCLUDE_DIR argp.h)
include_directories(${ARGP_INCLUDE_DIR})

add_executable(ancpoly_sample_freqs
  src/sample_freqs.c
  src/io.h src/io.c
  src/sampling.h src/sampling.c
  src/trees.h src/trees.c
)
install(TARGETS ancpoly_sample_freqs DESTINATION bin)
target_link_libraries(ancpoly_sample_freqs ${ARGP_LIB})

add_executable(ancpoly_weight_freqs
  src/weight_freqs.c
  src/io.h src/io.c
  src/trees.h src/trees.c
)
install(TARGETS ancpoly_weight_freqs DESTINATION bin)
target_link_libraries(ancpoly_weight_freqs ${ARGP_LIB})
