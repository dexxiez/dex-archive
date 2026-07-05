dxa_inc = include_directories('.')
dxa_src = files('dxa.c')

dxa_target = shared_library('dexarchive', dxa_src, include_directories: dxa_inc, install: false)

# Declare a dependency object for internal project use
dxa_dep = declare_dependency(link_with: dxa_target, include_directories: dxa_inc)
