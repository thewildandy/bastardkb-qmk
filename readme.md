This README has been repurposed for my own use / reference. For the official BKB QMK fork readme, see the upstream.

Installation:
- Install QMK
- Install dependencies for QMK:
- - for Intel macs: brew install armmbed/formulae/arm-none-eabi-gcc
- - for Apple Silicon macs (M1, M2 etc): brew install --cask gcc-arm-embedded

Build firmware:
qmk compile -c kb {keyboard} -km {keymap}
e.g.
qmk compile -c -kb bastardkb/charybdis/4x6 -km via
qmk compile -c -kb bastardkb/charybdis/4x6 -km custom


Wishlist:
- Remove all the keyboard configs I don't need?
- Double tap shift to caps lock, bonus points for lighting up the key in this scenario
- Re-add numpad
- Better layout for programming keys
- Macro for common functions?
- More layers