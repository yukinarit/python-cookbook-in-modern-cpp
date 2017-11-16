/// example.cpp
///
/// Example of implementing an inlined-callback function

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include <date/date.h>
#include <fmt/format.h>

using namespace date::literals;

date::year_month_day get_previous_byday(const std::string& name, date::year_month_day&& start) {
    static const std::vector<std::string> weekdays = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                                                      "Friday", "Saturday", "Sunday"};

    unsigned int day_num = unsigned(date::year_month_weekday{start}.weekday()) - 1;
    auto it = std::find(weekdays.begin(), weekdays.end(), name);
    auto day_num_target = std::distance(weekdays.begin(), it);
    auto days_ago = (7 + day_num - day_num_target) % 7;
    // fmt::print("{} {} {}\n", day_num, day_num_target, days_ago);

    if (days_ago == 0)
        days_ago = 7;
    return date::sys_days{start} - date::days{days_ago};
}

int main() {
    std::cout << "previous date=" << get_previous_byday("Monday", 2017_y / nov / 11) << std::endl;
    std::cout << "previous date=" << get_previous_byday("Friday", 2017_y / nov / 11) << std::endl;
    std::cout << "previous date=" << get_previous_byday("Saturday", 2017_y / nov / 11) << std::endl;
    std::cout << "previous date=" << get_previous_byday("Sunday", 2017_y / nov / 11) << std::endl;

    return 0;
}
