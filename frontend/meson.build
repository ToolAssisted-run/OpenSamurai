fs = import('fs')
# The game in a window (SDL2), if SDL2 is there
sdl2Dependency = dependency('sdl2', required : false)
# the MT-32's sound: Munt's libmt32emu (LGPL-2.1-or-later), built from extern/munt (a git submodule) and linked in
# statically; else an installed one (pkg-config mt32emu); else none
mt32emuDependency = dependency('', required : false)
frontendArgs = commonCompileArgs
frontendRpath = ''
frontendLinkLanguage = 'c'
frontendLinkDepends = []
if get_option('mt32').allowed() and fs.exists(meson.project_source_root() / 'extern' / 'munt' / 'mt32emu' / 'CMakeLists.txt')
  add_languages('cpp', native : false)
  cmake = import('cmake')
  muntOptions = cmake.subproject_options()
  muntOptions.add_cmake_defines({
    'munt_WITH_MT32EMU_SMF2WAV' : false, 'munt_WITH_MT32EMU_QT' : false, 'munt_WITH_MT32EMU_ALSADRV' : false,
    'libmt32emu_SHARED' : false, 'mt32emu_BUILD_TESTING' : false, 'CMAKE_POSITION_INDEPENDENT_CODE' : true,
    'CMAKE_BUILD_TYPE' : 'Release',
  })
  muntOptions.set_install(false)
  munt = cmake.subproject('munt', options : muntOptions)
  # (the archive and the C++ runtime after it, statically: the program needs no C++ library of the system's; as a
  # Meson C++ target it would bring the shared -lstdc++)
  mt32emuLibrary = munt.target('mt32emu')
  stdcxxStatic = meson.get_compiler('cpp').find_library('stdc++', static : true)
  mt32emuDependency = declare_dependency(
    link_args : [ mt32emuLibrary.full_path(), '-static-libgcc', '-lm' ],
    dependencies : [ stdcxxStatic ],
    include_directories : munt.include_directories('mt32emu'))
  frontendLinkDepends += [ mt32emuLibrary ]
elif get_option('mt32').allowed()
  mt32emuDependency = dependency('mt32emu', required : get_option('mt32'))
  if mt32emuDependency.found()
    frontendRpath = mt32emuDependency.get_variable(pkgconfig : 'libdir', default_value : '')
  endif
endif
if mt32emuDependency.found()
  frontendArgs += [ '-DHAVE_MT32EMU' ]
endif
if sdl2Dependency.found()
  executable('opensamurai',
    'main.c',
    c_args : frontendArgs,
    dependencies : [ opensamuraiDependency, sdl2Dependency, mt32emuDependency ],
    link_language : frontendLinkLanguage,
    link_depends : frontendLinkDepends,
    build_rpath : frontendRpath,
    install_rpath : frontendRpath,
    install : true,
  )
endif
