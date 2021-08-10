English | [Русский](README.ru.MD)

# Film processor POC

POC prototype of film processor for developing drums like Jobo or any other watertight.

![](https://user-images.githubusercontent.com/5612507/128636845-9ac9a695-918d-4a60-a002-c68c25360bce.jpg)

# Schematic

GNV and 5v lines not shown, attach it Arduino, touch sensor and stepper driver.

Arduino ports can be remapped in [config.h](https://github.com/TheLongRunSmoke/film_processor_poc/blob/main/config.h)

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

I already had most of the parts, so prices approximate.

| Part               |                   | Price  |
| -------------------|------------------:| --------------:|
| Printed parts |           |             |
| Arduino Nano rev 3 | ![](https://user-images.githubusercontent.com/5612507/128858132-71e92090-2f9f-4b29-ade3-ec815a11f163.jpg) |~6$|
| TTP223 touch sensor  | ![](https://user-images.githubusercontent.com/5612507/128857991-111f5105-cc19-464f-8e88-bfddf600f398.jpg)|~1$|
| Stepper driver interface board|![](https://user-images.githubusercontent.com/5612507/128858500-2db773fe-8905-4f79-81f1-ca0386f166e2.jpg)|~5$|
| DRV8825 or any other compatible driver |![](https://user-images.githubusercontent.com/5612507/128859694-bd5d91bb-b3a9-4566-b903-f13b6098c67d.jpg)| ~5$|
| NEMA17 or NEMA14 stepper motor |![](https://user-images.githubusercontent.com/5612507/128859179-e48553e2-b19d-4a32-babb-782be503d3c4.jpg)|~15$|
| GT2 450mm 6mm wide close timing belt | ![](https://user-images.githubusercontent.com/5612507/128860022-444b59a1-9ef9-4fea-b7bc-2099fb985f67.png)|~2$|
| 20T or 36T 8mm bore GT2 pulley X 2 |![](https://user-images.githubusercontent.com/5612507/128860144-1efe8d51-b1a2-4e99-8b37-cb463cbe1452.jpg)|~5$|
| 16T or 20T 5mm bore GT2 pulley |![](https://user-images.githubusercontent.com/5612507/128860093-ea726977-3771-4594-82cb-d02fed23d798.jpg)|~2$|
| LM2596 or any 5v step-down converter |![](https://user-images.githubusercontent.com/5612507/128860843-6c943751-edbc-4933-a12c-892a9f70f053.jpg)|~3$|
| Any 12v 2-3A power source  |       |   ~10$    |  
| Any large enough container  |       |       |
| Any enclosure for electronic parts  |       |       |
| 200mm piece of 8mm stock X 2  |       |       |
| Assorted M3 and M4 hardware  |       |       |
|   |    Total:   |   ~60$    |

TBU...