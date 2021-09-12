#include <iostream>
#include "bitwyresdk/rest/public/Market.hpp"
//#include "bitwyresdk/rest/public/Time.hpp"
//#include "bitwyresdk/rest/public/Ticker.hpp"
using namespace Bitwyre::Rest;
auto main() -> int {
    auto r = Bitwyre::Rest::Public::Market::get();

    std::cout << r.markets.size() << "\n";

    for(const auto& m : r.markets) {
        std::cout << m << "\n";
    }
//    Bitwyre::Types::Public::TimeResponse tr = Bitwyre::Rest::Public::Time::get();
//    TickerRequest tickReq{InstrumentT{"btc_usd_spot"}};
//    TickerResponse tr = Bitwyre::Rest::Public::Ticker::get(tickReq);
//    std::cout << tr.tickers.size() << "\n";
//    // use time class
//    std::cout << "getting time"
//    auto tr =  Bitwyre::Rest::Public::Time::get();
//    std::cout << tr.unixtime.count() << "\n";
}

