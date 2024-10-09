#include <iostream>
using namespace std;

class Queue
{
    public:
        Queue()
        {
            size = 5;
            last = 0;
            first = 0;
        }

        void enqueue(int value)
        {
            
            if (last >= size)
            {
                cout << "ERROR: Queue is full..." << endl;
                exit(1);
            }
            else
            {
                queue_arr[last] = value;
                last++;
            }
        }

        void print_queue()
        {
            for(int i = 0; i < last; i++)
            {
                cout << queue_arr[i];
            }
        }

    private:
        int first;
        int last;
        int size;
        int *queue_arr = new int[size];

};

int main()
{
    Queue line_obj;

    line_obj.enqueue(25);

    line_obj.print_queue();

    return 0;
}