## Generate maze (recursive segmentation algorithm):

1. Create a maze which has size determined by the user input.
2. Select random x, y coordinates and draw a cross made by walls
3. Randomly choose to break three of the walls to form routes.
4. Four regions divided by the cross are divided again by using recursion, until they are not big enough.
5. Draw the maze.


## Search routes (recursion):
1. A robot is created at the fixed entrance.
2. When the robot is not at the exit, on each grid, turn left and check if it can go forward to pass to the next grid.
3. If there is a wall on the left, keep turning right till it finds a route to go.
4. Stop at the exit.


## Commands:

compile:
gcc -o coursework coursework.c graphics.c  
run:
./coursework 20 | java -jar drawapp-2.0.jar
(The input denotes the size of maze. It can be changed.)

For mac users, try to run with:
./coursework.out 20 | java -jar drawapp-2.0.jar
For Windows users, try to run with:
./coursework.exe 20 | java -jar drawapp-2.0.jar
