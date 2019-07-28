// Author : Rajesh Berwal
//Date : 28-July-2019

#include<iostream>
#include<string>

class Stack{
    private:
        int arr[5]; //Try to create a dynamic array
        int top;

    public:
        // Constructer
        Stack(){
            // -1 = empty stack
            top = -1;
            for(int i = 0; i < 5; i++){
                //to create an empty stack  
                arr[i] = 0;
            }
        }

        //to check weather stack is empty or not
        bool isEmpty(){
            if(top == -1){
                return true;
            } else{
                return false;
            }
        }

        //to check stack is full or not
        bool isFull(){
            if(top == 4){
                return true;
            }else{
                return false;
            }
        }

        void push(int val){
            if(isFull()){
                std::cout << "StackOverflow" << std::endl;
            } else{
                top++; // increase the top indexing
                arr[top] = val; // Push the value at top
            }
        }
        
        int pop(){
            if(isEmpty()){
                std::cout << "UnderFlow" << std::endl; // going to print it on screen if stack is empty
                return 0;
            } else{
                int popValue = arr[top]; //To store the last value
                arr[top] = 0; //remove the value at top and set it to 0(means it'g going to empty place)
                top--; // decrement the position of top
                return popValue;
            }
        }

        // to get the total values available in stack
        int size(){
            return (top + 1);
        }

        //to get the value at given position or indexing
        int peek(int pos){
            if(isEmpty()){
                std::cout << "Stack Underflow" << std::endl;
                return 0;
            } else{
                return arr[pos];
            }
        }
        
        // to change a value at given location
        void change(int pos, int val){
            arr[pos] = val;
            std::cout << "Value changed at " << pos << std::endl;
        }

        // to display all the elements that are available in stack
        void display(){
            std::cout << "Elements in Sttack are: " << std::endl;
            for(int i = 4; i >= 0; i--){
                std::cout << arr[i] << std::endl;
            }
        }

};

int main(){
    Stack stack_1;
    int option, value, position;

    do{
        // Comand Line Menu to ask user to perform certain task
        std::cout << "Enter an option to perform. Enter 0 to exit." << std::endl;

        std::cout << "1: Push()" << std::endl;
        std::cout << "2: Pop()" << std::endl;
        std::cout << "3: isEmpty()" << std::endl;
        std::cout << "4: isFull()" << std::endl;
        std::cout << "5: Peek()" << std::endl;
        std::cout << "6: Size()" << std::endl;
        std::cout << "7: Change()" << std::endl;
        std::cout << "8: Display()" << std::endl;
        std::cout << "9: Clear Screen" << std::endl;

        std::cout << "Enter your option here: ";
        std::cin >> option;

        switch (option){
            case 1: 
                std::cout << "Enter an value to push in stack: ";
                std::cin >> value;
                stack_1.push(value);
                break;

            case 2:
                std::cout << "Poped value is :" << stack_1.pop() << std::endl;
                break;

            case 3:
                if(stack_1.isEmpty()){
                    std::cout << "Stack is empty." << std::endl;
                } else{
                    std::cout << "Stack is not empty." << std::endl;
                }
                break;
            
            case 4:
                if(stack_1.isFull()){
                    std::cout << "Stack is full." << std::endl;
                } else{
                    std::cout << "Stack is not full." << std::endl;
                }
                break;

            case 5:
                std::cout << "Enter the position that you want to peek: ";
                std::cin >> position;
                std::cout << "Peek called: " << "Value at" << position << " is " << stack_1.peek(position) << std::endl;
                break;

            case 6:
                std::cout << "Total number of item in stack are: " << stack_1.size() << std::endl;
                break;

            case 7:
                std::cout << "Enter the positon on that you want to change: ";
                std::cin >> position;
                std::cout << "Enter the value you want to insert: ";
                std::cin >> value;
                stack_1.change(position, value);
                std::cout << "New value " << value << " Changed at position " << position << std::endl;
                break;
            case 8:
                std::cout << "Display methode called: " << std::endl;
                stack_1.display();
                break;
            
            case 9:
                system("clear");
                break;

            default:
                std::cout << "Enter a valid option." << std::endl;
        }

    } while(option != 0);

    return 0;
}

