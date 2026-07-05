dxa_inc = include_directories('.')
dxa_src = files('dxa.c')

install_headers('dxa.h')

dxa_target = shared_library('dexarchive', dxa_src, include_directories: dxa_inc, install: true)

pkg = import('pkgconfig')
pkg.generate(dxa_target, name: 'dexarchive', description: '', version: '0.1.0')

# Declare a dependency object for internal project use
dxa_dep = declare_dependency(link_with: dxa_target, include_directories: dxa_inc)
