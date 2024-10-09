#include <iostream>
using namespace std;


class Stack
{
public:

    int capacity = 5;
    int counter = 0;
    Stack()
    {
        
    }

    void push(int value)
    {
        string awnser;
        if(counter >= capacity)
        {
            cout << "ERROR: Insufficient Capacity..." << endl;
            cout << "Would you like to increase allocated capacity? (Y/N): ";
            cin >> awnser;
            while(awnser != "Y" && awnser != "N")
            {
                cout << "Would you like to increase allocated capacity? (Y/N): ";
                cin >> awnser;
            }

            if(awnser == "Y")
            {
                increase_capacity();
                array[counter] = value;
                counter++;
            }
            else
            {
                cout << "Program termination..." << endl;
                exit(1);
            }
                
        }
        else
        {
            array[counter] = value;
            counter++;
        }
    }




    void increase_capacity()
    {
        int increase;
        cout << "Would you like to increase your capacity by 5 or 10? (5/10): ";
        cin >> increase;
        
        while(increase != 5 && increase != 10)
        {
            cout << "Would you like to increase your capacity by 5 or 10? (5/10): ";
            cin >> increase;
        }

        capacity = capacity + increase;
        int *temp_arr = new int[capacity]{};

        for(int i = 0; i < counter; i++)
        {
            temp_arr[i] = array[i];
        }

        delete [] array;
        array = temp_arr;
    }



    void pop()
    {   
        int removed;
        if(counter <= 0)
        {
            cout << "ERROR: No values left to remove...";
        }
        else
        {
            removed = array[counter - 1];
            counter--;
            cout << "Valued Removed: " << removed << endl;
        }
    }



    void print()
    {
        if(counter <= 0)
        {
            cout << "Empty Array!";
        }
        else
        {
            for(int i = 0; i < counter; i++)
            {
                cout << array[i] << endl;
            }
        }
    }


    void print_full_array()
    {
        if(counter <= 0)
        {
            cout << "Empty Array!";
        }
        else
        {
            for(int i = 0; i < capacity; i++)
            {
                cout << array[i] << endl;
            }
        }
    }

private:
    int top;
    int *array = new int [capacity]{};

};

int main()
{
    Stack Object;
    Object.push(1);
    Object.push(2);
    Object.push(3);
    Object.push(4);
    Object.push(5);
    Object.push(6);
    Object.print();


    return 0;
}