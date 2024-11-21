
#ifndef MATRIX_LIB_EXPORT_H
#define MATRIX_LIB_EXPORT_H

#ifdef MATRIX_LIB_STATIC_DEFINE
#  define MATRIX_LIB_EXPORT
#  define MATRIX_LIB_NO_EXPORT
#else
#  ifndef MATRIX_LIB_EXPORT
#    ifdef shared_matrix_lib_EXPORTS
        /* We are building this library */
#      define MATRIX_LIB_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MATRIX_LIB_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MATRIX_LIB_NO_EXPORT
#    define MATRIX_LIB_NO_EXPORT 
#  endif
#endif

#ifndef MATRIX_LIB_DEPRECATED
#  define MATRIX_LIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef MATRIX_LIB_DEPRECATED_EXPORT
#  define MATRIX_LIB_DEPRECATED_EXPORT MATRIX_LIB_EXPORT MATRIX_LIB_DEPRECATED
#endif

#ifndef MATRIX_LIB_DEPRECATED_NO_EXPORT
#  define MATRIX_LIB_DEPRECATED_NO_EXPORT MATRIX_LIB_NO_EXPORT MATRIX_LIB_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MATRIX_LIB_NO_DEPRECATED
#    define MATRIX_LIB_NO_DEPRECATED
#  endif
#endif

#endif /* MATRIX_LIB_EXPORT_H */
