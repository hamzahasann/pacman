enum Direction{LEFT=0,RIGHT,UP,DOWN,NONE};
class Player{
    int x,y;
    Texture texture[4];
    int counter;
    const int size=PLAYERSIZE,speed=PLAYERSPEED;
    bool left,right,up,down;
    Direction direction;
    Map* map;
public:
    Player(int a,int b){
        x=a;y=b;
        left=right=up=down=0;
        if(!texture[0].loadFromFile("../assets/spritesheet.png",IntRect(455,0,15,15)) ||
        (!texture[1].loadFromFile("../assets/spritesheet.png",IntRect(472,0,15,15))) ||
        (!texture[2].loadFromFile("../assets/spritesheet.png",IntRect(488,0,15,15)))){
            cout<<"Cant load pacman sprite\n";
        }texture[3]=texture[1];
        counter=0;
        direction=RIGHT;
    }void setMap(Map* _map){
        map=_map;
    }pair<int,int>getLocation(){
            return {x/CELLSIZE,y/CELLSIZE};
    }Direction getDirection(){
        return direction;
    }void turn(Direction d){
        left=right=up=down=0;
        if(d==LEFT && (direction==UP || direction==DOWN) && map->isOpen(x-speed,y)){
            left=1;
            direction=LEFT;
        }else if(d==RIGHT && (direction==UP || direction==DOWN) && map->isOpen(x+speed,y)){
            right=1;
            direction=RIGHT;
        }else if(d==UP && (direction==LEFT || direction==RIGHT) && map->isOpen(x,y-speed)){
            up=1;
            direction=UP;
        }else if(d==DOWN && (direction==LEFT || direction==RIGHT) && map->isOpen(x,y+speed)){
            down=1;
            direction=DOWN;
        }
    }void move(){
        if(direction==LEFT && map->isOpen(x-speed,y)){
            x-=speed;
        }if(direction==RIGHT && map->isOpen(x+speed,y)){
            x+=speed;
        }if(direction==UP && map->isOpen(x,y-speed)){
            y-=speed;
        }if(direction==DOWN && map->isOpen(x,y+speed)){
            y+=speed;
        }if(map->getCell(y/CELLSIZE,x/CELLSIZE)==1){
            map->setCell(y/CELLSIZE,x/CELLSIZE,0);
        }
    }void draw(RenderWindow &window){
        RectangleShape shape(Vector2f(CELLSIZE,CELLSIZE));
        shape.setOrigin(CELLSIZE/2,CELLSIZE/2);
        shape.setPosition(x,y);
        shape.setTexture(&texture[counter/2]);
        switch(direction){
            case LEFT:
                shape.setRotation(180);
                break;
            case UP:
                shape.setRotation(-90);
                break;
            case DOWN:
                shape.setRotation(90);
                break;
        }
        window.draw(shape);
        counter=(counter+1)%8;
    }
};
