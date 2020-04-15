#include<iostream>
using namespace std;

class Game
{
    public:
    char grid[25][25];
    int start_row, start_col;
    int end_row, end_col;
    int ROW, COL;

    void input()
    {
        cout<<"Enter no. of rows and columns in maze";
        cin>>ROW>>COL;
        cout<<"Put start and end rows and columns";
        cin>>start_row>>start_col>>end_row>>end_col;

    
        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j<COL; j++)
            {
                cin>>grid[i][j];
            }
        }
    }
    bool solve(int row, int col)
    {
        bool flagu=false, flagd=false, flagr=false, flagl=false;
        if(((row+1)<ROW)&&(grid[row+1][col]!='-')&&(grid[row+1][col]!='|'))
        {
            //cout<<"down"<<endl;
            grid[row+1][col]='-';
            //display();
            if(((row+1)==end_row)&&(col==end_col))
                return true;
            if(((row+1)>=ROW)&&(col==COL))
                return false;
            flagd=solve(row+1, col);
            if(!flagd)
                grid[row+1][col]='.';
            //cout<<"flagd"<<flagd;
        }
        if(!flagd)
        if(((row-1)>=0)&&(grid[row-1][col]!='-')&&(grid[row-1][col]!='|'))
        {
            //cout<<"up"<<endl;
            grid[row-1][col]='-';
            //display();
            if(((row-1)==end_row)&&(col==end_col))
                return true;
            if(((row-1)<=ROW)&&(col==COL))
                return false;
            flagu=solve(row-1,col);
            if(!flagu)
                grid[row-1][col]='.';
            //cout<<"flagu"<<flagu;
        }
        if(!flagd&&!flagu)
        if(((col+1)<COL)&&(grid[row][col+1]!='-')&&(grid[row][col+1]!='|'))
        {
            //cout<<"right"<<endl;
            grid[row][col+1]='-';
            //display();
            if(((row)==end_row)&&((col+1)==end_col))
                return true;

            if(((row)==ROW)&&((col+1)>=COL))
                return false;

            flagr=solve(row, col+1);
            if(!flagr)
                grid[row][col+1]='.';
            //cout<<"flagr"<<flagr;
        }
        if(!flagd&&!flagu&&!flagr)
        if(((col-1)<COL)&&(grid[row][col-1]!='-')&&(grid[row][col-1]!='|'))
        {
            //cout<<"left"<<endl;
            grid[row][col-1]='-';
            //display();
            if(((row)==end_row)&&((col-1)==end_col))
                return true;
            if(((row)==ROW)&&((col-1)<=COL))
                return false;
                
            flagl=solve(row, col-1);
            if(!flagl)
                grid[row][col-1]='.';
            //cout<<"flagl"<<flagl;
        }
        if(flagu||flagl||flagd||flagr)
            return true;
        else
            return false;
    }
    void display()
    {
        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j<COL; j++)
            {
                if(((i==end_row)&&(j==end_col))||((i==start_row)&&(j==start_col)))
                    cout<<'x'<<" ";
                else
                    cout<<grid[i][j]<<" ";
            } cout<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    Game g;
    bool check;
    g.input();
    cout<<"Puzzle: \n";
    g.display();
    check=g.solve(g.start_row, g.start_col);
    
    if(check)
    {
        cout<<"\n Solved!\n";
        cout<<endl;
        g.display();
        
    } else
    {
        cout<<"\n No solution found\n";
    }
    
    return 0;
}
/*
Walls/ obstacles: |
Free blocks to travel on: .
Start/ End: x
Path found: - 
*/