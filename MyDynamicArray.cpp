/*
* McKay Madsen
* This is a basic class that acts as a dynamically allocated array
* Only has 4 private variables and several public functions
*/
#ifndef MyDynamicArray_cpp
#define MyDynamicArray_cpp

#include<iostream>


class MyDynamicArray {
private:
    int size;
    int zeroVal = 0;
    int count = 0;
    int *array;
    
public:

    MyDynamicArray() { //default constructor
        array = new int[1];
        array[0] = 0; //initalize array to zero
        array[1] = 0; //initalize array to zero
        size = 0;
        count = 0;
    }
    
    MyDynamicArray(int s) { //custom constructor
        size = s;
        count = s;
        array = new int[s];
        for (int i = 0; i < size; i++) { //initalize array to zero
            array[i] = 0; 
        }
    }
    
    ~MyDynamicArray() { //deletes array using the delete function
        delete[] array;
    }
    
    int& operator[](int i) { //returns 0 if out of bounds
        if(i >= size || i < 0) { 
            std::cout << "Out of bounds reference : " << i << std::endl;
            return zeroVal;
        }
        return array[i];
    }
    
    void add(int v) { //increases the array size by 1 and inserts the given int at the end
                      //if more space is needed, the allocated mem is doubled
         
        if (count == size) {
            int *new_array;   
            std::cout << "Doubling to : " << size << std::endl;
            new_array = new int[size*2]; 
            for (int i = 0; i < count; i++) { new_array[i] = array[i]; }
            delete[] array;    
            array = new_array;  
        }    
        array[count++] = v; 
    } 

    void del() { //decreases the user array size by 1 && if usize is <25% allocated mem is 
                 //we half the array allocation
        if (count <= size/4) { 
            int *new_array = new int[count /= 2];
            std::cout << "Reducing to : " << size << std::endl;
            for (int i = 0; i < count; i++) { new_array[i] = array[i]; }
            delete[] array;    
            array = new_array;  
        }    
        count--;
    }
    
    int length() { //returns the user length of the array
        return count;
    }

    void clear() { 
        delete array;
        array = new int[count = 2];
        size = 2;
        count = 0;
        array[0] = 0;
        array[1] = 0;
    }
    
};

#endif
