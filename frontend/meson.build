# The game in a window (SDL2), if SDL2 is there
sdl2Dependency = dependency('sdl2', required : false)
# the MT-32's sound, if Munt's libmt32emu is there (pkg-config mt32emu; not part of this project)
mt32emuDependency = dependency('mt32emu', required : false)
frontendArgs = commonCompileArgs
frontendRpath = ''
if mt32emuDependency.found()
  frontendArgs += [ '-DHAVE_MT32EMU' ]
  frontendRpath = mt32emuDependency.get_variable(pkgconfig : 'libdir', default_value : '')
endif
if sdl2Dependency.found()
  executable('opensamurai',
    'main.c',
    c_args : frontendArgs,
    dependencies : [ opensamuraiDependency, sdl2Dependency, mt32emuDependency ],
    build_rpath : frontendRpath,
    install_rpath : frontendRpath,
    install : true,
  )
endif
