#include<iostream>


class Queue{
    private:
        int arr[4]; // try to create a dynamic array 
        int rear; 
        int front; 

    public:
        Queue(){
            front = -1; // to check empty queue
            rear = -1;  // to check empty queue
            for(int i = 0; i < 4; i++){
                arr[i] = 0;
            }
        }


        // to check queue is empty or not. Will return true if queue is empty and return false if queue is not empty
        bool isEmpty(){
            if(rear == -1 && front == -1){
                return true;
            } else{
                return false;
            }
        }

        // to check queue is full or not. Will return true if queue is full and return false if queue is not full
        bool isFull(){
            if(rear == (sizeof(arr)/4) -1){
                return true;
            } else{
                return false;
            }
            
        }


        // to add a data in rear or in end of the queue
        void enqueue(int val){
            if(isFull()){
                std::cout << "Queue is full." << std::endl;
            } else if(isEmpty()){
                rear = 0; 
                front = 0;
                arr[rear] = val;
            } else{
                rear++;
                arr[rear] = val;
            }
        }


        // to remove data from front 
        int dequeue(){
            int temp;
            if(isEmpty()){
                std::cout << "Queue is empty." << std::endl;
                return 0;
            } else if(rear == front){
                temp = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
            } else{
                temp = arr[front];
                arr[front] = 0;
                front++;
            }
            return temp;
        }

        // to check total elements available in queue
        int size(){
            return ((rear + 1) - front);
        }



};

int main(){
    int option, value;

    Queue queue_1;


    do{
        // to create a menu
        std::cout << "\nEnter an option to perform. Enter 0 to exit." << std::endl;

        std::cout << "1: Enqueue()" << std::endl;
        std::cout << "2: Dequeue()" << std::endl;
        std::cout << "3: isEmpty()" << std::endl;
        std::cout << "4: isFull()" << std::endl;
        std::cout << "5: Size()" << std::endl;
        std::cout << "6: Clear Screen" << std::endl;

        std::cout << "Enter your option here: ";
        std::cin >> option;

        switch (option){
            case 1: 
                std::cout << "Enter an value to enqueue in queue: ";
                std::cin >> value;
                queue_1.enqueue(value);
                break;

            case 2:
                std::cout << "Poped value is : " << queue_1.dequeue() << std::endl;
                break;

            case 3:
                if(queue_1.isEmpty()){
                    std::cout << "Queue is empty." << std::endl;
                } else{
                    std::cout << "Queue is not empty." << std::endl;
                }
                break;
            
            case 4:
                if(queue_1.isFull()){
                    std::cout << "Queue is full." << std::endl;
                } else{
                    std::cout << "Queue is not full." << std::endl;
                }
                break;

            case 5:
                std::cout << "Total number of item in queue are: " << queue_1.size() << std::endl;
                break;
            
            case 6:
                system("clear"); // change "clear" with "cls" if you are using Windows OS
                break;

            default:
                std::cout << "Enter a valid option." << std::endl;
        }

    } while(option != 0);
}