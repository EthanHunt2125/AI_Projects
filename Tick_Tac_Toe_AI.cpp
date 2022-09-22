#include <bits/stdc++.h>
#include <stdio.h>
#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <fstream>
#include <iostream>
#include <queue>  // Provides the queue template class
#include <stack>
#include <string>

using namespace std;
// finds the location of the target number and returns position vector


int* get_neighbors(int **arr, int r, int c ,int** graph, int size){
    int* pv= new int[2];
    int min=arr[r][c];
    int sum=0;
    //GET TOP
    pv[0]=r;
        pv[1]=c;
    if(r>0){
        ///if(graph[r-1][c]==0){
        if(arr[r-1][c]<min && arr[r-1][c]!=0){
        pv[0]=r-1;
        pv[1]=c;
        min=arr[r-1][c] ;
        }
     //   }
        
        
        
       
    }
    //get bottom
    if(r<size-1){
      //  if(graph[r+1][c]==0){
        if(arr[r+1][c]<min && arr[r+1][c]!=0){
        pv[0]=r+1;
        pv[1]=c;
        min=arr[r+1][c] ;
        }
       // }
       
    }
    //get mid
     if(c<size-1){
       // if(graph[r][c+1]==0){
        if(arr[r][c+1]<min&& arr[r][c+1]!=0){
        pv[0]=r;
        pv[1]=c+1;
        min=arr[r][c+1] ;
        }
      //  }
        
        }
        if(c>0){
       // if(graph[r][c-1]==0){
        if(arr[r][c-1]<min&& arr[r][c-1]!=0){
        pv[0]=r;
        pv[1]=c-1;
        min=arr[r][c-1] ;
        }
        //}
        }return pv;}


int** new_arr(int size) {
  int** arr;
  arr = new int*[size];

  for (int i = 0; i < size; i++) {
    arr[i] = new int[size];
  }
  return arr;
}

int** copy_arr(int** arr,int**copy, int size) {
  

  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      copy[i][y]=arr[i][y]; 
  }
  }
  return copy;
}

