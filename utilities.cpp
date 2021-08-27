#include "utilities.h"

namespace util{
    /** Copies [p_count] data from [p_orig] to [p_dest] using Duff's Device.*/
    void duff_copy(int *p_orig, int *p_dest, int p_count){
        int n = (p_count + 7) / 8;
 
        switch (p_count % 8)
        {
        case 0: do { *p_dest++ = *p_orig++;
        case 7:      *p_dest++ = *p_orig++;
        case 6:      *p_dest++ = *p_orig++;
        case 5:      *p_dest++ = *p_orig++;
        case 4:      *p_dest++ = *p_orig++;
        case 3:      *p_dest++ = *p_orig++;
        case 2:      *p_dest++ = *p_orig++;
        case 1:      *p_dest++ = *p_orig++;
                    } while (--n);
        }
    }
    /** Copies [p_count] data from [p_orig] to [p_dest].*/
    void copy_array(int *p_orig, int *p_dest, int p_count){
        for(int i = 0; i < p_count; i++){
            p_dest[i] = p_orig[i];
        }
    }
};