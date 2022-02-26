class Pink:public Ghost{
public:
    using Ghost::Ghost;
    void loadTexture(){
        for(int i=0;i<8;i++){
            if(!texture[i/2][i%2].loadFromFile("../assets/spritesheet.png",IntRect(456+i*16,80,16,16))){
                cout<<"Cant load pink sprite\n";
            }
        }
    }pair<int,int>calcTarget()override{
        pair<int,int>loc=player->getLocation();
        int x=loc.first,y=loc.second;
        Direction direction=player->getDirection();
        if(direction==LEFT){
            return {x-PINKDIST,y};
        }else if(direction==RIGHT){
            return {x+PINKDIST,y};
        }else if(direction==UP){
            return {x,y-PINKDIST};
        }else if(direction==DOWN){
            return {x,y+PINKDIST};
        }
    }
};
