#include <iostream>

#define BufferSize 5                                                            // size of buffer

typedef struct buf{                                                                        // stucture of buffer
    int readIndex = 0;
    int writeIndex = 0;
    bool isFull = 0;
    bool isEmpty = 1;
    int data[BufferSize];
}CircularBuffer;



bool putBuf(CircularBuffer *buffer) { // 0 - failed, 1 - success

    if (buffer->isFull) {
        system("cls");
        std::cout << "Buffer is full" << std::endl;
        return 0;
    }

    if (buffer->writeIndex >= BufferSize)
        buffer->writeIndex = 0;

    if (buffer->isEmpty) {

        buffer->isEmpty = 0;

        system("cls");
        std::cout << "Enter data [" << buffer->writeIndex + 1 << "]" << std::endl;
        std::cin >> buffer->data[buffer->writeIndex++];

        if (buffer->writeIndex == buffer->readIndex)
            buffer->isFull = 1;

        return 1;
    }

    system("cls");
    std::cout << "Enter data [" << buffer->writeIndex + 1 << "]" << std::endl;
    std::cin >> buffer->data[buffer->writeIndex++];

    if (buffer->writeIndex == buffer->readIndex)
        buffer->isFull = 1;

    return 1;


}

bool getBuf(CircularBuffer *buffer) {

    if (buffer->isEmpty) {
        system("cls");
        std::cout << "Buffer is empty" << std::endl;
        return 0;
    }

    if (buffer->readIndex >= BufferSize)
        buffer->readIndex = 0;

    buffer->isFull = 0;

    system("cls");
    std::cout << '[' << buffer->readIndex + 1 << "] : ";
    std::cout << buffer->data[buffer->readIndex++] << std::endl;

    if (buffer->readIndex == buffer->writeIndex)
        buffer->isEmpty = 1;

    return 1;



}

int main()
{
    CircularBuffer buffer;

    while (true) {

        int command;

        do {                                                                    // inputing command     
            std::cout << "Enter the command (0 - input data, 1 - output data)" << std::endl;
            std::cin >> command;
        } while (command != 0 && command != 1);

        if (command == 0)
            putBuf(&buffer);
        else if (command == 1)
            getBuf(&buffer);  


        //std::cout << std::endl << std::endl;                                   // debugging
        //for (int i = 0; i < BufferSize; i++)
        //    std::cout << buffer.data[i] << ' ' << std::endl;
        //std::cout << "Is empty " << buffer.isEmpty << std::endl;
        //std::cout << "Is full " << buffer.isFull << std::endl;
        //std::cout << "Read index " << buffer.readIndex << std::endl;
        //std::cout << "Write index " << buffer.writeIndex << std::endl;

        

    }

    
}
