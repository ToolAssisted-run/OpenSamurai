# The reconstructed game as one library. It is linked whole so that routines a test or the frontend
# replaces (weak defaults) behave as if every source were compiled into the program.
opensamuraiSources = files(
  'battle.c', 'battle_math.c', 'battle_tables.c', 'catalog.c', 'duel.c', 'duel_tables.c', 'shared.c',
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
