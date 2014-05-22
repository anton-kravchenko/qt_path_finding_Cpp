#include "findway.h"

FindWay::FindWay()
{

//    dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;// right, down, left, up
//    dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

    dir[0] = -WIDTH;
    dir[1] = 1;
    dir[2] = WIDTH;
    dir[3] = -1;

}
void FindWay::setWeight(Widget **grid, int num, bool &stop, int &d)
{
    if(EMPTY == grid[num]->state || FINISH == grid[num]->state)
    {
        stop = false;
        grid[num]->weight = d + 1;
        grid[num]->state = CHECKED;

    }
}

bool FindWay::find_path(Widget **grid, int start, int finish)
{
    length = 0;
    bool stop;

    int d, k;
    grid[start]->weight = 0;
    d=0;

    do{
        stop = true;
    for(int num = 0; num < HEIGHT * WIDTH; num++)
        if (grid[num]->weight == d)
            for(k=0; k < 4; k++)
            {
                if(grid[num+dir[k]]->state != WALL)
                grid[(num + dir[k])]->setImage(GRAS_LEE_OPENLIST);
                switch(k)
                {
                case 0:
                    if((num + dir[k]) >= 0)
                        setWeight(grid, num+dir[k], stop, d);
                    break;
                case 1:
                    if(((num % WIDTH) + dir[k]) < WIDTH)
                        setWeight(grid, num+dir[k], stop, d);
                    break;
                case 2:
                    if(num+dir[k] < WIDTH*HEIGHT)
                        setWeight(grid, num+dir[k], stop, d);
                    break;
                case 3:
                    if(((num%WIDTH)+dir[k]) >= 0)
                        setWeight(grid, num+dir[k], stop, d);
                    break;
                }
            }
    d++;
    }while(!stop && (-1 == grid[finish]->weight));
//}while(!stop && grid[bx*W + by]->weight == -1);


    length = grid[finish]->weight;

    Widget* way[length+1];

    Widget* cur = grid[finish];
    d = length;
    while(d > 0)
    {
        way[d] = cur;
        if(d != length)
        {
            cur->setImage(WAYPOINT_LEE);
            cur->setState(WAYPOINT);
        }
        d--;
            for(k=0; k < 4; k++)
            {
                int num = cur->number;

                if((num+dir[k] >= 0) && (num+dir[k] < HEIGHT*WIDTH))
                if(d == grid[num+dir[k]]->weight)
            {
                cur = grid[num+dir[k]];
                break;
            }
        }
    }
    way[0] = grid[start];
    way[0]->setImage(START_POINT);
    grid[finish]->setImage(FINISH_POINT);
//		cout << "x = " << wayX[length-k] << "; y = " << wayY[length-k]<< '\n';
    return true;
}


