#include <iostream>
#include "bitwyresdk/rest/public/Market.hpp"
#include "bitwyresdk/rest/public/Time.hpp"
#include "bitwyresdk/rest/public/Ticker.hpp"
using namespace Bitwyre::Rest;
auto main() -> int {
    auto r = Bitwyre::Rest::Public::Market::get();
    std::cout << "getting market size\n";
    std::cout << r.markets.size() << "\n";

    for(const auto& m : r.markets) {
        std::cout << m << "\n";
    }
    TickerRequest tickReq{InstrumentT{"btc_usd_spot"}};
    std::cout << "getting ticker size\n";
    TickerResponse ticker_r = Bitwyre::Rest::Public::Ticker::get(tickReq);
    std::cout << ticker_r.tickers.size() << "\n";
    // use time class
    std::cout << "getting time\n";
    auto tr =  Bitwyre::Rest::Public::Time::get();
    std::cout << tr.unixtime.count() << "\n";

    std::cout << "getting ticker size asynchronously\n";
    AsyncTickerResponse atr = Bitwyre::Rest::Public::Ticker::getAsync(tickReq);
    std::cout << atr.get().tickers.size()<< "\n";

    std::cout << "getting time callback asynchronously\n";
    auto func = [](const TimeResponse& res){ std::cout << res.unixtime.count() << "\n"; };
    Bitwyre::Rest::Public::Time::getAsync(func);
}

