sources += files('heart-break.cpp')

incdirs += include_directories('.')

subdir('imgui')
subdir('imgui-node-editor')

## Inexplicably meson does not let you copy directories from source to build
## Why? Who knows. Everything must suck and be miserable and tedious.
## below is what I wanted to write...
## configure_file(copy : true, input : 'data/', output :
## but instead this is what I have to write...
# data_in_dir = meson.current_source_dir() / 'data'
# custom_target('copy-data-dir',
# 	      command : ['cp', '-r', data_in_dir, data_out_dir],
# 	      output : 'meson is bad',
# 	      build_by_default : true,)
## I decided to give meson a chance because the pitch was its a fast build system
## that gets out of your way. "I don't want to baby sit my build system" he said.
## Lol so much for that.
