Must explicitly pass keymap arg to avoid make errors (if you see NoneType mentioned, you fucked this up)

e.g.
`qmk compile -c -kb bastardkp/charybdis/4x6/v1/elitec -km basil`

Must also run `qmk setup` after changing branches and ensure all dependencies are installed. Note this does not refer to the prompt 'would you like to install dependencies', but rather you must `brew install` the missing (red) packages. Some packages require m-series alternatives with slightly different brew providers.
