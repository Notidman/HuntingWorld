#include "spritesenemy.hpp"
#include <string_view>


namespace hw
{
  namespace sprites_enemy
  {
    namespace mysterious_forest
    {
      const std::vector<std::string_view> slime
      {
            {"                                  "},
            {"                                  "},
            {"                                  "},
            {"                                  "},
            {"                                  "},
            {"                                  "},
            {"            ,..---..,             "},
            {"        ,-''         '-,          "},
            {"       /    o      o    \\        "},
            {"      (                  )        "},
            {"      (        ^         )        "},
            {"       \\__  ___  ___  __/        "}
      };

      const std::vector<std::string_view> fire_slime
      {
            {"  .  8)  8)     8)     8) 8,    ,    "},
            {"    ,8' ,8'    ,8` .  ,8'  8)        "},
            {"   (8  ,8'    (8      '8,   `8,      "},
            {"  ,8'  8,     `8,   *  '8,    8)   . "},
            {" `8,   `8,      8)      '8)   '8,    "},
            {"   8     `8,   ,8'     ,8'    ,8`    "},
            {"    `       ,..---..,                "},
            {"        ,-''         '-,             "},
            {"       /    o      o    \\           "},
            {"      (                  )           "},
            {"      (         ^        )           "},
            {"       \\__  ___  ___  __/           "}
      };

      const std::vector<std::string_view> rare_big_slime
      {
            {"                                            "},
            {"            ,----------------,              "},
            {"           |                  |             "},
            {"           |                  |             "},
            {"           |                  |             "},
            {"      _____|__________________|_____        "},
            {"       ,```                    ```,         "},
            {"     /`     `--_         _--`      `\\      "},
            {"    (         *           *          )      "},
            {"   (                O                 )     "},
            {"   (                                  )     "},
            {"    \\______  _______  _______  ______/     "},
      };

      const std::vector<std::string_view> big_slime
      {
            {"                                            "},
            {"                                            "},
            {"                                            "},
            {"                                            "},
            {"                                            "},
            {"           ,,...----------...,,             "},
            {"       ,```                    ```,         "},
            {"     /`     `--_         _--`      `\\      "},
            {"    (         *           *          )      "},
            {"   (                O                 )     "},
            {"   (                                  )     "},
            {"    \\______  _______  _______  ______/     "},
        };

      const std::vector<std::string_view> goblin
      {
            {"              ,      ,           "},
            {"             / (.-""-.) \\       "},
            {"         |\\  \\/      \\/  /|   "},
            {"         | \\ / =.  .= \\ / |    "},
            {"         \\( \\   o\\/o   / )/   "},
            {"          \\_, '-/  \\-' ,_/     "},
            {"            /   \\__/   \\       "},
            {"            \\ \\__/\\__/ /      "},
            {"          ___\\ \\|--|/ /___     "},
            {"        /`    \\      /    `\\   "},
            {"       /       '----'       \\   "}
      };

    }

    namespace old_castle
    {
      const std::vector<std::string_view> knight
      {
            {"      _,."                        },
            {"    ,` -.)"                       },
            {"   ( _/-\\-._"                    },
            {"  /,|`--._,-^|            ,"      },
            {"  \\_| |`-._/||          ,'|"     },
            {"    |  `-, / |         /  /"      },
            {"    |     || |        /  /"       },
            {"     `r-._||/   __   /  /"        },
            {" __,-<_     )`-/  `./  /"         },
            {"'  \\   `---'   \\   /  /"        },
            {"    |           |./  /"           },
            {"    /           //  /"            },
            {"\\_/' \\         |/  /"           },
            {" |    |   _,^-'/  /"              },
            {" |    , ``  (\\/  /_"             }
      };

      const std::vector<std::string_view> skeleton
      {
            {"        ___-------___         "},
            {"     ,``        `   ``,      "},
            {"    .` `.        ``    `.     "},
            {"   ;     `        `      ;    "},
            {"   |   ,---,     ,---,   |    "},
            {"   |  |  o \\}  \\{  o  |  |    "},
            {"    |  `---``.^. ``---` |     "},
            {"    |    `  `-`-`    `  |     "},
            {"    \\  `             ` /     "},
            {"     `,`   |||||||    ,`      "},
            {"       |             |        "},
            {"     .` `-.       .-` `.      "},
            {"    `      ```````      `     "}
      };

