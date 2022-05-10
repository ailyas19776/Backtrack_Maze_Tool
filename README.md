# Maze_Game

Begin by cd inside of the directory and typing "make" to compile the files
________________________________________________________________________________

Command Line Options:

-s  --stack

-q  --queue

-o [arg] --output [arg] [M/L]  (Map format/List format)

_______________________________________________________________________________


Example Commands:

./supermarco --stack --output L < maze_file.txt

./supermarco --queue --output M < maze_file2.txt

_______________________________________________________________________________


Key for maze_files:

'.' = empty (can walk on)

'!' = bridge (can walk on)

'#' = walls (no walk)

'S' = starting locatoin

'C' = concluding location

'0' - '9' = warp pipe to same spot of that integer's room


_______________________________________________________________________________


Example maze_file texts L:

L (List vs Map)

2 (Number of Rooms)

4 (Number of Columns and Rows)

//castle room 0

(0,0,1,C)//ROOM, ROW, COLUMN, CHARACTER (Coordinates-- all other coordinates default to '.')

(0,1,0,.)

(0,2,3,S)

(0,3,1,#)

(0,3,0,1)

(0,3,2,#)

//castle room 1

(1,1,0,#)

(1,1,1,!)

(1,2,0,#)

(1,2,3,.)



Example maze_file texts M:

M (Map vs List)

1 (Number of Rooms)

3 (3 x 3)

//castle room 0

..C 

#S#

#!#
