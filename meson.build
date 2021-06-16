project('heart-break', 'cpp', 'c',
  version : '0.1',
  default_options : ['warning_level=1'])

add_global_arguments('-Werror=return-type', language : 'cpp') ## the gcc people are assholes and/or c++ is unbelievably shitty

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


gegl  = dependency('gegl-0.4')
glfw3 = dependency('glfw3')
gl    = dependency('gl')

# Naturally you can't just register libdl like a normal library.
# This isn't meson's fault, it's because of some stupid nonsense the GNU people
# are doing. 
cc = meson.get_compiler('c')
libdl = cc.find_library('dl')

summary (
  {
    'gegl'  :  gegl.found(),
    'glfw3' : glfw3.found(),    
    'gl'    :    gl.found(),
    'libdl' : libdl.found(),
  }
)


exe = executable(
  'heart_break',
  sources,
  include_directories : incdirs,
  dependencies: [gl3w_dep, glfw3, libdl, gl, gegl]
)
