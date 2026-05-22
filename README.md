# T8 Force Notations (v3.00.02)

<!-- <img align=center src=""> -->
because i can't bear it anymore

Changes Tekken 8 button notations by generating a custom keyboard layout.

T8FN lets you:
- select your input files,
- replace button icons/notations with another style,
- automatically build a ready-to-use mod folder.

## How it works

T8 Force Notations reads your inputs, pick the correct files, rearranges them, and generates a keyboard layout `KBL`.

## Usage

1. Run `T8ForceNotations`.
2. Select your input.
3. Choose the notation style you want to use.
4. Select the player side.
5. Click **Build**.
6. Move the generated `KBL` folder to: `TEKKEN 8\Polaris\Content\Paks\Mods\KBL`

> [!NOTE]
> T8FN currently cannot delete old files automatically.
> Since this is my first WinAPI32 project in C++, I prefer avoiding automatic file deletion (for now) for safety reasons until the filesystem handling is fully reliable.
> Rebuilding may create duplicate files so it is recommended to delete the old `KBL` folder before building again.

## TODO

* [ ] header
* [ ] request notation section prerequisites
- [ ] support controller
- [ ] layout presets
- [ ] music
- [ ] quick guide `it's my first mod`