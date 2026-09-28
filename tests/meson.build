# Test programs. The ones that need the game's files are registered only with -DgameDir; the oracle comparison
# suites (against captures of the real game in DOSBox-X, kept outside the repository in $SOTS_WORKSPACE,
# default ~/sotsdec) only with -DoracleTests=true.
testPrograms = {
  'cattest' : 'the resource catalogs: every entry of every catalog accounted for',
  'dueltest' : 'the duel against captures of the real game, frame by frame',
  'battletest' : 'the battle against captures of the real game, step by step',
  'meleetest' : 'the melee against captures of the real game, tick by tick',
  'rptest' : 'the role-playing game against captures of the real game, tick by tick',
  'starttest' : 'the start-up program against captures of the real game, wait by wait',
  'duelexetest' : 'the duel program against captures of the real game, frame by frame',
  'battleexetest' : 'the battle program against captures of the real game, step by step',
  'meleeexetest' : 'the melee program against captures of the real game, tick by tick',
  'gametest' : 'the game as the launcher runs it, headless, from the game files',
  'battlesetuptest' : 'the battlefield, the enemy formation and the armies against captures',
  'oplrender' : 'the AdLib chip model rendering a capture\'s writes (to set against the real game\'s sound)',
  'soundtest' : 'the IBM speaker driver against captures: its calls replayed, its port writes compared',
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
