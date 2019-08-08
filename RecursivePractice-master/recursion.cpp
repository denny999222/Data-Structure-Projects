#include <iostream>
#include "maze.h"
using namespace std;

using std::ostream;
using data_structures_assignment_5::maze;
using data_structures_assignment_5::maze_node;

void triangle(ostream& outs, unsigned int m, unsigned int n){
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/
    assert(m <= n);
    if(m==n){
        std::cout<<std::string(m,'*')<<std::endl;
        std::cout<<std::string(m,'*')<<std::endl;
    }
    else{
        cout<<std::string(m,'*')<<endl;
        triangle(cout, m+1, n);
        cout<<std::string(m,'*')<<endl;
    }


}

int count_ways_to_step(int number_of_stepping_stones){
// Precondition: number_of_stepping_stones > 0
// Postcondition: The number of ways to reach the final stepping stone using
// either a small step (moving 1 stepping stone) or a large step (moving 2 stepping
// stones) in any combination is returned.
// For 3 stepping stones there are 3 ways. For 4 stepping stones, there are 5 ways.
    assert(number_of_stepping_stones > 0);
    if(number_of_stepping_stones == 1){
        return 1;
    }
    else if (number_of_stepping_stones == 2){
        return 2;
    }
    else{
        return count_ways_to_step(number_of_stepping_stones - 1) + count_ways_to_step(number_of_stepping_stones-2);
    }
}



bool print_path_through_maze(const maze_node* maze_position) {
// Postcondition: Prints the path through the maze, with 0s representing right
// turns and 1s representing left turns.
// You may print the path in reverse order (this will be easier).
// Hint: Use the return boolean to signify that the current path is the correct path.
    //each piece prints out only one of its root
    //if the left pointer of current node is the finish
    //Reaches finish
    if(maze_position==nullptr){
        return false;
    }
    else if(maze_position->is_finish()){
        return true;
    }
    //Reaches a dead-end which isn't the finish
    else if(maze_position->left() == nullptr && maze_position->right() == nullptr && !(maze_position->is_finish())){
        return false;
    }
    else{
        bool path_left = print_path_through_maze(maze_position->left());
        if (path_left){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
            print_path_through_maze(maze_position->right());
        }

    }






}



int main()
{

    // You can test your code by adding it here.
    //triangle(cout, 3, 5);
    maze m1(1);
    print_path_through_maze(m1.get_start());
    cout<<endl;
    maze m0(0);
    print_path_through_maze(m0.get_start());

    return 0;
}
