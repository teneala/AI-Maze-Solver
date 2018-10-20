// Teneala Spencer
// Algorithms Homework 2
// Created on 4/18/17.
// This algorithm was designed using lists to minimize the use of loops. The first list created is a list of every position in the array that has a zero.
// The subsequent lists are designed so that everything in each list has the same column. Ex: (1,2 | 2,2 | 3,2, | 5,2), (1,3 | 2,3 | 5,3)
// Then each element is compared from list to list to see if it the current element's row in list one matches the current element in list two
// It was written this way because if two positions have the same column and the corresponding positions are on the same row then they are corners
// From example one the corners would look like: (1,2 | 2,2 | 1,3 | 2,3), (2,2 | 5,2 | 2,3 | 5,3)

#include "binary.hpp"
#include <iostream>
#include <fstream>
#include <string>


// The node will be used to hold the positions of my zeros.
struct node
{
    int row;
    int col;
    node * next;
};

// Some of the following pointers are to mainly increment through my linked list of positions.
// That is the justification for some of their ambiguous names.

node * root = nullptr;
node * head1 = nullptr;
node * current2 = nullptr;
node * after2 = nullptr;
node * previous = nullptr;
node * after1 = nullptr;
node * list = nullptr;
node * current1 = nullptr;
node * temp = nullptr;

node * n = nullptr;
node * q = nullptr;
node * k = nullptr;
node* j = nullptr;


node **memory = new node*[2000]; // This declares a dynamically allocated 1D array of the type node pointer to store the memory address of the beginning of each list.





binaryA::binaryA()
{
    
}

binaryA::~binaryA()
{
    
}

stack::stack()
{
    
}

stack::~stack()
{
    
}



void::binaryA::writeData(int number, int width, int length)
{
    std::ofstream binaryOut;
    int product = width * length;    // this is used so it can know how many random ones and zeros to generate and store into the 2D array
    
    binaryOut.open("matrix.txt");
    
    
    for(int i = 0; i < product; i++)
    {
        number = rand() % 2;                  // generates random ones and zeros
        binaryOut << number << std::endl;     // prints to file
       
        
    }
    
    binaryOut.close();
}







int::binaryA::createArray( int width, int length, int **arr)
{
   std::ifstream binaryIn;
   binaryIn.open("matrix.txt");
    
    for( int i = 0; i < width; i++)         // loads the zeros from the file named 'matrix.tx' into the 2D array
        
        for( int j = 0; j < length; j++)
        {
            
            
            binaryIn >> arr[i][j];
            
            
            
            
        }
    
    binaryIn.close();
    return 0;
}





// The following function is used to create a linked list of the positions of where the zeros occur in the array
// After making the list it will generate individual lists from the original list of positions based on whether they have the same column
// If they have the same column, then they potential make a square with other positions that have the same row.
// Example: list one = (1,2 | 2,2 | 3,2), list two = (1,3 | 2,3, | 4,3) the resulting zeros would form corners at (1,2 | 2,2 | 1,3 | 3,2).
// This is because they would be paired according to first their column then their row.
// This is the reasoning behind having linked list of positions who's columns are the same.

void::stack::push(int length, int width, int **arr)
{
    
    for(int i = 0; i < width; i++)
        for(int j = 0; j < length; j++)
        {
          
            if(arr[i][j] == 0)          //checks to see where zeros are placed in the array
            {
                
                n = new node;           //if it is a zero create a new node
                
                if(temp == NULL)        //if temp is null make it point to the first new node
                {
                    temp = n;
                }
                
                n -> row = i;           //set the values in the new node equal to the position of the zero in the binary array
                n-> col = j;            //set the values in the new node equal to the position of the zero in the binary array
                n->next = n;            //increment the pointer
                temp->next = n;
                temp = n;
                
                if( root == NULL)
                {
                    root = n;
                    
                }

            }
        }
    
    temp->next = NULL;                  //make the last item equal to null
    k = root;
    
}

// The following function's time complexity is O(n^2) because of the two nested while loops.
// Although the loop contains an if statement, if statements are O(n) because they execute only once on condition
// The function is designed in order to create lists of positions that have the same columns

