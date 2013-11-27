/* Enfold Enterprise Server */
/* Copyright(C), 2004-5, Enfold Systems, LLC - ALL RIGHTS RESERVED */

/* Enfold Systems, LLC */
/* 4617 Montrose Blvd., Suite C215 */
/* Houston, Texas 77006 USA */
/* p. +1 713.942.2377 | f. +1 832.201.8856 */
/* www.enfoldsystems.com */
/* info@enfoldsystems.com */

/* Inspired by:  */
/* http://www.linuxjournal.com/article/6799 */

#include "Python.h"
#include <sched.h>

PyDoc_STRVAR(_affinity__doc__, "Linux Processor Affinity\n");

static PyObject *
get_process_affinity_mask(PyObject *self, PyObject *args)
{
  unsigned long cur_mask;
  unsigned int len = sizeof(cur_mask);
  pid_t pid;

  if (!PyArg_ParseTuple(args, "i:get_process_affinity_mask", &pid))
    return NULL;

  if (sched_getaffinity(pid, len,
                        (cpu_set_t *)&cur_mask) < 0) {
    PyErr_SetFromErrno(PyExc_ValueError);
    return NULL;
  }

  return Py_BuildValue("l", cur_mask);
}

static PyObject *
set_process_affinity_mask(PyObject *self, PyObject *args)
{
  unsigned long new_mask;
  unsigned long cur_mask;
  unsigned int len = sizeof(new_mask);
  pid_t pid;

  if (!PyArg_ParseTuple(args, "il:set_process_affinity_mask", &pid, &new_mask))
    return NULL;

  if (sched_getaffinity(pid, len,
                        (cpu_set_t *)&cur_mask) < 0) {
    PyErr_SetFromErrno(PyExc_ValueError);
    return NULL;
  }

  if (sched_setaffinity(pid, len, (cpu_set_t *)&new_mask)) {
    PyErr_SetFromErrno(PyExc_ValueError);
    return NULL;
  }

  return Py_BuildValue("l", cur_mask);
}

static PyMethodDef methods[] = {
  {"get_process_affinity_mask", get_process_affinity_mask, METH_VARARGS,
    "get_process_affinity_mask(pid) ->\n\
Get the process affinity mask of 'pid'.\n\n\
You can get the affinity mask of any process running\n\
in the system, even if you are not the process owner."},
  {"set_process_affinity_mask", set_process_affinity_mask, METH_VARARGS,
    "set_process_affinity_mask(pid, affinity_mask) ->\n\
Set the process affinity mask of 'pid' to 'affinity_mask'\n\
and return the previous affinity mask.\n\n\
If the PID is set to zero, the PID of the current task is used.\n\n\
Note: you must be 'root' or the owner of 'pid' in\n\
order to be able to call this."},
  {NULL, NULL},
};

PyMODINIT_FUNC
init_affinity(void)
{
  Py_InitModule3("_affinity", methods, _affinity__doc__);
}

