class Orange:public Ghost{
public:
    using Ghost::Ghost;
    void loadTexture(){
        for(int i=0;i<8;i++){
            if(!texture[i/2][i%2].loadFromFile("../assets/spritesheet.png",IntRect(456+i*16,112,16,16))){
                cout<<"Cant load orange sprite\n";
            }
        }
    }pair<int,int>calcTarget()override{
        pair<int,int>loc=player->getLocation();
        if((loc.first-x/CELLSIZE)*(loc.first-x/CELLSIZE)+(loc.second-y/CELLSIZE)*(loc.second-y/CELLSIZE)>=ORANGEDIST*ORANGEDIST){
            targetx=loc.first;
            targety=loc.second;
        }else{
            targetx=2;
            targety=28;
        }return {targetx,targety};
    }
};
