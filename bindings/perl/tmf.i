%module tmf
%{
/* Includes the header in the wrapper code */
#include "tmf.h"
%}

/* Parse the header file to generate wrappers */
%include "tmf.h"

