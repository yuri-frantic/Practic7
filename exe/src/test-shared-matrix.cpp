//#include <src/export.h>
#define MATRIX_LIB_EXPORT __declspec(dllimport)

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif

extern Matrix* MATRIX_LIB_EXPORT math_createMatrix(int, int);
extern void MATRIX_LIB_EXPORT math_set(Matrix*,int, int, double);
extern void MATRIX_LIB_EXPORT math_print(Matrix*);
extern void MATRIX_LIB_EXPORT math_deleteMatrix(Matrix*);


#ifdef __cplusplus

}
#endif

int main()
{
    Matrix* m = math_createMatrix(3,3);

    math_set(m, 0, 0, 1);
    math_set(m, 1, 1, 1);

    math_print(m);

    math_deleteMatrix(m);
    return 0;
}