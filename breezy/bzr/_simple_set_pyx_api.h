/* Generated by Cython 3.0.8 */

#ifndef __PYX_HAVE_API__breezy__bzr___simple_set_pyx
#define __PYX_HAVE_API__breezy__bzr___simple_set_pyx
#ifdef __MINGW64__
#define MS_WIN64
#endif
#include "Python.h"
#include "_simple_set_pyx.h"

static PyTypeObject *__pyx_ptype_6breezy_3bzr_15_simple_set_pyx_SimpleSet = 0;
#define SimpleSet_Type (*__pyx_ptype_6breezy_3bzr_15_simple_set_pyx_SimpleSet)

static struct SimpleSetObject *(*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_New)(void) = 0;
#define SimpleSet_New __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_New
static PyObject *(*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Add)(PyObject *, PyObject *) = 0;
#define SimpleSet_Add __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Add
static int (*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Contains)(PyObject *, PyObject *) = 0;
#define SimpleSet_Contains __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Contains
static int (*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Discard)(PyObject *, PyObject *) = 0;
#define SimpleSet_Discard __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Discard
static PyObject *(*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Get)(struct SimpleSetObject *, PyObject *) = 0;
#define SimpleSet_Get __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Get
static Py_ssize_t (*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Size)(PyObject *) = 0;
#define SimpleSet_Size __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Size
static int (*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Next)(PyObject *, Py_ssize_t *, PyObject **) = 0;
#define SimpleSet_Next __pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Next
static PyObject **(*__pyx_api_f_6breezy_3bzr_15_simple_set_pyx__SimpleSet_Lookup)(PyObject *, PyObject *) = 0;
#define _SimpleSet_Lookup __pyx_api_f_6breezy_3bzr_15_simple_set_pyx__SimpleSet_Lookup
#ifndef __PYX_HAVE_RT_ImportFunction_3_0_8
#define __PYX_HAVE_RT_ImportFunction_3_0_8
static int __Pyx_ImportFunction_3_0_8(PyObject *module, const char *funcname, void (**f)(void), const char *sig) {
    PyObject *d = 0;
    PyObject *cobj = 0;
    union {
        void (*fp)(void);
        void *p;
    } tmp;
    d = PyObject_GetAttrString(module, (char *)"__pyx_capi__");
    if (!d)
        goto bad;
    cobj = PyDict_GetItemString(d, funcname);
    if (!cobj) {
        PyErr_Format(PyExc_ImportError,
            "%.200s does not export expected C function %.200s",
                PyModule_GetName(module), funcname);
        goto bad;
    }
    if (!PyCapsule_IsValid(cobj, sig)) {
        PyErr_Format(PyExc_TypeError,
            "C function %.200s.%.200s has wrong signature (expected %.500s, got %.500s)",
             PyModule_GetName(module), funcname, sig, PyCapsule_GetName(cobj));
        goto bad;
    }
    tmp.p = PyCapsule_GetPointer(cobj, sig);
    *f = tmp.fp;
    if (!(*f))
        goto bad;
    Py_DECREF(d);
    return 0;
bad:
    Py_XDECREF(d);
    return -1;
}
#endif

#ifndef __PYX_HAVE_RT_ImportType_proto_3_0_8
#define __PYX_HAVE_RT_ImportType_proto_3_0_8
#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#include <stdalign.h>
#endif
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) || __cplusplus >= 201103L
#define __PYX_GET_STRUCT_ALIGNMENT_3_0_8(s) alignof(s)
#else
#define __PYX_GET_STRUCT_ALIGNMENT_3_0_8(s) sizeof(void*)
#endif
enum __Pyx_ImportType_CheckSize_3_0_8 {
   __Pyx_ImportType_CheckSize_Error_3_0_8 = 0,
   __Pyx_ImportType_CheckSize_Warn_3_0_8 = 1,
   __Pyx_ImportType_CheckSize_Ignore_3_0_8 = 2
};
static PyTypeObject *__Pyx_ImportType_3_0_8(PyObject* module, const char *module_name, const char *class_name, size_t size, size_t alignment, enum __Pyx_ImportType_CheckSize_3_0_8 check_size);
#endif

