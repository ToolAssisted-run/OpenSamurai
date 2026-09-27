# Test programs. The ones that need the game's files are registered only with -DgameDir; the oracle comparison
# suites (against captures of the real game in DOSBox-X, kept outside the repository in $SOTS_WORKSPACE,
# default ~/sotsdec) only with -DoracleTests=true.
testPrograms = {
  'cattest' : 'the resource catalogs: every entry of every catalog accounted for',
  'dueltest' : 'the duel against captures of the real game, frame by frame',
  'battletest' : 'the battle against captures of the real game, step by step',
}

testExecutables = {}
foreach name, description : testPrograms
  testExecutables += { name : executable(name,
    name + '.c',
    c_args : commonCompileArgs,
    dependencies : [ opensamuraiDependency ],
  ) }
endforeach

gameDir = get_option('gameDir')
if gameDir != ''
  test('cattest', testExecutables['cattest'], args : [ gameDir ], suite : 'core')
endif
