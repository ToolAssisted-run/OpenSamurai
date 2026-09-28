project('opensamurai', 'c',
  version: '0.1.0',
  license: 'GPL-3.0-or-later',
  license_files: ['LICENSE'],
  default_options : ['c_std=gnu11', 'buildtype=release', 'warning_level=1'],
  subproject_dir: 'extern'
)

# Common flags for everything built here
commonCompileArgs = [ '-Wfatal-errors', '-Wall' ]

# The reconstructed game
subdir('source')

# Do not build any targets if this is a subproject
if meson.is_subproject() == false

  # The game
  subdir('frontend')

  # Test programs and the test suite
  if get_option('buildTests') == true
    subdir('tests')
  endif

endif # is_subproject()