void::stack::find(int length)
{
    
    int i = 0;
    

    
    n = root;                   // Go to beginning of linked list of zero positions
 
    
    while( n  != NULL )
    {
        
        list = new node;            //create a new node.
        list -> row = n -> row;     // set whatever n is pointing, which it is pointing to the original list, equal to the contents of the new node which is the position of the zero
                                    //in the binary array
        list -> col = n-> col;      // set whatever n is pointing to equal to the contents of the new node which is the position of the zero in the binary array
    

        temp = list;                //make temp point to the new node
    
    
    
        if( head1 == NULL)          //if head1 is null make it point to the first node in the list.
    {
            head1 = list;

            memory[i] = head1;          // then put the address that the pointer contains into the array.
                                        // the array will later be used to reference the head of each list.
            i++;
 
        
        
    }
    
    previous = n;
    
    q = n -> next;               // make q equal to the next node of the original list of the positions
    
    while(q != NULL)
    {
        if(q -> col == n -> col)    //if the columns in the original list matches the column of the current node then create a list of positions with the same column
        {
            list = new node;        //create a new node to add the list of the one that has the same column position as whatever n is pointing to
            

            
            list -> row = q -> row; // put the position into the new node in order to create a list of positions with the same column values
            list -> col = q -> col;
            
            temp->next = list;      // make temp's next pointer point to the new node
            temp = list;            // puts temp on the new node to further create the link list of zeros who have the same column
            
            previous -> next = q -> next; // this is so that if there is a duplicate then it can be deleted
            delete q;                     // like if you have 0,2 and 2,2 in an already created list it can't make another list with 2,2
            q = previous->next ;
            
        
            }
        
       
        
            else
            {
                previous = previous -> next; //increment previous
                q = q -> next;      //if the columns don't match don't put it in the list and move on
            }
        
        if( q == NULL)      //once q is equal to null make temp's next pointer equal to null so the last node in the columns list is null
        {
            head1 = nullptr;
            temp->next = NULL;
            list = nullptr;     // then make list a nullptr to start a new list of positions with the same column
        }

        
        
        }
    
    n = n -> next;      //increment n to get to the next node in the original position list

}
}


// Unfortunately, finding the pairs was more efficient than printing the pairs.
// The following function is O(n^3) because of the 3 nested while loops.
void::stack::print(std::ofstream &cornerOut, int length)
    {
        cornerOut.open("corners.txt");
       
        cornerOut << "These are the corners: " << std::endl;
        int keepCount = 0;
        int increment = 1;
        int e = 0;
        int w = 0;
        w = length - 1;

        
        
        while ( e != length) // this is so that each list can be compared to one another by setting e equal to zero until it reaches the last linked list of positions with the same..
                            // ..number of columns. So it starts on list one and compares it to everthing else. Then it starts on list two and compares it to every other list etc.
                            // This is to get where the rows are equal and columns are equal to print the correct pairs
        {
            
            
            while( keepCount != w)  // keepCount is making sure that it is comparing each list to the current list
            {
                
               
                current1  = memory[e];      // it sets the pointer current  equal to memory address stored in the array which keeps track of where all of the roots of each list is
                after1 = current1  -> next;      // this sets after1 equal to the node after current1
                
                
                current2 = memory[e + increment];  // this sets the pointer current2 equal to the next list to compare it to the current list
                                            // increment is used as a way to access each list and compare it to current before moving current to the next list
                after2 = current2 -> next;              // this sets the pointer after2 equal to the next node in the list that current2 is pointing to
                
                
                while( after1 != NULL && after2 != NULL) // since after1 and after2 are after current1 and current2 then if they are null there no point in looking anymore
                {
                    if( current1  -> row == current2 -> row && after1 -> row == after2 -> row) // because each list contains positions that have equal columns if they have the same..
                                                                                                // then they need to be paired together
                    {
                        cornerOut << "(" << current1 -> row << "," << current1 -> col << ")" << " "  << "(" << current2 -> row << "," << current2->col << ")" << " " << "(" << after1 -> row << "," << after1->col << ")" << " " << "(" << after2 -> row << "," << after2 -> col << ")" << std::endl << std::endl;
                        current1  = current1  -> next;
                        after1 = after1 -> next;
                        current2 = current2 -> next;
                        after2 = after2-> next;
                    }
                    
                    else
                    {
                        current1  = current1  -> next; // if they don't have the same row then they are not pairs
                        after1 = after1 -> next;
                        current2 = current2 -> next;
                        after2 = after2-> next;
                    }
                    
                    
                    
                }
                keepCount++;
                increment++;
                
            }
            w = w - 1;
            keepCount = 0;
            increment = 1;
            e++;
        }
        
        
    }
    
void::stack::times(std::ofstream &cornerOut, double time)
{
    
    cornerOut << "This is how many milliseconds it took to find the pairs and to print them: " << time << std::endl;
    cornerOut.close();
}








