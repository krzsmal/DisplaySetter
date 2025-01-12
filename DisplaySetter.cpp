#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

bool readConfig(const string& filename, int& x, int& y) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open the configuration file: " << filename << endl;
        return false;
    }

    string line;
    try {
        while (getline(file, line)) {
            if (line.find("x=") == 0) {
                x = stoi(line.substr(2));
            } else if (line.find("y=") == 0) {
                y = stoi(line.substr(2));
            }
        }
    } catch (const invalid_argument& e) {
        cerr << "Invalid number format in configuration file: " << e.what() << endl;
        return false;
    } catch (const out_of_range& e) {
        cerr << "Number out of range in configuration file: " << e.what() << endl;
        return false;
    }

    file.close();
    return true;
}

int main() {
    if (SetDisplayConfig(0, nullptr, 0, nullptr, SDC_TOPOLOGY_EXTEND | SDC_APPLY) != ERROR_SUCCESS) {
        cerr << "Failed to set display mode to extend!" << endl;
        Sleep(3000);
        return 1;
    }

    DISPLAY_DEVICEW dmInfo{ sizeof(DISPLAY_DEVICEW) };
    DEVMODEW dmMode{ {}, {}, {}, sizeof(DEVMODEW), 0 };

    if (EnumDisplayDevicesW(nullptr, 0, &dmInfo, EDD_GET_DEVICE_INTERFACE_NAME) == 0) {
        cerr << "Failed to enumerate display devices!" << endl;
        Sleep(3000);
        return 1;
    }

    if (EnumDisplaySettingsExW(dmInfo.DeviceName, ENUM_CURRENT_SETTINGS, &dmMode, EDS_RAWMODE) == 0) {
        cerr << "Failed to enumerate display settings!" << endl;
        Sleep(3000);
        return 1;
    }

    int x = 0, y = 0;

    if (!readConfig("config.ini", x, y)) {
        cerr << "Configuration file could not be loaded. Using default settings (x=0, y=0)." << endl;
        Sleep(3000);
    }

    dmMode.dmFields = DM_POSITION;
    dmMode.dmPosition.x = x;
    dmMode.dmPosition.y = y;

    if (ChangeDisplaySettingsExW(dmInfo.DeviceName, &dmMode, nullptr, CDS_GLOBAL | CDS_UPDATEREGISTRY, nullptr) != DISP_CHANGE_SUCCESSFUL) {
        cerr << "Failed to change display settings!" << endl;
        Sleep(3000);
        return 1;
    }

    return 0;
}
