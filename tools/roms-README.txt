The Roland MT-32's ROMs go here: a control ROM and a PCM ROM, as files of any names (they are recognized by their
contents; an original MT-32's, versions 1.04 to 1.07, is the sound the game was made for; a later MT-32's or a
CM-32L's also work). They are not included: they are Roland's, and you need your own.

Then start the game with the MT-32: opensamurai GAMEDIR /AR

The ROMs are also looked for in your own data folder (on Linux ~/.local/share/OpenSamurai/roms, on Windows
%APPDATA%\OpenSamurai\roms), in the folder the OPENSAMURAI_MT32ROMS environment variable names, and in the game's
folder. Without them, /AR plays the AdLib's sound instead.
