#ifndef SURFACE_STATES_H
#define SURFACE_STATES_H

enum STATE{START = 0, FINISH = 1, WALL = 2, EMPTY = 3, GO = 4, CHECKED = 5, CLEAR = 6, WAYPOINT = 7};
const int WIDTH = 30;
const int HEIGHT = 15;
const int orthogonalTile = 10;
const int diagonalTile = 14;

const int START_POINT = 0;
const int FINISH_POINT = 1;
const int WALL_POINT = 2;
const int EMPTY_POINT = 3;
const int WAY_POINT = 4;
const int GRAS_OPENLIST = 5;
const int GRAS_LEE_OPENLIST = 6;
const int WAYPOINT_LEE = 7;

#endif // SURFACE_STATES_H
