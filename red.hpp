class Red:public Ghost{
public:
    using Ghost::Ghost;
    void loadTexture(){
        for(int i=0;i<8;i++){
            if(!texture[i/2][i%2].loadFromFile("../assets/spritesheet.png",IntRect(456+i*16,64,16,16))){
                cout<<"Cant load red sprite\n";
            }
        }
    }pair<int,int>calcTarget()override{
        return player->getLocation();
    }
};
