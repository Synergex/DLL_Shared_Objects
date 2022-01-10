#include "sysdep.h"
#ifdef WIN32
#include <windows.h>
#endif
#include <math.h>
#include  "xcall.h"

#define WROARG 6
#define XCALL_ANSI_C   1

void power(argblk) DESCRIP **argblk;
{
  double	num1,num2, result;
  SEGENTRY	*segp;
  DESCRIP 	*exec_argblk[2];
  DESCRIP	r_descr;
  void *ptr;

  if ((long)argblk[0] != 3)
    dblerror(WROARG);

  num1 = get_xarg_fval(argblk, 2);
  num2 = get_xarg_fval(argblk, 3);

  printf("  C: xval=%f yval=%f\n",num1,num2);

  result = pow(num1, num2);

  printf("  C: result=%f\n",result);
  put_xarg_fval(argblk, 1, result);

  printf("  C: Calling back to DBL with result=%f\n",result);
  exec_argblk[0] = (DESCRIP *)1;
  exec_argblk[1] = get_xarg(argblk, 1, &r_descr);
  ptr = get_seg_ptr("SUB1");
  if (ptr)
    dbl_exec(ptr, exec_argblk);

  printf("  C: Back from DBL call-back, returning to caller with result=%f\n",result);

  return;
}
