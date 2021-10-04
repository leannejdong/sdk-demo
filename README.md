## Build instruction

This is a simple demo of our [sdk library](https://github.com/bitwyre/sdk)

You may need a key for running `conan install ..`. Please contact me via 
[email](leanne@bitwyre.com) or twitter/linkedin.

```
cd sdk-demo
mkdir build
cd build
conan install .. --build=missing
cmake ..
make
```

More examples (Just paste to your `main.cpp`)

# Example of usage Public API

- Getting the Server time https://docs.bitwyre.id/#server-time

```c++
#include "bitwyresdk/rest/public/Time.hpp"

auto main() -> int {
    TimeResponse tr = Bitwyre::Rest::Public::Time::get();
    std::cout << tr.unixtime.count() << "\n";
}
```

```c++
#include "bitwyresdk/rest/public/Time.hpp"
auto main() -> int {
    AsyncTimeResponse atr = Bitwyre::Rest::Public::Time::getAsync();
    std::cout << atr.get().unixtime.count() << "\n";
}
```

```c++
#include "bitwyresdk/rest/public/Time.hpp"
auto main() -> int {
    auto func = [](const TimeResponse& res){ std::cout << res.unixtime.count() << "\n" };
    Bitwyre::Rest::Public::Time::getAsync(func);
}
```

- Getting the list of tickers https://docs.bitwyre.id/#ticker

```cpp
#include "rest/public/Ticker.hpp"
auto main() -> int {
    TickerRequest tickReq{InstrumentT{"btc_usd_spot"}};
    AsyncTickerResponse atr = Ticker::getAsync(tickReq);
    std::cout << atr.get().tickers.size()<< "\n";
    }
```
<!---
```c++
#include "rest/public/Ticker.hpp"

auto main() -> int {
    // TickerRequest tickReq{InstrumentT{"btc_usd_spot"}};
    auto func = [](const TickerResponse& res){ std::cout << res{InstrumentT{"btc_usd_spot"}}};
    Ticker::getAsync(func);
}
```
-->
# Example of usage Private API

All private APIs are authenticated following https://docs.bitwyre.id/#authentication.

For running these endpoints, follow the documentation link above and retrieve your **API-KEY** and **API-SECRET**, they will be
required in order to sign every request.

Once you've retrieved the API credentials, set them as environment variable.

```shell
export BITWYRE_API_SECRET=mysecret
export BITWYRE_API_KEY=mypublic
```

At this point we are all set to run the examples.

- Opening a new order https://docs.bitwyre.id/#ticker

```c++
#include "rest/public/NewOrder.hpp"

auto main() -> int {
    NewOrderRequest request{
      InstrumentT{"btc_usd_spot"},
      SideT{1},
      OrdType{1},
      PriceT{100},
      QtyT{100},
  };
    
    auto result = NewOrder::post(request);
    
    std::cout << result.instrument << "\n";
}
```
