Title: Blender Basics
Date: 2018-04-14
Category: Misc
Tags: Blender



Right-handed (Rechtshändiges) Cartesian coordinate system. Axes:

- $x$: width, red
- $y$: depth, green
- $z$: height, blue

Mesh: vertices (3D points), edges (connects points) and faces (polygon formed by vertices).

Texture: 2D images mapped to 3D objects. UV coordinates necessary to project texture onto mesh.

Lights (rendering): usually 3 kind of lamps

- directional light, like sun, hard shadows
- omnidirectional light, diffuse, illuminating things arround it, soft shadows
- spots: simulate conical shaped light


# Viewport (3D View)

## Emulate 3 Button Mouse and Emulate Numpad

> File > User Preferences

- Emulate 3 Button Mouse: use `ALT`+`LMB` as `MMB`
- Emulate Numpad: use top row numbers as numpad


## Navigation

| Action           | Shortcut      |
|------------------|---------------|
| Pan (shifting)   | `Shift`+`MMB` |
| Orbit (rotatong) | `MMB`         |
| Zoom             | Mouse wheel   |


`SHIFT`+`C`: Reset 3D cursor to origin

## Shortcuts for Views

| Action    | Shortcut (num pad)  |
|-----------|---------------------|
| Front     |                 1   |
| Side      |                 3   |
| Top       |                 7   |
| (De-)activate orthographic mode | 5 |
| Camera    |                 0   |


## Selection

Select object: `RMB`
Select multiple objects: `SHIFT`+`RMB`
Select complete loop: `ALT`+`RMB` (can be combined with `SHIFT`)
Select (deselect) all: `A`
Box selection: `B` `LMB` (`MMB` for deselection)
Circle (brush) select: `C` `LMB`, scroll for bigger brush (`MMB` for deselection)

## Tranformation

Grab: `G`
Rotation: `R` (`R` `R` for free rotation)
Scale: `S`

Revert Grab `Alt`+`G`
Revert Rotatsion `Alt`+`R`
Revert Scale `Alt`+`S`

Each of the transformation hot-key can be combined with `x`, `y` or `z` to allow the trasformation only for this axis.

## Add and Delete Objects

- Delete: `x` or `DEL`
- Add: `SHIFT`+`A`


## Modes

Toggle between *Edit Mode* and *Object Mode*: `TAB`


## Display Mode

Toggle between *Solid* and *Wireframe*: `Z`

## Edit Mode

Mesh select mode (Vertex, Edge, Face): `CTRL`+`TAB`


