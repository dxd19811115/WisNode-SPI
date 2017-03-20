/***************************************************************************//**
 * @file
 * @brief I/O input redirection
 * @author IAR Systems, Energy Micro AS
 * @version 2.4.0
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2012 IAR Systems, http://www.iar.com</b>
 * <b>(C) Copyright 2012 Energy Micro AS, http://www.energymicro.com</b>
 *******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: IAR Systems AB and/or
 * Energy Micro AS have no obligation to support this Software. IAR Systems AB
 * and/or Energy Micro AS are providing the Software "AS IS", with no express
 * or implied warranties of any kind, including, but not limited to, any implied
 * warranties of merchantability or fitness for any particular purpose or
 * warranties against infringement of any proprietary rights of a third party.
 *
 * IAR Systems AB and/or Energy Micro AS will not be liable for any
 * consequential, incidental, or special damages, or any other relief, or for
 * any claim by any third party, arising from your use of this Software.
 *
 * EXPORT LAWS: THIS LICENSE ADDS NO RESTRICTIONS TO THE EXPORT LAWS OF YOUR
 * JURISDICTION. It is licensee's responsibility to comply with any export
 * regulations applicable in licensee's jurisdiction. Under CURRENT (May 2000)
 * U.S. export regulations this software is eligible for export from the U.S.
 * and can be downloaded by or otherwise exported or reexported worldwide
 * EXCEPT to U.S. embargoed destinations which include Cuba, Iraq, Libya, North
 * Korea, Iran, Syria, Sudan, Afghanistan and any other country to which the
 * U.S. has embargoed goods and services.
 *
 ******************************************************************************/
#include <yfuns.h>
#include "bsp.h"

_STD_BEGIN

#pragma module_name = "?__read"

size_t __read(int handle, unsigned char * buffer, size_t size)
{
  int nChars = 0;

  /* Only reads from "standard in", for all other file
   * handles it returns failure. */
  if (handle != _LLIO_STDIN)
  {
    return _LLIO_ERROR;
  }
  
  for (; size > 0; --size)
  {
      int c = USART_ReceiveData(PRINT_USART);
      if (c < 0)
          break;
      
      *buffer++ = c;
      ++nChars;
  }

  return nChars;
}

_STD_END
