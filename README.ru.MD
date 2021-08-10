[English](README.MD) | Русский

# Film processor POC

Прототип процессора для проявки плёнки в герметичных бачках, например Jobo.

![](https://user-images.githubusercontent.com/5612507/128636845-9ac9a695-918d-4a60-a002-c68c25360bce.jpg)

[![](https://user-images.githubusercontent.com/5612507/128865930-81133e4f-d7af-42f1-810c-93fd7418a0d5.jpg)](https://www.youtube.com/watch?v=tWknhwFOHiI)

# Schematic

GNV и 5 вольт не показаны, подключите их к ардуино, тач-сенсору и драйверу шагового двигателя.

Пины ардуино могут быть настроены в [config.h](https://github.com/TheLongRunSmoke/film_processor_poc/blob/main/config.h)

              _________________________________________
             |                                         |
             |                                         |
             |             Arduino Nano v3             |
             |                                         |
             |_________________________________________|
                |    |    |                  | 
              D9|  D7|  D6|                D2|
                |    |    |                  |                  __________
                |    |    |                  |                 |          |
                |    |    |                  |_________Signal__|  TTP223  |
                |    |    |                                    |__________|
                |    |    |                  
                |    |    |              ______________    
                |    |    |__Enable_____|              |             
                |    |                  |    Pololu    |_______*         *
                |    |_______Direction__|     Step     |______*  Stepper  *
                |                       |    Driver    |______*   mottor  *
                |____________Step_______|              |_______*         *
                                        |______________|
                                            |      |
                                            ^ =12v ^

# BOM

У меня уже было большинство деталей, поэтому цены приблизительные. Всё можно купить на Ozon, eBay, Aliexpress или
локально.

| Деталь               |                   | Цена  |
| -------------------|------------------:| --------------:|
| Печатные детали |           |             |
| Ардуино Нано, ревизия 3 | ![](https://user-images.githubusercontent.com/5612507/128858132-71e92090-2f9f-4b29-ade3-ec815a11f163.jpg) |~500р|
| TTP223 датчик касания | ![](https://user-images.githubusercontent.com/5612507/128857991-111f5105-cc19-464f-8e88-bfddf600f398.jpg)|~200р|
| Плата адаптера драйвера шагового двигателя|![](https://user-images.githubusercontent.com/5612507/128858500-2db773fe-8905-4f79-81f1-ca0386f166e2.jpg)|~100р|
| DRV8825 или другой драйвер шагового двигателя |![](https://user-images.githubusercontent.com/5612507/128859694-bd5d91bb-b3a9-4566-b903-f13b6098c67d.jpg)| ~200р|
| Шаговый двигатель размера NEMA14 или NEMA17|![](https://user-images.githubusercontent.com/5612507/128859179-e48553e2-b19d-4a32-babb-782be503d3c4.jpg)|~1000р|
| Ремень GT2 450мм шириной 6мм| ![](https://user-images.githubusercontent.com/5612507/128860022-444b59a1-9ef9-4fea-b7bc-2099fb985f67.png)|~100р|
| 20T или 36T GT2 шкив на вал 8мм X 2 |![](https://user-images.githubusercontent.com/5612507/128860144-1efe8d51-b1a2-4e99-8b37-cb463cbe1452.jpg)|~100р|
| 16T или 20T GT2 шкив на вал 5мм |![](https://user-images.githubusercontent.com/5612507/128860093-ea726977-3771-4594-82cb-d02fed23d798.jpg)|~100р|
| LM2596 или другой понижающий DC-DC |![](https://user-images.githubusercontent.com/5612507/128860843-6c943751-edbc-4933-a12c-892a9f70f053.jpg)|~50р|
| Любой источник 12v 2-3A |       |   ~500р    |  
| Подходящий контейнер |       |       |
| Любой корпус для электроники |       |       |
| 200мм кусок прутка 8мм X 2  |       |       |
| Крепёж M3 M4  |       |       |
|   |    Итого:   |   ~3000р    |

TBU...