# cub3D

Cub3D is a 42 school team project to create a dynamic view inside a 3D maze. Using the [MiniLibX library](https://github.com/42Paris/minilibx-linux), we must implement raycasting in the style of the famous [Wolfenstein 3D](http://users.atw.hu/wolf3d/) game, the first true FPS in videogame history.

## Clone

Clone the repository including the MiniLibX submodule:

```shell
git clone git@github.com:botyonthesky/Cub3D.git
```

## Compile and Run

There are two versions of the program, the mandatory part and the bonus part. The bonus part adds wall collision, a minimap, and the ability to rotate the view by moving the mouse.

To compile the mandatory part, `cd` into the cloned directory and:

```shell
make
```

To run the program:

```shell
./cub3d /map <path/to/map.cub>
```

The program takes a map file as an argument. Maps are available in the `maps` directory. 
There are only three maps, a little one, a square one, and a real one, where that you can finish the level by killing all the ennemies.

## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse (bonus only)
- `E`: open doors
- `F`: fire
- `C`: change weapons
- `1`,`2`,`3`,`4`,`5`: select wespons
- `P`: pause
- `ECHAP` : quit


