project(
  'dexarchive_repo',
  'c',
  version: '0.1.0',
  default_options: [
    'c_std=c11',
    'warning_level=3',
    'buildtype=debug',
    'b_ndebug=if-release',
    'default_library=shared',
    # 'werror=true',       # uncomment once warnings are clean
  ],
)

cc = meson.get_compiler('c')

# ---- Extra footgun-catching warnings ---------------------------------------
extra_warnings = cc.get_supported_arguments(
  [
    '-Wshadow',
    '-Wconversion',
    '-Wsign-conversion',
    '-Wcast-align',
    '-Wstrict-prototypes',
    '-Wmissing-prototypes',
    '-Wdouble-promotion',
    '-Wformat=2',
    '-Wundef',
    '-Wnull-dereference',
    '-Wpointer-arith',
  ],
)
add_project_arguments(extra_warnings, language: 'c')

# ---- Suppress noisy/unwanted warnings ---------------------------------------
suppressed_warnings = cc.get_supported_arguments(
  [
    '-Wno-calloc-transposed-args',
  ],
)
add_project_arguments(suppressed_warnings, language: 'c')

# ---- Source files ------------------------------------------------------------

subdir('src/dxalib')
subdir('src/cli')
