/* pathmgr.cpp
 * Rationale: Python has an lack of code
 * that can automatically add folders to
 * the PATH environment variable on windows.
 * Because of this I decided to also provide
 * code bindings that my pthmgr also uses so
 * that way one can achive the same results
 * as using pthmgr, however with it auto
 * modifying the path environment of python as
 * well with it broadcasting an WM_SETTINGCHANGE
 * by default.
 *
 * I would have named the file as an *.c file
 * however the dependencies to pthmgr uses namespaces
 * that is only availible with c++ without it actually
 * checking if compiling for c++ first.
 * I would love to change it but I really should not
 * change the dependencies myself at all really.
 */
#include <Python.h> /* for python's C API's*/
#ifdef _WIN32
  /*
   * These are only supported on Windows I think so far.
   */
  #define EDITENV_STATIC
  #include <editenv.hpp>

  /*
   * Helper functions for the C Python extension modules.
   */
  void add_path(const char* folder) {
	  pathAdd(editenv::es_user, folder);
	  pathAdd(editenv::es_system, folder);
  }

  void remove_path(const char* folder) {
	  pathRemove(editenv::es_user, folder);
	  pathRemove(editenv::es_system, folder);
  }
#endif

static PyObject *
pathmgr_add_path(PyObject *self, PyObject *args)
{
  const char *path;
  if (!PyArg_ParseTuple(args, "s", &path))
      return NULL;
#ifdef _WIN32
  // let's add the path
  add_path(path);
#endif
  Py_RETURN_NONE;
}

static PyObject *
pathmgr_remove_path(PyObject *self, PyObject *args)
{
  const char *path;
  if (!PyArg_ParseTuple(args, "s", &path))
      return NULL;
#ifdef _WIN32
  // let's remove the path
  remove_path(path);
#endif
  Py_RETURN_NONE;
}

static PyMethodDef pathmgr_methods[] = {
  {"add_path", consoletitle, METH_VARARGS,
   "Adds the specified path into Window's PATH"
   " Environment variable and broadcasts this"
   " change to Python automatically. On"
   " non-windows systems this simply returns None only."},
  {"remove_path", consolesize, METH_VARARGS,
   "Removes the specified path from Window's PATH"
   " Environment variable and broadcasts this"
   " change to Python automatically. On"
   " non-windows systems this simply returns None only."},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef pathmgrmodule = {
  PyModuleDef_HEAD_INIT, "pathmgr",
  "Python extension module that allows"
  " management of the PATH environment variable"
  " stuff for you that works and automatically"
  " tells python about said modifications so you"
  " do not have to manually restart python for"
  " the changes to take effect thereby reducing "
  " the amount of time wasted waiting for python"
  " to close before you can reopen python.", -1,
  pathmgr_methods
};

PyMODINIT_FUNC
PyInit_pathmgrmodule(void)
{
  PyObject* m;
  
  m = PyModule_Create(&pathmgrmodule);
  if (m == NULL)
    return NULL;
  
  PyObject *_all_members = PyList_New(2);
  if (_all_members == NULL)
    return NULL;
  
  PyList_SetItem(
    _all_members, 0,
    PyUnicode_FromString("add_path"));
  PyList_SetItem(
    _all_members, 1,
    PyUnicode_FromString("remove_path"));
  
  /* expose this here...
   * only needed for travis.
   */
  PyModule_AddObject(m, "all_members", _all_members);
  
  return m;
}
