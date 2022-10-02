/*[L12 P6] Cyclic Permutations of an array
Consider the array of elements {23, 1, -3, 5}. A cyclic permutation of such an array would be {5, 23, 1, -3}, where the last element comes first and all the other elements shift to the right by one place.  If we continue taking the cyclic permutations, it looks something like this:
{23, 1, -3, 5} → {5, 25, 1, -3} → {-3, 5, 23, 1} → {1, -3, 5, 23} → {23, 1, -3, 5}
After exactly 4 steps (note that there are 4 elements in the array) the array comes back to its original state.
Define a function void nextcyclic(int* arr, int size);  that takes the pointer to an array as its first argument, size of the array as the second argument, and returns ‘nothing’ but modifies array to its next cyclic state. The program should behave the following way:
Example 1:
Input:
3
2 -3 5
    where:
first line takes the size of the array
second line scans the elements of the array
Output:
5,2,-3 
-3,5,2 
2,-3,5
Explanation: These are the next three cyclic permutations after which the array came back to the original state.
Example 2:
Input:
4
1 0 -1 0
Output:
0,1,0,-1
-1,0,1,0
0,-1,0,1
1,0,-1,0
Constraints:
The size of the array is < 100
The type of the array is int.
*/

//feel free to re-write the entire code on your own. This template is only for those who need help.

#include <stdio.h>

void nextcyclic(int* arr, int size){
    int last=arr[size-1]; //assign last element to of the array
    for(int i=size-1;i>=0;i--) 
    {
        if(i==0) //If its the first element in the array push the last element to first element
        {
            arr[0]=last;
        }
        else
        {
            arr[i]=arr[i-1]; //Else keep pushing elements to the next place
        }
    }
    
}

int main(){
  int mynumbs[1000] = {};
  
  int size;
  scanf("%d", &size);
  
  for(int i = 0; i < size; i++){ //scanning of array is done here.
    scanf("%d", &mynumbs[i]);
  }

  for(int i = 0; i < size; i++){ //printing of each permutation is done here.
    nextcyclic(mynumbs, size);
    for(int j = 0; j < size; j++){
      printf("%d", mynumbs[j]);
      if(j != size - 1){
        printf(",");
      }
    }
    printf("\n");
  }	
  return 0;
}