#ifndef __PYX_HAVE_RT_ImportType_3_0_8
#define __PYX_HAVE_RT_ImportType_3_0_8
static PyTypeObject *__Pyx_ImportType_3_0_8(PyObject *module, const char *module_name, const char *class_name,
    size_t size, size_t alignment, enum __Pyx_ImportType_CheckSize_3_0_8 check_size)
{
    PyObject *result = 0;
    char warning[200];
    Py_ssize_t basicsize;
    Py_ssize_t itemsize;
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *py_basicsize;
    PyObject *py_itemsize;
#endif
    result = PyObject_GetAttrString(module, class_name);
    if (!result)
        goto bad;
    if (!PyType_Check(result)) {
        PyErr_Format(PyExc_TypeError,
            "%.200s.%.200s is not a type object",
            module_name, class_name);
        goto bad;
    }
#if !CYTHON_COMPILING_IN_LIMITED_API
    basicsize = ((PyTypeObject *)result)->tp_basicsize;
    itemsize = ((PyTypeObject *)result)->tp_itemsize;
#else
    py_basicsize = PyObject_GetAttrString(result, "__basicsize__");
    if (!py_basicsize)
        goto bad;
    basicsize = PyLong_AsSsize_t(py_basicsize);
    Py_DECREF(py_basicsize);
    py_basicsize = 0;
    if (basicsize == (Py_ssize_t)-1 && PyErr_Occurred())
        goto bad;
    py_itemsize = PyObject_GetAttrString(result, "__itemsize__");
    if (!py_itemsize)
        goto bad;
    itemsize = PyLong_AsSsize_t(py_itemsize);
    Py_DECREF(py_itemsize);
    py_itemsize = 0;
    if (itemsize == (Py_ssize_t)-1 && PyErr_Occurred())
        goto bad;
#endif
    if (itemsize) {
        if (size % alignment) {
            alignment = size % alignment;
        }
        if (itemsize < (Py_ssize_t)alignment)
            itemsize = (Py_ssize_t)alignment;
    }
    if ((size_t)(basicsize + itemsize) < size) {
        PyErr_Format(PyExc_ValueError,
            "%.200s.%.200s size changed, may indicate binary incompatibility. "
            "Expected %zd from C header, got %zd from PyObject",
            module_name, class_name, size, basicsize+itemsize);
        goto bad;
    }
    if (check_size == __Pyx_ImportType_CheckSize_Error_3_0_8 &&
            ((size_t)basicsize > size || (size_t)(basicsize + itemsize) < size)) {
        PyErr_Format(PyExc_ValueError,
            "%.200s.%.200s size changed, may indicate binary incompatibility. "
            "Expected %zd from C header, got %zd-%zd from PyObject",
            module_name, class_name, size, basicsize, basicsize+itemsize);
        goto bad;
    }
    else if (check_size == __Pyx_ImportType_CheckSize_Warn_3_0_8 && (size_t)basicsize > size) {
        PyOS_snprintf(warning, sizeof(warning),
            "%s.%s size changed, may indicate binary incompatibility. "
            "Expected %zd from C header, got %zd from PyObject",
            module_name, class_name, size, basicsize);
        if (PyErr_WarnEx(NULL, warning, 0) < 0) goto bad;
    }
    return (PyTypeObject *)result;
bad:
    Py_XDECREF(result);
    return NULL;
}
#endif


static int import_breezy__bzr___simple_set_pyx(void) {
  PyObject *module = 0;
  module = PyImport_ImportModule("breezy.bzr._simple_set_pyx");
  if (!module) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_New", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_New, "struct SimpleSetObject *(void)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_Add", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Add, "PyObject *(PyObject *, PyObject *)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_Contains", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Contains, "int (PyObject *, PyObject *)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_Discard", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Discard, "int (PyObject *, PyObject *)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_Get", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Get, "PyObject *(struct SimpleSetObject *, PyObject *)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_Size", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Size, "Py_ssize_t (PyObject *)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "SimpleSet_Next", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx_SimpleSet_Next, "int (PyObject *, Py_ssize_t *, PyObject **)") < 0) goto bad;
  if (__Pyx_ImportFunction_3_0_8(module, "_SimpleSet_Lookup", (void (**)(void))&__pyx_api_f_6breezy_3bzr_15_simple_set_pyx__SimpleSet_Lookup, "PyObject **(PyObject *, PyObject *)") < 0) goto bad;
  __pyx_ptype_6breezy_3bzr_15_simple_set_pyx_SimpleSet = __Pyx_ImportType_3_0_8(module, "breezy.bzr._simple_set_pyx", "SimpleSet", sizeof(struct SimpleSetObject), __PYX_GET_STRUCT_ALIGNMENT_3_0_8(struct SimpleSetObject),__Pyx_ImportType_CheckSize_Warn_3_0_8); if (!__pyx_ptype_6breezy_3bzr_15_simple_set_pyx_SimpleSet) goto bad;
  Py_DECREF(module); module = 0;
  return 0;
  bad:
  Py_XDECREF(module);
  return -1;
}

#endif /* !__PYX_HAVE_API__breezy__bzr___simple_set_pyx */