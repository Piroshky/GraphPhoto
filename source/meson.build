sources += files('heart-break.cpp')

incdirs += include_directories('.')

subdir('imgui')
subdir('imgui-node-editor')

## Inexplicably meson does not let you copy directories from source to build
## why? who knows. everything must suck and be miserable and tedious
## configure_file(copy : true, input : 'data/', output : 'data/')

## I decided to give meson a chance because the pitch was its a fast build system
## that gets out of your way. Lol I guess not.
data_in_dir = meson.current_source_dir() / 'data'
custom_target('copy-data-dir',
	      command : ['cp', '-r', data_in_dir, data_out_dir],
	      output : 'meson is bad',
	      build_by_default : true,
	     )
