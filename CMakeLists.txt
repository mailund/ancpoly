project(AncPoly)
set(AncPoly_VERSION_MAJOR 0)
set(AncPoly_VERSION_MINOR 1)

#configure_file()

add_executable(bin/sample_freqs
  src/sample_freqs.c
  src/io.h src/io.c
  src/sampling.h src/sampling.c
  src/trees.h src/trees.c
)
