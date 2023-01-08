#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int gridSize,  halfGrid;
static int windowSize = 750;

void makeHoles(int **maze,int x1,int y1,int x2,int y2, int x_split, int y_split){
    int directions[4]={0};
    directions[rand()%4]=1;
    for(int i=0; i<4; i++){
        if(directions[i] == 0){
            int x_copy = x_split;
            int y_copy = y_split;
            do{
                switch (i){
                    case 0: x_copy = x1 + rand()%(x_copy-x1); break;
                    case 1: y_copy = y_copy + 1 + rand()%(y2-y_copy); break;
                    case 2: x_copy = x_copy + 1 + rand()%(x2-x_copy); break;
                    case 3: y_copy = y1 + rand()%(y_copy-y1); break;}
            }while (maze[x_copy-1][y_copy] + maze[x_copy+1][y_copy] + maze[x_copy][y_copy-1] + maze[x_copy][y_copy+1] > 2);
            maze[x_copy][y_copy]=0;
        }
    }
}

void drawWall(int **maze,int x1,int y1,int x2,int y2){
    if(x2 - x1 <2 || y2 - y1 < 2)
        return;
    int x_split = x1 + 1 + rand()%(x2-x1-1);
    int y_split = y1 + 1 + rand()%(y2-y1-1);
    for(int i=x1; i<=x2; i++) maze[i][y_split]=1;
    for(int i=y1; i<=y2; i++) maze[x_split][i]=1;
    drawWall(maze, x1, y1, x_split - 1, y_split - 1);
    drawWall(maze, x_split + 1, y_split + 1, x2, y2);
    drawWall(maze, x_split + 1, y1, x2, y_split - 1);
    drawWall(maze, x1, y_split + 1, x_split - 1, y2);
    makeHoles(maze, x1, y1, x2, y2, x_split, y_split);
}

int ** mazeSetting(int **maze, int size){
    for(int i=0; i<size; i++){
        maze[0][i]=1;
        maze[i][0]=1;
        maze[size-1][i]=1;
        maze[i][size-1]=1;
    }
    drawWall(maze, 1,1, size-2, size-2);
    maze[1][0]=0;
    maze[size-2][size-1]=2;
    return maze;
}

int ** createMaze(int size){
    srand((unsigned)time(NULL));
    int **maze=(int**)malloc(size * sizeof(int*));
    for(int i=0;i<size;i++){
        maze[i]=(int*)calloc(size, sizeof(int));
    }
    return mazeSetting(maze, size);
}

void deleteMaze(int **maze, int size){
    for(int i=0;i<size;i++){
        free(maze[i]);
    }
    free(maze);
}

void drawMaze(int **maze, int size){
    setWindowSize(windowSize, windowSize);
    gridSize = windowSize / size;
    halfGrid = gridSize / 2;
    background();
    for (int x=0; x<size; x++){
        for (int y=0; y<size; y++){
            setColour(black);
            switch (maze[y][x]){
                case 0: drawRect(x*gridSize, y*gridSize, gridSize, gridSize); break;
                case 1: fillRect(x*gridSize, y*gridSize, gridSize, gridSize); break;
                case 2: setColour(gray); 
                    fillRect(x*gridSize, y*gridSize, gridSize, gridSize);
                    break;
            }
        }
    }
    foreground();
}

void drawDirectionUp(int x, int y){
    int x_coordinates[] = {x*gridSize, (x+1)*gridSize,x*gridSize+halfGrid};
    int y_coordinates[] = {(y+1)*gridSize, (y+1)*gridSize, y*gridSize};
    fillPolygon(3, x_coordinates, y_coordinates);
}

void drawDirectionRight(int x, int y){
    int x_coordinates[] = {x*gridSize, x*gridSize,(x+1)*gridSize};
    int y_coordinates[] = {y*gridSize, (y+1)*gridSize, y*gridSize+halfGrid};
    fillPolygon(3, x_coordinates, y_coordinates);
}

void drawDirectionDown(int x, int y){
    int x_coordinates[] = {x*gridSize, (x+1)*gridSize,x*gridSize+halfGrid};
    int y_coordinates[] = {y*gridSize, y*gridSize, (y+1)*gridSize};
    fillPolygon(3, x_coordinates, y_coordinates);
}

void drawDirectionLeft(int x, int y){
    int x_coordinates[] = {(x+1)*gridSize, (x+1)*gridSize,x*gridSize};
    int y_coordinates[] = {y*gridSize, (y+1)*gridSize, y*gridSize+halfGrid};
    fillPolygon(3, x_coordinates, y_coordinates);
}

void drawRobot(int x, int y, int direction){
    clear();
    setColour(green);
    switch (direction){
        case 1: drawDirectionUp(x, y); break;
        case 2: drawDirectionRight(x, y); break;
        case 3: drawDirectionDown(x, y); break;
        case 4: drawDirectionLeft(x, y); break;
    }
}

typedef struct Robot{
    int x;
    int y;
    int direction;
}Robot;

Robot* createRobot(int x, int y, int direction){
    Robot *robot = (Robot *)malloc(sizeof(Robot));
    robot -> x = x;
    robot -> y = y;
    robot -> direction = direction;
    drawRobot(x,y,direction);
    return robot;
}

void deleteRobot(Robot *robot){
    free(robot);
}

void forward(Robot *robot){
    switch (robot -> direction){
        case 1: robot -> y--; break;
        case 2: robot -> x++; break;
        case 3: robot -> y++; break;
        case 4: robot -> x--; break;
    }
    drawRobot(robot->x, robot->y, robot->direction);
}

void left(Robot *robot){
    robot->direction--;
    if (robot->direction==0){
        robot->direction = 4;
    }
    drawRobot(robot->x, robot->y, robot->direction);
}

void right(Robot *robot){
    robot->direction++;
    if (robot->direction==5){
        robot->direction = 1;
    }
    drawRobot(robot->x, robot->y, robot->direction);
}

int atExit(Robot *robot, int **maze){
    if (maze[robot->y][robot->x]==2){
        return 1;
    }
    return 0;
}

int canMoveForward(Robot *robot, int **maze){
    int xcoordinate = robot->x;
    int ycoordinate = robot->y;
    switch (robot -> direction){
        case 1: ycoordinate--; break;
        case 2: xcoordinate++; break;
        case 3: ycoordinate++; break;
        case 4: xcoordinate--; break;
    }
    return !(maze[ycoordinate][xcoordinate]==1);
}

int search(Robot *robot, int **maze){
    while(atExit(robot, maze)==0){
        left(robot);
        for (int i=0; i<3; i++){
            if (canMoveForward(robot,maze)){
                sleep(200);
                forward(robot);
                search(robot, maze);
            }
            right(robot);
        }
    }
    exit(0);
}

int main(int argc, char **argv){
    int defaultSize = 11;
    if (argc == 2){
        defaultSize = atoi(argv[1]);
    }
    int **maze = createMaze(defaultSize);
    drawMaze(maze, defaultSize);
    Robot *robot = createRobot(0,1,2);
    search(robot, maze);
    deleteRobot(robot);
    deleteMaze(maze, defaultSize);
}