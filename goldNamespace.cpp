// Name: Vansh Patel
// Class (CECS 325-02)
// Project Name (Prog X – Gold Namespace)
// Due Date 05/01/2024
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

namespace gold
{
    template <typename T>
    class vector
    {
    private:
        T *_arr;               // pointer to arr
        int _capacity;         // capacity of arr
        int _current_capacity; // current size of arr

    public:
        vector()
        {                                // default constructor
            _arr = new T[2];             // default size of 2
            this->_capacity = 2;         // default capacity
            this->_current_capacity = 0; // current size of arr
        }

        vector(int size)
        { // constructor with size
            _arr = new T[size];
            this->_capacity = size;
            this->_current_capacity = size;
            for (int i = 0; i < size; i++)
            {
                _arr[i] = T(); // initialize all elements to default value
            }
        }

        vector(int size, const T &val)
        { // constructor with size and value
            _arr = new T[size];
            this->_capacity = size;
            this->_current_capacity = size;
            for (int i = 0; i < size; i++)
            {
                _arr[i] = val; // initialize all elements to value
            }
        }
        void push_back(const T &item)
        {
            if (_current_capacity == _capacity)
            {
                T *temp = new T[2 * _capacity];
                for (int i = 0; i < _capacity; i++)
                {
                    temp[i] = _arr[i]; // copy old elements to new array
                }
                delete[] _arr;
                _arr = temp;
                _capacity *= 2;
            }
            _arr[_current_capacity] = item;
            _current_capacity++;
        }

        int size()
        {
            return _current_capacity;
        }

        T &operator[](int idx)
        {
            return _arr[idx];
        }

        void pop_back()
        {
            if (_current_capacity > 0)
            {
                _current_capacity--;
            }
        }

        int capacity()
        {
            return _capacity;
        }

        void clear()
        {
            delete[] _arr;
            _arr = new T[_capacity]; // reset to default capacity
            _current_capacity = 0;   // reset current size to 0
        }

        T &front()
        {
            return _arr[0];
        }

        T &back()
        {
            return _arr[_current_capacity - 1];
        }

        T &at(int idx)
        {
            if (idx >= _current_capacity)
            {
                throw "Index out of range";
            }
            return _arr[idx];
        }
    };
};