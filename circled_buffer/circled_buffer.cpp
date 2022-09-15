#include <iostream>

#define BufferSize 5                                                            // size of buffer

struct {                                                                        // stucture of buffer
    int readIndex = 0;
    int writeIndex = 0;
    bool isFull = 0;
    bool isEmpty = 1;
    int data[BufferSize];
}buffer;


void put() {                                                                    // data entry
    if (buffer.isFull != 1) {
        system("cls");
        std::cout << "Enter data [" << buffer.writeIndex + 1 << "]" << std::endl;
        std::cin >> buffer.data[buffer.writeIndex];
        buffer.writeIndex++;
    }
    else {
        system("cls");
        std::cout << "Buffer is full" << std::endl;

    }
    
}

void get() {                                                                    // data output
    if (buffer.isEmpty != 1) {
        system("cls");
        std::cout << '[' << buffer.readIndex + 1 << "] : ";
        std::cout << buffer.data[buffer.readIndex] << std::endl;
        buffer.readIndex++;
    }
    else {
        system("cls");
        std::cout << "Buffer is empty" << std::endl;

    }
}

int main()
{

    while (true) {

        int command; 


        if (buffer.writeIndex >= 5)                                             // conditions
            buffer.isFull = 1;
        
        else {
            buffer.isFull = 0;
            if (buffer.readIndex == 5)
                buffer.writeIndex = 0;
        }

        if (buffer.writeIndex <= buffer.readIndex || buffer.readIndex == 5) {
            buffer.isEmpty = 1;
            buffer.writeIndex = 0;
            buffer.readIndex = 0;
        }
        else 
            buffer.isEmpty = 0;


        do {                                                                    // inputing command     
            std::cout << "Enter the command (0 - input data, 1 - output data)" << std::endl;
            std::cin >> command;
        } while (command != 0 && command != 1);

        if (command == 0)
            put();
        else if (command == 1)
            get();  
    }

}