<h1 align="center">T8 Force Notations (v3.01.01)</h1>

<p align="center">
<img align=center src="https://github.com/m-curto/t8-force-notations/blob/main/resources/readme/header.jpg">
</p>

<h2 align="center">Changes Tekken 8 button notations by generating a custom keyboard layout.</h2>

T8FN lets you:
- select your input files,
- replace button icons/notations with another style,
- automatically build a ready-to-use mod folder.

## How it works

<p align="center">
<img src="https://github.com/m-curto/t8-force-notations/blob/main/resources/readme/preview1.png">
</p>
T8 Force Notations reads your inputs, pick the correct files, rearranges them, and generates a keyboard layout `KBL`.

## Usage

1. Run `T8ForceNotations`.
2. Select your input.
3. Choose the notation style you want to use.
4. Select the player side.
5. Click **Build**.
6. Move the generated `KBL` folder to: `TEKKEN 8\Polaris\Content\Paks\Mods\KBL`

<p align="center">
<img src="https://github.com/m-curto/t8-force-notations/blob/main/resources/readme/preview2.png">
</p>

> [!NOTE]
> T8FN currently cannot delete old files automatically.
> Since this is my first WinAPI32 project in C++, I prefer avoiding automatic file deletion (for now) for safety reasons until the filesystem handling is fully reliable.
> Rebuilding may create duplicate files so it is recommended to delete the old `KBL` folder before building again.

> [!NOTE]
> This project is largely a pretext for experimenting with WinAPI32; expect some bugs or things that don't work yet.

## TODO

* [ ] header
* [ ] request notation section prerequisites
- [ ] support controller
- [x] layout presets
- [ ] music
- [ ] quick guide `install your first mod`
- [ ] check duplicates console icons
- [ ] support special char display combobox
- [ ] support 1+2 1+2+3 etc..
- [ ] warning presets that erase previous input
- [ ] merge struct notation BMP+Cursor+KeyCodes
- [x] 169 191 264
- [x] 197 198 (as intended)
- [ ] shuffled XYAB ui doublecheck
- [ ] resize readme *.jpg
