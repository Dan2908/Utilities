#ifndef MY_ARRAYS_H
#define MY_ARRAYS_H
#include <cstdarg>

#define F_MIN(A,B) ( (A < B) ? A : B )

/**
 * Array<class> template for arrays of n dimensions.
 */
template<class dataType>
class Array{
    dataType *m_array;
    int *m_sizes,
         m_dimensionN;
    int  m_getGridCount(const int n, int *p_sizes) const{
        if(n < 0) return 1;
        return p_sizes[n] * m_getGridCount(n-1, p_sizes);
    }
    int  m_getGridPosition( int *p_params, const int n) const{
        if(n == 0) return p_params[0];
        return p_params[n] * m_getGridCount(n-1, m_sizes) + m_getGridPosition(p_params, n-1);
    }
    /* Compares two n-Dimensional arrays and returns a n-Dimensional array with the minimum values of each*/
    int* m_getMinArray( int *p_array, int *p_other, int n){
        int *minarray = new int[n];
        for(int i = 0; i < n; i++)
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
    Array( const int p_dimensions... ){
        /* Get total array size and dimensions array (width, height, depth, ...) */
        int array_size = 1;
        m_sizes = new int(p_dimensions);      // Contains dimension sizes W, H, D, ...
        m_dimensionN = static_cast<int>(sizeof(m_sizes)/sizeof(int));
        for(int i = 0; i < m_dimensionN; i++){
            array_size *= m_sizes[i];                // Calculate m_array size
        }
        /* Create new array */
        m_array = new dataType[array_size];
    }
    ~Array(){
        if(m_array != 0) delete[] m_array;
        if(m_sizes != 0) delete[] m_sizes;
        m_array = 0;
        m_sizes = 0;
    }
    dataType& Get( const int p_position... ){
        int parameters[] = {p_position};
        return m_array[ (m_getGridPosition(parameters, m_dimensionN - 1 ))];
    }
    /**
     * Resizes the array into the current dimension bound.
     * @param p_sizes comma-separated list of new sizes corresponding to each dimension,
     * further sizes int the list will be ignored.
     * Example: Array<int> arr(3, 3, 3); arr.Resize(3, 4, 5, 6, 7) will give an array
     * of 3x4x5, while sizes 6 and 7 are ignored.
    */
    template<typename... Ts>
    void Resize( Ts... p_sizes ){
        if(sizeof...(p_sizes) < m_dimensionN)
            return;
        //New data array;
        dataType *newarray = 0;
        //Save new sizes
        int newsizes[] = {p_sizes};
        //Allocate new array
        newarray = new dataType[ m_getGridCount( m_dimensionN - 1, newsizes) ];
        if(newarray == 0) return;                                     //Catch Allocation error

        int *min = m_getMinArray( oldsizes, newsizes);

        int min = (p_size < m_size) ? p_size : m_size,  //number of bytes to copy
            index;                                      //array index
        for(index = 0; index < min; index++)
            newarray[index] = m_array[index];           //copy data
        if(m_array != 0)                                //delete old array (if exists)
            delete[] m_array;
        m_array = newarray;                             //use new array
        m_size = p_size;
    }
};
#endif //MY_ARRAYS_H
