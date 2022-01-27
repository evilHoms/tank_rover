#include <Arduino.h>

struct Stick {
    short x;
    short y;
    bool btn;
};

struct Data {
    Stick stick1;
    Stick stick2;
    bool btns[4];
    byte pot1;
};

class DataStorage {
    public:
        DataStorage() {
            resetData();
        }

        void mapByteData(byte byteData[8]) {
            byte btns[] = {1, 2, 4, 8, 16, 32};
            byte btnValue = byteData[0];

            resetData();

            if (btnValue >= btns[5]) {
                btnValue -= btns[5];
                _data.stick2.btn = true;
            }
            if (btnValue >= btns[4]) {
                btnValue -= btns[4];
                _data.stick1.btn = true;
            }
            if (btnValue >= btns[3]) {
                btnValue -= btns[3];
                _data.btns[3] = true;
            }
            if (btnValue >= btns[2]) {
                btnValue -= btns[2];
                _data.btns[2] = true;
            }
            if (btnValue >= btns[1]) {
                btnValue -= btns[1];
                _data.btns[1] = true;
            }
            if (btnValue >= btns[0]) {
                btnValue -= btns[0];
                _data.btns[0] = true;
            }

            _data.pot1 = byteData[1];
            _data.stick1.x = byteData[2];
            _data.stick1.y = byteData[3];
            _data.stick2.x = byteData[4];
            _data.stick2.y = byteData[5];
        }

        Data getData() {
            return _data;
        }

    private:
        Data _data;

        void resetData() {
            _data.stick1.x = 0;
            _data.stick1.y = 0;
            _data.stick1.btn = false;
            _data.stick2.x = 0;
            _data.stick2.y = 0;
            _data.stick2.btn = false;
            for (byte i = 0; i < sizeof(_data.btns); i += 1) {
                _data.btns[i] = 0;
            }
            _data.pot1 = 0;
        }
};
