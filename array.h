#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;


template <typename T> class Array{
    public:
        Array(int size) {
            if(size < 1)
                throw std::invalid_argument("size must be greater than 0");

            m_array = new int[size];
            m_size = size;
        }

        ~Array() {
            if(m_array)
                delete [] m_array;
        }

        Array(const Array &a) {
            m_size = a.m_size;

            if(a.m_array) {
                m_array = new T[a.m_size];

                for(int i = 0; i < a.m_size; ++i)
                    m_array[i] = a.m_array[i];
            }
        }

        Array& operator=(const Array &a) {
            if(this == &a)
                return *this;

            if(m_array != nullptr)
                delete [] m_array;

            m_size = a.m_size;

            if(a.m_array) {
                m_array = new T[a.m_size];

                for(int i = 0; i < a.m_size; ++i)
                    m_array[i] = a.m_array[i];
            } else
                m_array = nullptr;

            return *this;
        }

        int& operator[](int i) const {
            if(i < 0 || i >= m_size)
                throw std::out_of_range("index out of range");

            return m_array[i];
        }

        int size(void) const {
            return m_size;
        }

    void findMinAndMax(int &min, int &max) { //pass by value
        max = m_array[0];
        for (int i = 0; i < m_size; i++){
            if (m_array[i] > max) { max = m_array[i]; }
        }
        min = m_array[0];
        for (int i = 0; i < m_size; i++){
            if (m_array[i] < min) { min = m_array[i]; }
        }
    }

    friend ostream& operator<<(ostream &s, Array &a) {
            for(int i = 0; i < a.m_size; ++i)
                s << a[i] << endl;

            return s;
        }

    private:
        int *m_array = nullptr;
        T m_size = 0;
    };
//}

#endif // ARRAY_H_
