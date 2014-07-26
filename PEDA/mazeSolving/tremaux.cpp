  
#include <stdlib.h>				// allows use of = clrscreen();
#include <conio.h>
#include <fstream>
#include <iostream.h>
#include <iomanip> 

#include <stack.h>

#include "clear.h"


using namespace std;
void Traverse( char[][80], int, int, int);
void Maze(const char[][80]);
bool validmove(const char[][80],int,int);               
bool Edge (int,int);
enum direction {DOWN,RIGHT,UP,LEFT};  //0,1,2,3
const int x = 2;
const int y = 0;
////****Main****////

 void pushX(int);
 void pushY(int);
 

int main()
   {
       char maze[25][80]; 
                    
                        
                        
                         
                       
   ifstream infile;
   infile.open("25X80_1.txt");
 
    for (int i = 0; i < 25; i++) {
         for (int j = 0; j < 80; j++) {
                     infile>>maze[i][j];   
                   }
                    //cout<<'\n'; 
            }
    
    Traverse(maze,x,y,RIGHT);                       
        
    system("PAUSE");
    return 0;
}

 
void Traverse(char maze[][80], int xlocation, int ylocation, int direction)  
 {
       
        stack< int > s;       
        
        
    	maze[xlocation][ylocation]='Ü';   
       
       cout<<"Determining current state "<<endl<<"Array"; 
       pushX(xlocation);
       pushY(ylocation);
        
       cout<<endl<<endl;
                    
       
         
       //popY(ylocation);
    //  popX(xlocation);  
       
         cout<<endl<<endl;
        
     	Maze(maze); 
     	 clrscreen();
       // pushArray();   
           
           
           
    if (Edge(xlocation,ylocation) && xlocation!=x && ylocation!=y)  
         {
        	cout<<"Maze game SOLVED!!! \n";  
               
            return;
          }
               else {
             	
                  	for (int move =direction,count=0;count<4;count++,move++,move%=4)   
                  
                      switch (move)   

                                       	{
                                	case DOWN:
                	                          	if ( validmove(maze,xlocation+1,ylocation) ) 
                                                    {
                    	                                Traverse(maze,xlocation+1,ylocation,LEFT);
                	                                       return;
                                                        }
                                                      break;
                                     
                                     
                                     
                                     
                                 	case RIGHT:
                	                        	if (validmove(maze,xlocation,ylocation+1))
                                                    {
                    	                               	Traverse(maze,xlocation,ylocation+1,DOWN);
                                                           return;
                                                       }

                                                       	break;
                                                                   	
                                   	case UP:
                		                       if (validmove(maze,xlocation-1,ylocation))
                                                  {
                    	                                Traverse(maze,xlocation-1,ylocation,RIGHT);
                    	                                 return;
                                                           }
                                                     	break;
                                                                       	
                                                                       	
                	               case LEFT:
                		                      if (validmove(maze,xlocation,ylocation-1))
                                                    {
                    	                             	Traverse(maze,xlocation,ylocation-1,UP);
                                                         return;
                                                     }
                                                     	break;
                	               	}    //end switch
                              	}      //end for loop
                             }    //end Travers function




           
     bool validmove(const char maze[][80],int r, int c)    
              {
                return (r>=0 && r<=24 && c>=0 && c<=79 && maze[r][c]!='*');       
              }

    

     bool Edge(int x ,int y)   
            {
               if ((x==0||x==24)&&(y>=0&&y<=79))
                return true;
                else if ((y==0||y==79)&&(x>=0&&x<=24)) 
                return true;
                else
                return false;
            }

      
      
     void Maze(const char maze[][80]) {

      
             


         for (int x=0;x<25;x++)  {
                    for (int y=0;y<80;y++)  {
                         cout<<maze[x][y];    
                        }  
                   cout<<'\n';
                }

                // cout<<"Press Enter for the next move\n";
               cin.get();
                 
            }

     void pushX(int x ){  //push row
       
           stack< int > s;   
            s.push( x );
          cout <<"["<<s.top()<<"]";
           
         }
     
     
     void pushY(int y ){    //push column
        stack< int > s;   
   
        s.push( y );
        cout <<"["<<s.top()<<"]";
      
}     
