
/*|+----------------------------------------------------------------------+|*\
 *|   ProgramName: Hunting world                                           |*
 *|   CreateDate: 16.06.2021                                               |*
 *|   Version: v.1.2 beta                                                  |*
 *|   Author: Ezi                                                          |*
 *|   Language: C++                                                        |*
 *|   Copyright © 2022 Ezi . All Rights Reserved.                          |*
\*|+---------------------------------| HUNTING WORLD |--------------------+|*/

#include "consoleprinter.hpp"
#include "instructionmenu.hpp"
#include "mainmenu.hpp"

int
main()
{
  hw::ConsolePrinter console_printer{std::make_shared<hw::InstructionMenu>()};
  console_printer.display_interface();
}
