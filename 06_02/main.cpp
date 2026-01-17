#include <stdio.h>
#include <thread>
#include <mutex>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

std::vector<std::vector<int>> mapData;
std::mutex mtx;
bool loaded = false;

void LoadCSV(const char* filename) {
    std::ifstream file(filename);
    std::string line;

    std::vector<std::vector<int>> temp;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<int> row;

        while (std::getline(ss, value, ',')) {
            row.push_back(std::stoi(value));
        }
        temp.push_back(row);
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        mapData = temp;
        loaded = true;
    }
}

int main() {
    // バックグラウンド
    std::thread loader(LoadCSV, "map.csv");

    // メインループ
    while (true) {
        std::lock_guard<std::mutex> lock(mtx);
        if (loaded) {
            break;
        }
    }

    // マップ表示（マップチップ）
    for (auto& row : mapData) {
        for (int v : row) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    loader.join();
    return 0;
}