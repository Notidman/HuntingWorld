#pragma once
#include "iusermenu.hpp"
#include "numsreader.hpp"
#include <tuple>
#include <vector>
#include <string>

namespace hw
{
  class MainMenu final : public IUserMenu
  {
  public:
    MainMenu()  noexcept;

    virtual std::string get_title_name() const override;
    virtual std::string get_body_choices() const override;

    std::vector<std::tuple<short, std::string>> choices_;
  };
} // namespace hw