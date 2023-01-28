#include <iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void add(vector<vector<int> >& matrix,int x,int y)
{
    if ( ( x >= 0 && x < matrix.size() ) &&
         ( y >= 0 && y < matrix[x].size() ) && 
         ( matrix[x][y] != -1 ) )
        matrix[x][y]++;
    
}

void compute_bomb(vector<vector<int> >& matrix,pair<int,int> bomb)
{
    int x = bomb.first ;
    int y = bomb.second;

    add(matrix,x-1,y-1);
    add(matrix,x,y-1);
    add(matrix,x+1,y-1);
    add(matrix,x+1,y);
    add(matrix,x+1,y+1);
    add(matrix,x,y+1);
    add(matrix,x-1,y+1);
    add(matrix,x-1,y);

}


int main(){

    int size_x,size_y;
    vector< vector<int> > matrix;

    vector< pair<int,int> > bombs;

    int field = 1;
    while(true)
    {
        cin >>size_x >>size_y;
        if ( size_x == 0 && size_y == 0)
            break;

        if ( field != 1 )
            cout<<"\n";        
        // cout<<size_x<<" --- "<<size_y<<endl;

        cout<<"Field #"<<field<<":\n";

        matrix.resize(size_x);
        for (int x = 0; x < size_x; x++)
            matrix[x].resize(size_y);

        for (int r = 0; r < size_x; r++)
        {
            for (int c = 0; c < size_y; c++)
            {
                char k;
                cin >> k;
                // cout<<k<<endl;
                // // matrix[r].push_back(k);
                if (k == '*')
                {
                    bombs.push_back(make_pair(r,c));
                    matrix[r][c] = -1;
                }
                else
                    matrix[r][c] = 0;
            }
        }

        for (int i=0; i<bombs.size(); i++)
        {
            compute_bomb(matrix,bombs[i]);

        // for (int r = 0; r < size_x; r++)
        // {
        //     for (int c = 0; c < size_y; c++)
        //     {
        //         if (matrix[r][c]==-1)
        //             cout<<"*";
        //         else
        //             cout << matrix[r][c];
        //     }
        //     cout<< "\n";
        // }
        }

        for (int r = 0; r < size_x; r++)
        {
            for (int c = 0; c < size_y; c++)
            {
                if (matrix[r][c]==-1)
                    cout<<"*";
                else
                    cout << matrix[r][c];
            }
            cout<< "\n";
        }
        bombs.clear();
        field++;
    }

    return 0;
}