int compute_offensive_score(int** arr, int r, int c , int size ) {
    int** grid=new_arr(size);
    grid=copy_arr(arr,grid,size);
    int o_score=0;
    
    if(grid[r][c]==-1){
        
        
       return -1; 
    }
    else if(grid[r][c]==0){
    grid[r][c]=1;    
        
    }
    else{
        
        return 0;
    }
    // Top row
    if(r==0){
    //cout<<"Row one"<<endl;
    // first column
    if(c==0){
    //cout<<"Column One"<<endl;
    //row goal one
    if((grid[r][c+1]> -1) && (grid[r][c+2]> -1) ){
      
    if((grid[r][c+1] && grid[r][c+2]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r+1][c]> -1) && (grid[r+2][c]> -1) ){
      
    if((grid[r+1][c] && grid[r+2][c]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // diagonal left goal
     if((grid[r+1][c+1]> -1) && (grid[r+1][c+2]> -1) ){
      
    if((grid[r+1][c+1] && grid[r+2][c+2]) == 1){
        o_score=9;  
        grid[r][c]=0;
        return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     
     
    } 
    else if(c==1){
   // cout<<"Column two"<<endl;
    //  row goal one
    if((grid[r][c-1]!= -1) && (grid[r][c+1]!= -1) ){
      
    if((grid[r][c-1] && grid[r][c+1]) == 1){
        o_score=9;  
        grid[r][c]=0;
        return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r+1][c]!= -1) && (grid[r+2][c]!= -1) ){
      
    if((grid[r+1][c] && grid[r+2][c]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     
    }  
    else if(c==2){
   // cout<<"Column 3"<<endl;   
    if((grid[r][c-1]!= -1) && (grid[r][c-2]!= -1) ){
      
    if((grid[r][c-1] && grid[r][c-2]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r+1][c]!= -1) && (grid[r+2][c]!= -1) ){
      
    if((grid[r+1][c] && grid[r+2][c]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   \
     // right diagonal 
    if((grid[r+1][c-1]!= -1) && (grid[r+2][c-2]!= -1) ){
      
    if((grid[r+1][c-1] && grid[r+2][c-2]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
    
    } 
    return o_score;
    }
    
    else if(r==1){
    //cout<<"row two"<<endl;
    // first column
    if(c==0){
    //cout<<"Column One"<<endl;
    //row goal two
    if((grid[r][c+1]> -1) && (grid[r][c+2]> -1) ){
      
    if((grid[r][c+1] && grid[r][c+2]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r+1][c]> -1) && (grid[r-1][c]> -1) ){
      
    if((grid[r+1][c] && grid[r-1][c]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     
        
     
     
    } 
    else if(c==1){
   // cout<<"Column 2"<<endl;
    //  row goal two
    if((grid[r][c-1]> -1) && (grid[r][c+1]> -1) ){
      
    if((grid[r][c-1] && grid[r][c+1]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r-1][c]> -1) && (grid[r+1][c]> -1) ){
      
    if((grid[r-1][c] && grid[r+1][c]) == 1){
        o_score=9;  
      grid[r][c]=0;
    return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // left diagonal 
     if((grid[r-1][c-1]> -1) && (grid[r+1][c+1]> -1) ){
      
    if((grid[r-1][c-1] && grid[r+1][c+1]) == 1){
        o_score=9;  
      grid[r][c]=0;
    return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // right diagonal
     if((grid[r+1][c-1]> -1) && (grid[r-1][c+1]> -1) ){
      
    if((grid[r+1][c-1] && grid[r-1][c+1]) == 1){
        o_score=9; 
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     
     
     
     
    }  
    else if(c==2){
   //   cout<<"Column 3"<<endl; 
    if((grid[r][c-1]> -1) && (grid[r][c-2]> -1) ){
      
    if((grid[r][c-1] && grid[r][c-2]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r+1][c]> -1) && (grid[r-1][c]> -1) ){
      
    if((grid[r+1][c] && grid[r-1][c]) == 1){
        o_score=9; 
        grid[r][c]=0; 
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }    
    } 
    return o_score;
    }
    
    else if(r==2){
    //cout<<"row 3"<<endl;
        // first column
    if(c==0){
   // cout<<"Column One"<<endl;
    //row goal one
    if((grid[r][c+1]> -1) && (grid[r][c+2]> -1) ){
      
    if((grid[r][c+1] && grid[r][c+2]) == 1){
        o_score=9;  
       grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r-1][c]> -1) && (grid[r-2][c]> -1) ){
      
    if((grid[r-1][c] && grid[r-2][c]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // diagonal right goal
     if((grid[r-1][c+1]> -1) && (grid[r-2][c+2]> -1) ){
      
    if((grid[r-1][c+1] && grid[r-2][c+2]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     
     
    } 
    else if(c==1){
    //cout<<"Column 2"<<endl;
        //  row goal one
    if((grid[r][c-1]> -1) && (grid[r][c+1]> -1) ){
      
    if((grid[r][c-1] && grid[r][c+1]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r-1][c]> -1) && (grid[r-2][c]> -1) ){
      
    if((grid[r-1][c] && grid[r-2][c]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     
    }  
    else if(c==2){
     //  cout<<"Column 3"<<endl;
        if((grid[r][c-1]> -1) && (grid[r][c-2]> -1) ){
      
    if((grid[r][c-1] && grid[r][c-2]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
     // column goal one
     if((grid[r-1][c]> -1) && (grid[r-2][c]> -1) ){
      
    if((grid[r-1][c] && grid[r-2][c]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   \
     // right diagonal 
    if((grid[r-1][c-1]> -1) && (grid[r-2][c-2]> -1) ){
      
    if((grid[r-1][c-1] && grid[r-2][c-2]) == 1){
        o_score=9;  
        grid[r][c]=0;
       return o_score;   
          
      }   
       else{
           o_score++;
           
       }  
         
     }   
    
    } 
    return o_score;
    }
    
    
    
    
    grid[r][c]=0;
   
  

  return o_score;
}




// print matrix
void print_arr(int size, int** grid) {
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      cout << grid[i][y] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void print_arr2(int size, int** grid) {
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
    if( grid[i][y]==1){
        cout<<"X|";
    }
    else if( grid[i][y]==-1){
        cout<<"O|";
    }
    else{
        cout<<" |";
        
    }
    }
    cout << endl;
  }
  
}

void find_num(int** arr, int size) {

 int** copy=new_arr(size);
    copy=copy_arr(arr,copy,size);
    int max=0;
    
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      
        if(max<compute_offensive_score(copy,i,y,size)){
          
      }
        cout<<" ";
       // print_arr(3,copy);
        
    }
  cout<<endl;
  }


}


int* find_move(int** arr, int** enemy, int size) {

 int** copy=new_arr(size);
 int** enemy_c=new_arr(size);
    copy=copy_arr(arr,copy,size);
    enemy_c=copy_arr(enemy,enemy_c,size);
    int max=0;
    int* move= new int[2];
    int value=0; 
    
  
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      if(copy[i][y]==0){
        value=(compute_offensive_score(copy,i,y,size)+compute_offensive_score(enemy_c,i,y,size));
        //cout<<value<<"|";
        if(max<value){
          max=value;
          move[0]=i;
          move[1]=y;
      }  
      }
        
        
       
        
    }
  //cout<<endl;
  }
//cout<<endl;
return move;
}





int* sub_game(int** grid, int** enemy, int size) {
  int i = 0;
  int j = 0;
  int count = 0;
  int temp;
  int* sv = new int[2];
  int* start_vector = new int[2];     // give location of zero at start
  int* position_vector = new int[2];  // give loction of current zero
  int y_start;
  int num;
  

  position_vector[0] = start_vector[0];
  position_vector[1] = start_vector[1];

  
    
    
  
    position_vector=find_move(grid,enemy,size);
   // grid[position_vector[0]][position_vector[1]]=1;
   // enemy[position_vector[0]][position_vector[1]]=-1;
   // print_arr2(size, grid);
    
    //print_arr2(size, enemy);
    
  return position_vector;
}

int* find_move2(int** arr, int** enemy, int size) {

 int** copy=new_arr(size);
 int** copy2=new_arr(size);
 int** enemy_c=new_arr(size);
 int** enemy_c2=new_arr(size);
    copy=copy_arr(arr,copy,size);
    copy2=copy_arr(arr,copy2,size);
    enemy_c=copy_arr(enemy,enemy_c,size);
    enemy_c2=copy_arr(enemy,enemy_c2,size);
    int max=0;
    int* move= new int[2];
    int value=0; 
    int value2=0;
    int* temp= new int[2];
  
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
       
        value= (compute_offensive_score(copy,i,y,size)+compute_offensive_score(enemy_c,i,y,size));
        
        copy2[i][y]=1;
        enemy_c2[i][y]=-1;
        temp=sub_game(enemy_c2,copy2,size);
        //temp=find_move(copy2,enemy_c2,size);
        value2=compute_offensive_score(enemy_c2,temp[0],temp[1],size);
        value=value-value2;
        if(max<value){
          max=value;
          move[0]=i;
          move[1]=y;
      }
      
       copy2=copy_arr(copy,copy2,size);
       enemy_c2=copy_arr(enemy_c,enemy_c2,size);
        
    }
  
  }

return move;
}



// set all numbers in an matrix to zero
int** set_arr(int size, int** grid) {
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      grid[i][y] = 0;
    }
  }
  return grid;
}
// sets numbers all the -1 randomly into the main matrix
int** set_arr2(int size, int** grid) {
  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      grid[i][y] = -1;
    }
  }
  return grid;
}
// makes goal matirx
int** set_goal(int size, int** grid) {
  
    
  grid[0][0] = 0; grid[0][1] = -1; grid[0][2] = 0;
  grid[1][0] = 1; grid[1][1] = 0; grid[1][2] = -1;
  grid[2][0] = 0; grid[2][1] = 1; grid[2][2] = 0;

  return grid;
}
// makes new matrix

// checks if a node is visited
bool has_visted(int node) {
  if (node == 1) {
    return true;

  } else {
    return false;
  }
}
// checks graph fillin progress
bool check_graph(int size, int** graph) {
  int count = 0;

  for (int i = 0; i < size; i++) {
    for (int y = 0; y < size; y++) {
      if (has_visted(graph[i][y])) {
        count++;
      }
    }
  }
  if (count == size * size) {
    return true;
  }

  return false;
}
// sets numbers all the 0-8 randomly into main matrix
int** fill_arr(int size, int** arr, int** graph) {
  int value = 0;
  int count_1 = 0;
  int count_2 = 0;
  int count_3 = 0;
  int count_4 = 0;
  int count_5 = 0;
  int count_6 = 0;
  int count_7 = 0;
  int count_8 = 0;
  int count_0 = 0;
  bool con = false;
  int i = 0;
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      con = false;
      if (!has_visted(graph[r][c])) {
        // print_arr(size,graph);

        while (!con) {
          value = (rand() % 9);
          if (count_1 == 0 && value == 1) {
            // cout<<value<<endl;
            arr[r][c] = value;
            count_1++;
            con = true;
          } else if (count_2 == 0 && value == 2) {
            arr[r][c] = value;
            //  cout<<value<<endl;
            count_2++;
            con = true;
          } else if (count_3 == 0 && value == 3) {
            // cout<<value<<endl;
            arr[r][c] = value;
            count_3++;
            con = true;
          } else if (count_4 == 0 && value == 4) {
            //  cout<<value<<endl;
            arr[r][c] = value;
            con = true;
            count_4++;
          } else if (count_5 == 0 && value == 5) {
            //  cout<<value<<endl;
            arr[r][c] = value;
            con = true;
            count_5++;
          } else if (count_6 == 0 && value == 6) {
            //   cout<<value<<endl;
            arr[r][c] = value;

            count_6++;
            con = true;
          } else if (count_7 == 0 && value == 7) {
            //   cout<<value<<endl;
            arr[r][c] = value;
            count_7++;
            con = true;
          } else if (count_8 == 0 && value == 8) {
            //   cout<<value<<endl;
            arr[r][c] = value;
            count_8++;
            con = true;
          } else if (count_0 == 0 && value == 0) {
            //   cout<<value<<endl;
            arr[r][c] = value;
            count_0++;
            con = true;
          }
        }
        graph[r][c] = 1;
      }
    }
  }

  return arr;
}
//checks is a goal istance is meet
bool is_solved(int** grid, int size) {
 
      if ( grid[0][0]==1 && grid[0][1]==1 && grid[0][2]==1){
          cout<<"YOU WIN "<<endl;
          return true;
          
          
      }
      else  if ( grid[1][0]==1 && grid[1][1]==1 && grid[1][2]==1){
          cout<<"YOU WIN "<<endl;
          return true;
          
          
      }  
      else  if ( grid[2][0]==1 && grid[2][1]==1 && grid[2][2]==1){
          cout<<"YOU WIN "<<endl;
          return true;
          
          
      }
      else if ( grid[0][0]==1 && grid[1][0]==1 && grid[2][0]==1){
          cout<<"YOU WIN "<<endl;
          return true;
          
          
      }
     else if ( grid[0][1]==1 && grid[1][1]==1 && grid[2][1]==1){
         cout<<"YOU WIN "<<endl;
         return true;
          
          
      }
     else if ( grid[0][2]==1 && grid[1][2]==1 && grid[2][2]==1){
         cout<<"YOU WIN "<<endl; 
         return true;
          
          
      }
     else if ( grid[0][0]==1 && grid[1][1]==1 && grid[2][2]==1){
         cout<<"YOU WIN "<<endl; 
         return true;
          
          
      }
     else if ( grid[2][0]==1 && grid[1][1]==1 && grid[0][2]==1){
         cout<<"YOU WIN "<<endl; 
         return true;
          
          
      }
      else{
          return false;
      }
      
}

bool is_solved2(int** grid, int size) {
 
      if ( grid[0][0]==1 && grid[0][1]==1 && grid[0][2]==1){
          cout<<"YOU LOOSE "<<endl;
          return true;
          
          
      }
      else  if ( grid[1][0]==1 && grid[1][1]==1 && grid[1][2]==1){
          cout<<"YOU LOOSE "<<endl;
          return true;
          
          
      }  
      else  if ( grid[2][0]==1 && grid[2][1]==1 && grid[2][2]==1){
         cout<<"YOU LOOSE "<<endl;
          return true;
          
          
      }
      else if ( grid[0][0]==1 && grid[1][0]==1 && grid[2][0]==1){
          cout<<"YOU LOOSE "<<endl;
          return true;
          
          
      }
     else if ( grid[0][1]==1 && grid[1][1]==1 && grid[2][1]==1){
         cout<<"YOU LOOSE "<<endl;
         return true;
          
          
      }
     else if ( grid[0][2]==1 && grid[1][2]==1 && grid[2][2]==1){
         cout<<"YOU LOOSE "<<endl;
         return true;
          
          
      }
     else if ( grid[0][0]==1 && grid[1][1]==1 && grid[2][2]==1){
         cout<<"YOU LOOSE "<<endl;
         return true;
          
          
      }
     else if ( grid[2][0]==1 && grid[1][1]==1 && grid[0][2]==1){
         cout<<"YOU LOOSE "<<endl; 
         return true;
          
          
      }
      else{
          return false;
      }
      
}

// full puzzle implementing all functions and algorithm
void Full_game(int** grid, int** enemy, int size) {
  int i = 0;
  int j = 0;
  int count = 0;
  int temp;
  int* sv = new int[2];
  int* start_vector = new int[2];     // give location of zero at start
  int* position_vector = new int[2];  // give loction of current zero
  int y_start;
  int num;
  

  position_vector[0] = start_vector[0];
  position_vector[1] = start_vector[1];

  while (!is_solved2(grid, size) && !is_solved(enemy, size) && count < 9) {
    
    if(count%2==0){
    cout<<"Enter move"<<endl;
    cin>>position_vector[0];
    cin>>position_vector[1];
    grid[position_vector[0]][position_vector[1]]=-1;
    enemy[position_vector[0]][position_vector[1]]=1;     
    }
    else{
    position_vector=find_move(grid,enemy,size);
    grid[position_vector[0]][position_vector[1]]=1;
    enemy[position_vector[0]][position_vector[1]]=-1;
    }
    
    print_arr2(size, enemy);
    cout << "----------------------" << endl;
    count++;
    if(count==9){
        cout<<"Draw - Good Game"<<endl;
        
    }
  }
  
}

void Full_game3(int** grid, int** enemy, int size) {
  int i = 0;
  int j = 0;
  int count = 0;
  int temp;
  int* sv = new int[2];
  int* start_vector = new int[2];     // give location of zero at start
  int* position_vector = new int[2];  // give loction of current zero
  int y_start;
  int num;
  

  position_vector[0] = start_vector[0];
  position_vector[1] = start_vector[1];

  while (!is_solved2(grid, size) && !is_solved2(enemy, size) && count < 9) {
    
    if(count%2==0){
    cout<<"Enter move"<<endl;
    cin>>position_vector[0];
    cin>>position_vector[1];
    grid[position_vector[0]][position_vector[1]]=-1;
    enemy[position_vector[0]][position_vector[1]]=1;     
    }
    else{
    position_vector=find_move(grid,enemy,size);
    grid[position_vector[0]][position_vector[1]]=1;
    enemy[position_vector[0]][position_vector[1]]=-1;
    }
    
    print_arr2(size, enemy);
    cout << "----------------------" << endl;
    count++;
    if(count==9){
        cout<<"You win - Good Game"<<endl;
        
    }
  }
  
}

void Full_game2(int** grid, int** enemy, int size) {
  int i = 0;
  int j = 0;
  int count = 0;
  int temp;
  int* sv = new int[2];
  int* start_vector = new int[2];     // give location of zero at start
  int* position_vector = new int[2];  // give loction of current zero
  int y_start;
  int num;
  

  position_vector[0] = start_vector[0];
  position_vector[1] = start_vector[1];

  while (!is_solved2(grid, size) && !is_solved(enemy, size) && count < 9) {
    
    if(count%2==0){
    cout<<"Enter move"<<endl;
    cin>>position_vector[0];
    cin>>position_vector[1];
    grid[position_vector[0]][position_vector[1]]=-1;
    enemy[position_vector[0]][position_vector[1]]=1;     
    }
    else{
    position_vector=find_move2(grid,enemy,size);
    grid[position_vector[0]][position_vector[1]]=1;
    enemy[position_vector[0]][position_vector[1]]=-1;
    }
    
    print_arr2(size, enemy);
    cout << "----------------------" << endl;
    count++;
    if(count==9){
        cout<<"Draw - Good Game"<<endl;
        
    }
  }
  
}

int main()  // driver code

{
  int input;
 
  int** goal = new_arr(3);
  int** player=new_arr(3);
  int** ai=new_arr(3);
  player=set_arr(3,player);
  ai=set_arr(3,ai);
  goal = set_goal(3, goal);
  
  cout << " Tick-Tac-Toe AGENT " << endl;
  cout << "----------------------" << endl;
  cout << " Option Select " << endl;
  cout << " 1-Play Game(EASY) " << endl;
  cout << " 2-Play Game(HARD) " << endl;
  cout << " 3-Play Game(AON) " << endl;
  cout << " 0-Quit Program " << endl;
  cout << "Enter Selction:";
  cin >> input;
  do {
    cout << "----------------------" << endl;
    
    

    if (input == 1) {
        player=set_arr(3,player);
        ai=set_arr(3,ai);
        Full_game(player,ai, 3);
        
    
    

    } 
    
    if (input == 2) {
        player=set_arr(3,player);
        ai=set_arr(3,ai);
        Full_game2(player,ai, 3);
        
    
    

    } 
    if (input == 3) {
        player=set_arr(3,player);
        ai=set_arr(3,ai);
        Full_game3(player,ai, 3);
        
    
    

    } 
    
    else if (input == 0) {
      cout << "THANKS..." << endl;
    } 
    else {
      cout << "invalid option" << endl;
    }
    cin >> input;
  
    
  } while (input != 0);
  return 0;
}
