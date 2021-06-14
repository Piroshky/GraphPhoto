project('heart-break', 'cpp', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# gl3w_lib = static_library(
#   'gl3w',
#   'libs/gl3w/Source/gl3w.c',
#   include_directories: 'libs/gl3w/Include',
# )
# gl3w_dep = declare_dependency(
#   include_directories: 'libs/gl3w/Include',
#   link_with: gl3w_lib
# )

sources = []
incdirs = []

# part of a stupid hack to get around meson's deficiencies as a build system
data_out_dir = meson.current_build_dir() / 'data'

subdir('libs')
subdir('source')

glfw3 = dependency('glfw3')

cc = meson.get_compiler('c')
libdl = cc.find_library('dl')

gl = dependency('gl')

summary (
  {
    'glfw3' : glfw3.found(),
    'libdl' : libdl.found(),
    'gl'    :    gl.found(),
  }
)

exe = executable(
  'heart_break',
  sources,
  include_directories : incdirs,
  dependencies: [gl3w_dep, glfw3, libdl, gl]
)
