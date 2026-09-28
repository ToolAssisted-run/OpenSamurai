# The reconstructed game as one library. It is linked whole so that routines a test or the frontend
# replaces (weak defaults) behave as if every source were compiled into the program.
opensamuraiSources = files(
  'asm2c.c', 'battle.c', 'battle_math.c', 'battle_setup.c', 'battle_tables.c', 'catalog.c', 'dosmem.c', 'dsimage.c', 'duel.c',
  'duel_tables.c', 'lzw.c', 'melee_core.c', 'melee_rt.c', 'mgraphic.c', 'rp_core.c', 'rp_rt.c', 'shared.c', 'start_core.c', 'start_rt.c',
)

opensamuraiIncludes = include_directories('.')

opensamuraiLib = static_library('opensamurai', opensamuraiSources,
  c_args : commonCompileArgs,
  include_directories : opensamuraiIncludes,
)

opensamuraiDependency = declare_dependency(
  link_whole : opensamuraiLib,
  include_directories : opensamuraiIncludes,
)
