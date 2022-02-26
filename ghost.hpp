// enum Direction{LEFT=0,RIGHT,UP,DOWN};
enum Mode{SCATTER,CHASE};
class Ghost{
protected:
    int x,y,targetx,targety;
    Texture texture[4][2];
    int speed;
    Direction direction;
    Mode mode;
    Player* player;
    Map* map;
    int counter;
public:
    Ghost(int _x,int _y){
        x=_x;
        y=_y;
        direction=UP;
        mode=SCATTER;
        speed=GHOSTSPEED;
        counter=0;
    }void setPlayer(Player* _player){
        player=_player;
    }void setMap(Map* _map){
        map=_map;
    }pair<int,int>getLocation(){
        return {x/CELLSIZE,y/CELLSIZE};
    }void move(){
        switch(direction){
            case LEFT:
                x-=speed;
                break;
            case RIGHT:
                x+=speed;
                break;
            case UP:
                y-=speed;
                break;
            case DOWN:
                y+=speed;
                break;
        }
    }virtual pair<int,int>calcTarget(){
        return player->getLocation();
    }int dist(int x,int y){
        pair<int,int>loc=calcTarget();
        targetx=loc.first;
        targety=loc.second;
        int dx=targetx-x,dy=targety-y;
        return dx*dx+dy*dy;
    }void draw(RenderWindow &window){
        RectangleShape rect(Vector2f(CELLSIZE,CELLSIZE));
        rect.setOrigin(CELLSIZE/2,CELLSIZE/2);
        rect.setPosition(x,y);
        counter=(counter+1)%2;
        switch(direction){
            case LEFT:
                rect.setTexture(&texture[1][counter]);
                break;
            case RIGHT:
                rect.setTexture(&texture[0][counter]);
                break;
            case UP:
                rect.setTexture(&texture[2][counter]);
            case DOWN:
                rect.setTexture(&texture[3][counter]);
        }
        window.draw(rect);
    }void turn(){
        int d1=50000,d2=50000,d3=50000,d4=50000;
        if(map->isOpen(x-speed,y)){
            d1=dist(x/CELLSIZE-1,y/CELLSIZE);
        }if(map->isOpen(x+speed,y)){
            d2=dist(x/CELLSIZE+1,y/CELLSIZE);
        }if(map->isOpen(x,y-speed)){
            d3=dist(x/CELLSIZE,y/CELLSIZE-1);
        }if(map->isOpen(x,y+speed)){
            d4=dist(x/CELLSIZE,y/CELLSIZE+1);
        }if(direction==LEFT){
            if(d3<d1 && d3<=d4){
                direction=UP;
            }else if(d4<d1 && d4<d3){
                direction=DOWN;
            }
        }else if(direction==RIGHT){
            if(d3<d2 && d3<=d4){
                direction=UP;
            }else if(d4<d2 && d4<d3){
                direction=DOWN;
            }
        }else if(direction==UP){
            if(d1<d3 && d1<=d2){
                direction=LEFT;
            }else if(d2<d3 && d2<d1){
                direction=RIGHT;
            }
        }else if(direction==DOWN){
            if(d1<d4 && d1<=d2){
                direction=LEFT;
            }else if(d2<d4 && d2<d1){
                direction=RIGHT;
            }
        }
    }
    void update(){
        if((x-GHOSTSIZE)%CELLSIZE==0 && (y-GHOSTSIZE)%CELLSIZE==0){
            turn();
        }
    }

};
