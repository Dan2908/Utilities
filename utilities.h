#ifndef UTILITIES_H
// DEFINITIONS
#define UTILITIES_H
// MACROS
#define F_MIN(A, B) ((A < B) ? A : B)
// INCLUDES
#include <crtdefs.h> // size_t
#include <algorithm> // std::copy
#include <chrono>    // clocks, time_point

namespace util
{
/** A class for a basic dynamic array handling with it's basic methods. */
    template <class T>
    class dynamic_array
    {
        T *m_array;
        size_t m_size;

    public:
        /** Constructor. */
        dynamic_array() 
            : m_size(0), m_array(0) {}
        dynamic_array(size_t p_size) 
            : m_size(p_size), m_array(new T[p_size])    {}
        /** Copy constructor. */
        dynamic_array(dynamic_array<T> &p_other) 
            : dynamic_array<T>() {  *this = p_other; }  // operator=
        /** Destructor. */
        ~dynamic_array()
        {
            if (m_array != 0)
                delete[] m_array;
            m_array = 0;
        }
        /** Comparation operator */
        bool operator==(dynamic_array<T> &p_other)
        {
            if (m_size == p_other.m_size)
            {
                return std::equal(m_array, &m_array[m_size - 1], &p_other[0]);
            }
            return false;
        }
        /** Asignation */
        void operator=(dynamic_array<T> &p_other)
        {
            // New array
            size_t newSize = p_other.size();
            T *newArray = new T[newSize];
            // Check new array
            if (newArray == 0)  return;
            // Delete old array.
            if (m_array != 0)   delete[] m_array; 
            // Save pointer and new size.
            m_size = newSize;
            m_array = newArray;
            // Copy new data
            copy(p_other);
        }
        /** Index operator, returns a reference of data array */
        T &operator[](size_t p_index)
        {
            return m_array[p_index];
        }
        /** Returns array size */
        size_t size()
        {
            return m_size;
        }
        /** Resize */
        void resize(size_t p_size)
        {
            // Create new array.
            T *newArray = new T(p_size);
            if (newArray == 0) //
                return;        // Check errors.
            // Copy old data.
            if(m_size > 0){
                size_t min = (p_size < m_size) ? p_size : m_size;
                std::copy(m_array, &m_array[min], newArray);
                // Delete old array.
                delete[] m_array;
            }
            // Save data.
            m_array = newArray;
            m_size = p_size;
        }
        /** @brief Copy data from other array.
     *  If destination array size is less than the elements to be copied, it only copies
     *  all the elements that fits. Array is not resized. */
        void copy(dynamic_array<T> &p_other)
        {
            size_t lastPos = (m_size < p_other.m_size) ? m_size : p_other.m_size;
            std::copy(p_other.m_array, &p_other[lastPos], m_array);
        }
    };

    namespace testing
    {
        /** 
     *  Timer implementation for measuring execution times.
     *  This functions implements std::chrono libraries to do the task.
     *  
     *  Values returned by it's methods may vary depending on SO specific and priority of CPU usage,
     *  but may be still useful to compare algorithms each other. */
        class timer
        {
            std::chrono::time_point<std::chrono::_V2::steady_clock> m_begin, m_end;
            std::chrono::nanoseconds m_duration;

        public:
            timer() : m_duration(std::chrono::nanoseconds::zero()) {}
            void start()
            {
                m_begin = std::chrono::_V2::steady_clock::now();
                m_duration = std::chrono::nanoseconds::zero();      // reset duration
            }
            void end()
            {
                m_end = std::chrono::_V2::steady_clock::now();
                m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_begin);
            }
            int get_nanoseconds() { return m_duration.count(); }
        };
    };
};

#else

// TODO: These functions bellow may be derived from dinamic_array (above).

/** struct for reserving dimensional size data for multi-dimensional arrays*/
struct MultiDimSizing
{
    MultiDimSizing(int p_nDimension, int p_sizes...)
    {
        int auxarray[p_nDimension] = {p_sizes};
        m_sizes = auxarray;
        m_nDimension = p_nDimension;
    }
    ~MultiDimSizing()
    {
        if (m_sizes != 0)
            delete[] m_sizes;
        m_sizes = 0;
    }
    int &operator[](int p_index)
    {
        return m_sizes[p_index];
    }
    int &GetDimension()
    {
        return m_nDimension;
    }
    void SetSize(int p_dest, int p_new_size)
    {
        m_sizes[p_dest] = p_new_size;
    }

private:
    int m_nDimension;
    int *m_sizes;
};
}
;

/**
 * Array<class> template for arrays of n dimensions.
 */
template <class dataType>
class Array
{
    dataType *m_array;
    util::MultiDimSizing m_sizes;

    int m_getGridCount(const int n, int *p_sizes) const
    {
        if (n < 0)
            return 1;
        return p_sizes[n] * m_getGridCount(n - 1, p_sizes);
    }
    int m_getGridPosition(int *p_params, const int n) const
    {
        if (n == 0)
            return p_params[0];
        return p_params[n] * m_getGridCount(n - 1, m_sizes) + m_getGridPosition(p_params, n - 1);
    }
    /* Compares two n-Dimensional arrays and returns a n-Dimensional array with the minimum values of each*/
    int *m_getMinArray(int *p_array, int *p_other, int n)
    {
        int *minarray = new int[n];
        for (int i = 0; i < n; i++)
            minarray[i] = F_MIN(p_array[i], p_other[i]);
        return minarray;
    }

public:
    /** Creates an array of dataType with n dimensions. Dimensions are calculated by the number of parameters
 * passed to it's constructor.
 * example: Array<int> arr(3x3x3) builds a zero initialized 3D array. 
 * @param[in] p_dimensions comma-separated sizes, each parameter refers to each dimension. 3, 2, ..., n gives
 * a n-Dimension array.
 */
    Array(const int p_dimensions...)
    {
        /* Get total array size and dimensions array (width, height, depth, ...) */
        int array_size = 1;
        m_sizes = new int(p_dimensions); // Contains dimension sizes W, H, D, ...
        m_dimensionN = static_cast<int>(sizeof(m_sizes) / sizeof(int));
        for (int i = 0; i < m_dimensionN; i++)
        {
            array_size *= m_sizes[i]; // Calculate m_array size
        }
        /* Create new array */
        m_array = new dataType[array_size];
    }
    ~Array()
    {
        if (m_array != 0)
            delete[] m_array;
        if (m_sizes != 0)
            delete[] m_sizes;
        m_array = 0;
        m_sizes = 0;
    }
    dataType &Get(const int p_position...)
    {
        int parameters[] = {p_position};
        return m_array[(m_getGridPosition(parameters, m_dimensionN - 1))];
    }
    /**
     * Resizes the array into the current dimension bound.
     * @param p_sizes comma-separated list of new sizes corresponding to each dimension,
     * further sizes int the list will be ignored.
     * Example: Array<int> arr(3, 3, 3); arr.Resize(3, 4, 5, 6, 7) will give an array
     * of 3x4x5, while sizes 6 and 7 are ignored.
    */
    template <typename... Ts>
    void Resize(Ts... p_sizes)
    {
        if (sizeof...(p_sizes) < m_dimensionN)
            return;
        //New data array;
        dataType *newarray = 0;
        //Save new sizes
        int newsizes[] = {p_sizes...};
        //Allocate new array
        newarray = new dataType[m_getGridCount(m_dimensionN - 1, newsizes)];
        if (newarray == 0)
            return; //Catch Allocation error

        int *min = m_getMinArray(m_sizes, newsizes);

        //TODO: copy old array dato to the new
    }
};
#endif //UTILITIES_H
