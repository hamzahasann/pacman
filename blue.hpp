class Blue:public Ghost{
    Red* red;
public:
    using Ghost::Ghost;
    void setRed(Red* _red){
        red=_red;
    }
    void loadTexture(){
        for(int i=0;i<8;i++){
            if(!texture[i/2][i%2].loadFromFile("../assets/spritesheet.png",IntRect(456+i*16,96,16,16))){
                cout<<"Cant load blue sprite\n";
            }
        }
    }pair<int,int>calcTarget()override{
        pair<int,int>loc1=player->getLocation();
        pair<int,int>loc2=red->getLocation();
        targetx=loc1.first+(loc2.first-loc1.first)*2;
        targety=loc1.second+(loc2.second-loc1.second)*2;
        return {targetx,targety};
    }
};
