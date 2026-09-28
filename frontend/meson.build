# The game in a window (SDL2), if SDL2 is there
sdl2Dependency = dependency('sdl2', required : false)
if sdl2Dependency.found()
  executable('opensamurai',
    'main.c',
    c_args : commonCompileArgs,
    dependencies : [ opensamuraiDependency, sdl2Dependency ],
    install : true,
  )
endif