      const std::vector<std::string_view> ghost
      {
            {"           ____________         "},
            {"       ,```            ```,     "},
            {"     .`       ( * )        `.   "},
            {"    /                 ( * )  \\ "},
            {"  ,|   ( * )   ( * )          |,"},
            {"  |                  ( * )     |"},
            {"  `|                          |`"},
            {"   |         ( * )            | "},
            {"   `|  ( * )           ( * )  | "},
            {"     `,       ,`;      /`;   ;  "},
            {"      ; ,`, ;`   `,  .`  `. ;   "},
            {"       `   ;      ; ;      `;   "},
            {"                   `;           "}
      };
    }

    namespace sacred_mountains
    {
      const std::vector<std::string_view> angel
      {
            {"                 ___                   "},
            {"               /`,--`\\                "},
            {"       .--.   ( ('_') )   .--.         "},
            {"     ,'    \\  (.-`-'(_)  /    `.      "},
            {"    /(_.    `-/       \\-`   ._) \\    "},
            {"   :  '-`(   /'   )   `\\ )`-'    :    "},
            {"   |       ./    (,)    \\.   :   |    "},
            {"   |   . : !\\ ,__[_]__, / ! . !   |   "},
            {"   | ! |-'-| \\__)_=_(__/: |-'-| | |   "},
            {"   | |-'   `-'| \"\"T\"\" | `-'   `-| |"},
            {"   `-'        |   H   |         `-'    "},
            {"              |   H   |                "},
            {"              |   H   |                "}
      };

      const std::vector<std::string_view> stone_golem
      {
            {"          `                             "},
            {"                              `     `   "},
            {"   `    `    /```````````\\ `            "},
            {"  `         |  [*]   [*]  |       `     "},
            {"      ___   \\............./    ___       "},
            {"     | ` | |  |    ``    |` | |   |     "},
            {"     |___|   |  ``  `   |     |___|     "},
            {"     ```  |  `       `    | `|   ``     "},
            {"    (` )    |    `      `  |    (` )    "},
            {"     __`     o0o|ooOo`oo0o       __`    "},
            {"    [__]       o`oo0oo|         [__]    "},
            {"                  ooO       `           "},
            {"          `       O                     "}
      };

      const std::vector<std::string_view> fire_spirit
      {
            {"                   ,           *        "},
            {"    *             (,)                   "},
            {"            *   ,(...),           *     "},
            {"      (       ,( +   + ),     (         "},
            {"       )      (         )      )      * "},
            {"      ( )      )       (      ( )       "},
            {"     ( ( )     (      (      ( ( )      "},
            {"      ( )       )    (        ( )       "},
            {"   *   -         (   )         -        "},
            {"                  ) (    *    .      *  "},
            {"                   (         ;.; ,```,  "},
            {"                    -;;-----`   ` ,`,`  "},
            {"                 *     ````,,___,``,`   "},
            {"       *                    ,`__`,      "}
       };
    }

    namespace cave_of_time
    {
      const std::vector<std::string_view> greate_dragon
      {
        {"                 /           /             "},
        {"                /' .,,,,  ./               "},
        {"               /';'     ,/                 "},
        {"              / /   ,,//,`'`               "},
        {"             ( ,, '_,  ,,,' ``             "},
        {"             |    /@  ,,, ;\" `             "},
        {"            /    .   ,''/' `,``            "},
        {"           /   .     ./, `,, ` ;           "},
        {"        ,./  .   ,-,',` ,,/''\\,'           "},
        {"       |   /; ./,,'`,,'' |   |             "},
        {"       |     /   ','    /    |             "},
        {"        \\___/'   '     |     |             "},
        {"          `,,'  |      /     `\\            "},
        {"               /      |        ~\\          "}
      };
    }
  }

}
