class Map{
    int rows,cols;
    vector<vector<int>>cell;
    Texture texture;
    int size=24;
public:
    Map(){
        rows=MAPROWS;
        cols=MAPCOLS;
        cell.resize(rows,vector<int>(cols));
        if(!texture.loadFromFile("../assets/spritesheet.png",IntRect(228,0,228+224,288))){
            cout<<"Cant load map sprite\n";
        }Image image;
        image.loadFromFile("../assets/spritesheet.png");
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                int x1,y1,x2,y2;
                x1=c*8;y1=r*8;
                x2=c*8+8;y2=r*8+8;
                for(int x=x1;x<x2;x++){
                    for(int y=y1;y<y2;y++){
                        Color color=image.getPixel(x,y);
                        if(color==Color(255,183,174)){
                            cell[r][c]=1;
                        }else if(color==Color(33,33,255)){
                            cell[r][c]=2;
                        }
                    }
                }
            }
        }
    }void setCell(int i,int j,int k){
        cell[i][j]=k;
    }int getCell(int i,int j){
        return cell[i][j];
    }
    void draw(RenderWindow &window){
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(cell[r][c]==1){
                    CircleShape circle(PELLETSIZE,PELLETSIZE);
                    circle.setPosition(c*CELLSIZE+CELLSIZE/2-PELLETSIZE,r*CELLSIZE+CELLSIZE/2-PELLETSIZE);
                    circle.setFillColor(Color(150,50,250));
                    window.draw(circle);
                }if(cell[r][c]==2){
                    RectangleShape rect(Vector2f(CELLSIZE,CELLSIZE));
                    rect.setPosition(c*CELLSIZE,r*CELLSIZE);
                    rect.setFillColor(Color(33,33,255));
                    window.draw(rect);
                }
            }
        }
    }bool isOpen(int x,int y){
        x-=PLAYERSIZE;y-=PLAYERSIZE;
        if(
            cell[y/CELLSIZE][x/CELLSIZE]==2 ||
            cell[(y+CELLSIZE-1)/CELLSIZE][x/CELLSIZE]==2 ||
            cell[y/CELLSIZE][(x+CELLSIZE-1)/CELLSIZE]==2 ||
            cell[(y+CELLSIZE-1)/CELLSIZE][(x+CELLSIZE-1)/CELLSIZE]==2
        )return false;
        return true;
    }
};
