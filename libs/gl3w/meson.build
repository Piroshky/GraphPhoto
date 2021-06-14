#  sources += files(
#   'Source/gl3w.c',
# )

incdirs += include_directories('Include')

gl3w_lib = static_library(
  'gl3w',
  'Source/gl3w.c',
  include_directories: 'Include',
)
gl3w_dep = declare_dependency(
  include_directories: 'Include',
  link_with: gl3w_lib
)
